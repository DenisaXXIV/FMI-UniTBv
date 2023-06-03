#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#pragma comment(lib,"freeglut.lib")

void InitGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 700);
}

void Initialize(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //culoarea neagru de fond a ecranului
}

void RenderFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(20.0);
	glBegin(GL_POINTS);

	//primul varf
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex4f(-0.8f, -0.8f, -0.0f, 1.0f);

	//al doilea varf
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex4f(0.0f, 0.8f, -0.0f, 1.0f);

	//al treilea varf
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex4f(0.8f, -0.8f, -0.0f, 1.0f);

	glEnd();
	glFlush();
}

//Se apeleaza in functia Main metodele de initializare, se specifica callback-ul
//de randare si se porneste bucla principala

int main(int argc, char* argv[])
{
	InitGLUT(argc, argv);
	glutCreateWindow("Primul Triunghi - OpenGL <<vechi>>"); //titlul ferestrei
	std::cout << "OpenGL version supported by this platform:"
		<< glGetString(GL_VERSION) << std::endl;

	std::cout << "GLSL version supported by this platform:"
		<< glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	Initialize();
	glutDisplayFunc(RenderFunction);
	glutMainLoop();
	return 0;
}