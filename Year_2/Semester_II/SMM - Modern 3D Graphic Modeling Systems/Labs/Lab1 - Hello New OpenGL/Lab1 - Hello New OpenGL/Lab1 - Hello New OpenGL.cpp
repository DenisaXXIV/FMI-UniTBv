// Se includ headerele necesare pentru cititrea shader-elor
#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#pragma comment(lib,"freeglut.lib")
#pragma comment(lib,"glew32.lib")

// Se declara id-urile de tip int pentru Vertex Array Object, Vertex Buffer Object, Colored buffer, Vertex Shader, Fragment Shader si program
GLuint VaoId, VboId, ColorBufferId, VertexShaderId, FragmentShaderId, ProgramId;
// Se declara shader-ul de varfuri ca un sir de caractere
const GLchar* VertexShader =
{
"#version 400\n"\
"layout(location=0) in vec4 in_Position;\n"\
"layout(location=1) in vec4 in_Color;\n"\
"out vec4 ex_Color;\n"\
"void main(void)\n"\
"{\n"\
" gl_Position = in_Position;\n"\
" ex Color in Color; \n"\
"}\n"
};

// Se declara shader-ul de fragment ca un sir de caractere
const GLchar* FragmentShader =
{
"#version 400\n"\
"in vec4 ex_Color;\n"\
"out vec4 out_Color;\n"\
"void main(void)\n"\
"{\n"\
" out_Color = ex_Color;\n"\
"}\n"
};

// Se creaza bufer-ul de vertex-uri
void CreateVBO(void)
{
	// varfurile
	GLfloat Vertices[] = {
	-0.8f, -0.8f, 0.0f, 1.0f,
	0.0f, 0.8f, 0.0f, 1.0f,
	0.8f, -0.8f, 0.0f, 1.0f
	};

	// culorile, ca atribute ale varfurilor
	GLfloat Colors[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// un nou buffer, pentru culoare 
	glGenBuffers(1, &ColorBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);

	// atributul 1 = culoare
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
}

// Se distruge bufer-ul de vertex-uri
void DestroyVBO(void)
{
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &ColorBufferId);
	glDeleteBuffers(1, &VboId);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VaoId);
}

// Se creaza shader-ele 
void CreateShaders(void)
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
	glUseProgram(ProgramId);
}

// Se distrug shader-ele 
void DestroyShaders(void)
{
	glUseProgram(0);
	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);
	glDeleteShader(FragmentShaderId);
	glDeleteShader(VertexShaderId);
	glDeleteProgram(ProgramId);
}

void Initialize(void)
{
	// Se specifica culoarea background-ului
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // culoarea de fond a ecranului
	CreateVBO();
	CreateShaders();
}

// Se scrie functia care randeaza varfurile
void RenderFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(20.0);
	glDrawArrays(GL_POINTS, 0, 3);
	glFlush();
}
// Se scrie functia de cleanup
void Cleanup(void)
{
	DestroyShaders();
	DestroyVBO();
}

// Se scrie functia principala
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100); // pozitia initiala a ferestrei 
	glutInitWindowSize(1000, 700); //dimensiunile ferestrei
	glutCreateWindow("Primul triunghi - OpenGL <<nou>>"); // titlul ferestrei
	// nu uitati de initializare glew;
	// trebuie initializat inainte de a a initializa desenarea
	glewInit();
	Initialize();
	glutDisplayFunc(RenderFunction);
	glutCloseFunc(Cleanup);
	glutMainLoop();
}
