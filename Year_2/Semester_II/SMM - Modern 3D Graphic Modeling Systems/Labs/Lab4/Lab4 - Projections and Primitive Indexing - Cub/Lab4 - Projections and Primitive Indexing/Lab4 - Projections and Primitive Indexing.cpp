// Lab4 - Index buffer.cpp : Defines the entry point for the console application.
//
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <stdio.h>
#include <math.h> 
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h> // nu trebuie uitat freeglut.h
#include <GLM.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// include the freeglut Library file
#pragma comment (lib, "freeglut.lib")
#pragma comment (lib, "glew32.lib")

GLuint VaoId, VboId, IboId, ColorBufferId, VertexShaderId, FragmentShaderId, ProgramId;
GLuint WorldMatrixLocation, ProjMatrixLocation;

bool g_WireFrame = false;

glm::mat4 g_projTransf = glm::mat4(1);
float FOV = 45.f;
const glm::mat4 GetProjectionMatrix(bool bOrthoProj)
{
	glm::mat4 projTransf = glm::mat4(1);
	float fZNear = 0.1f;
	float fZFar = 500.f;
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	if (bOrthoProj)
	{
		float scaleFactor = 2000.f;
		projTransf = glm::ortho(-width / scaleFactor, width / scaleFactor,
			-height / scaleFactor, height / scaleFactor, -fZFar, fZFar);
	}
	else
	{
		float fWindowAspect = width / (float)height;
		projTransf = glm::perspective(glm::radians(FOV), fWindowAspect, fZNear, fZFar);
	}
	return projTransf;
}

// Shader-ul de varfuri / Vertex shader (este privit ca un sir de caractere)
const GLchar* VertexShader =
{
	"#version 400\n"\
	"layout(location=0) in vec4 in_Position;\n"\
	"layout(location=1) in vec4 in_Color;\n"\
	"out vec4 ex_Color;\n"\
	"uniform mat4 WorldMatrix;\n"\
	"uniform mat4 ProjMatrix;\n"\
	"void main()\n"\
	"{\n"\
	"  gl_Position = ProjMatrix * WorldMatrix * in_Position;\n"\
	"  ex_Color = in_Color;\n"\
	"}\n"
};
// Shader-ul de fragment / Fragment shader (este privit ca un sir de caractere)
const GLchar* FragmentShader =
{
	"#version 400\n"\
	"in vec4 ex_Color;\n"\
	"out vec4 out_Color;\n"\
	"void main()\n"\
	"{\n"\
	"  out_Color = ex_Color;\n"\
	"}\n"
};
void CreateVBO()
{
	// indexurile cubului
	unsigned int Indices[] = {
		0, 1, 2,
		0, 2, 3,
		1, 5, 6,
		1, 6, 2,
		5, 4, 7,
		5, 7, 6,
		4, 0, 3,
		4, 3, 7,
		0, 1, 5,
		0, 5, 4,
		3, 2, 6,
		3, 6, 7
	};

	// varfurile cubului
	GLfloat Vertices[] = {
		-0.4f, -0.4f, 0.4f, 1.0f,
		0.4f, -0.4f, 0.4f, 1.0f,
		0.4f, 0.4f, 0.4f, 1.0f,
		-0.4f, 0.4f, 0.4f, 1.0f,
		-0.4f, -0.4f, -0.4f, 1.0f,
		0.4f, -0.4f, -0.4f, 1.0f,
		0.4f, 0.4f, -0.4f, 1.0f,
		-0.4f, 0.4f, -0.4f, 1.0f
	};

	// culorile, ca atribute ale varfurilor
	GLfloat Colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f
	};

	// se creeaza un buffer nou
	glGenBuffers(1, &VboId);
	// este setat ca buffer curent
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	// punctele sunt "copiate" in bufferul curent
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// se creeaza / se leaga un VAO (Vertex Array Object) - util cand se utilizeaza mai multe VBO
	glGenVertexArrays(1, &VaoId);
	glBindVertexArray(VaoId);

	// se activeaza lucrul cu atribute; atributul 0 = pozitie
	glEnableVertexAttribArray(0);
	// 
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// un nou buffer, pentru culoare
	glGenBuffers(1, &ColorBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	// atributul 1 =  culoare
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// un nou buffer pentru indexuri
	glGenBuffers(1, &IboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void DestroyVBO()
{
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ColorBufferId);
	glDeleteBuffers(1, &VboId);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);
}
void CreateShaders()
{
	VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShaderId, 1, &VertexShader, NULL);
	glCompileShader(VertexShaderId);

	FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShaderId, 1, &FragmentShader, NULL);
	glCompileShader(FragmentShaderId);

	ProgramId = glCreateProgram();
	glAttachShader(ProgramId, VertexShaderId);
	glAttachShader(ProgramId, FragmentShaderId);
	glLinkProgram(ProgramId);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	glGetProgramiv(ProgramId, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		glGetProgramInfoLog(ProgramId, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		exit(1);
	}

	glValidateProgram(ProgramId);
	glGetProgramiv(ProgramId, GL_VALIDATE_STATUS, &Success);
	if (!Success) {
		glGetProgramInfoLog(ProgramId, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
		exit(1);
	}

	glUseProgram(ProgramId);

	WorldMatrixLocation = glGetUniformLocation(ProgramId, "WorldMatrix");
	ProjMatrixLocation = glGetUniformLocation(ProgramId, "ProjMatrix");

}
void DestroyShaders()
{
	glUseProgram(0);

	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);

	glDeleteShader(FragmentShaderId);
	glDeleteShader(VertexShaderId);

	glDeleteProgram(ProgramId);
}
void Initialize()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // culoarea de fond a ecranului
	glEnable(GL_CULL_FACE);
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	CreateVBO();
	CreateShaders();

	g_projTransf = GetProjectionMatrix(true);
}
void RenderFunction()
{
	static float triangleOffset = 0.0f;
	const float triangleIncrement = 0.001f;

	triangleOffset += triangleIncrement;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 worldTransf = glm::translate(glm::mat4(1.0), glm::vec3(0.f, 0.0f, -1.f));
	worldTransf = glm::scale(worldTransf, glm::vec3(0.1f, 0.1f, 0.1f));
	worldTransf = glm::rotate(worldTransf, triangleOffset, glm::vec3(0, 1, 0));

	glUniformMatrix4fv(WorldMatrixLocation, 1, GL_FALSE, glm::value_ptr(worldTransf));
	glUniformMatrix4fv(ProjMatrixLocation, 1, GL_FALSE, glm::value_ptr(g_projTransf));

	if (!g_WireFrame)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_DEPTH_TEST);
	}

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VboId);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IboId);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void Keyboard(unsigned char Key, int x, int y)
{
	if (tolower(Key) == 'w' && g_WireFrame == false) {
		g_WireFrame = true;
	}
	if (tolower(Key) == 's' && g_WireFrame == true) {
		g_WireFrame = false;
	}
	if (tolower(Key) == 'o') {
		g_projTransf = GetProjectionMatrix(true);
	}
	if (tolower(Key) == 'p') {
		g_projTransf = GetProjectionMatrix(false);
	}
	if (tolower(Key) == 'i') {
		FOV -= 5;
		if (FOV == 15)
			FOV += 5;
		g_projTransf = GetProjectionMatrix(false);
	}
	if (tolower(Key) == 'd') {
		FOV += 5;
		if (FOV == 180)
			FOV -= 5;
		g_projTransf = GetProjectionMatrix(false);
	}
}

void Cleanup()
{
	DestroyShaders();
	DestroyVBO();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100); // pozitia initiala a ferestrei
	glutInitWindowSize(1000, 700); //dimensiunile ferestrei
	glutCreateWindow("Lab 4"); // titlul ferestrei
	// nu uitati de initializare glew; 
	// trebuie initializat inainte de a a initializa desenarea
	glewInit();
	Initialize();
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(RenderFunction);
	glutKeyboardFunc(Keyboard);

	glutCloseFunc(Cleanup);
	glutMainLoop();
}