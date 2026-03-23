#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat flow1 = 0.0;
static GLfloat flow1_2 = 0.0;
static GLfloat flow2 = 0.0;
static GLfloat flow3 = 0.0;
static GLfloat flow4 = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(1.0, 0.40, 0.0);
	glRectf(-45.0, -40.0, -25.0, 40.0);
	glColor3f(0.0, 0.50, 1.0);
	glRectf(-45.0, -40.0, -25.0, 40.0 - flow1);

	glColor3f(1.0, 0.40, 0.0);
	glRectf(25.0, -40.0, 45.0, 40.0);
	glColor3f(0.0, 0.50, 1.0);
	glRectf(25.0, -40.0, 45.0, -40.0 + flow4);

	glColor3f(1.0, 0.40, 0.0);
	glRectf(-25.0, -35.0, 25.0, -25.0);
	glColor3f(0.0, 0.50, 1.0);
	glRectf(-25.0 + flow3, -35.0, -25.0 + flow2, -25.0 - flow1_2);

	glPopMatrix();
	glutSwapBuffers();

	glFlush();
}

void flowDisplay(void)
{
	flow1 = flow1 + 0.0007;
	flow2 = flow2 + 0.01;
	if (flow1 > 75.0)
	{
		flow1 = 75.0;
	}
	if (flow2 > 50.0)
	{
		flow2 = 50.0;
	}
	if (flow1 == 75.0)
	{
		flow3 = flow3 + 0.01;
		if (flow3 > 50.0)
		{
			flow3 = 50.0;
		}
	}
	if (flow2 > 45.0)
	{
		flow4 = flow4 + 0.0007;
		if (flow4 > 75.0)
		{
			flow4 = 75.0;
		}
	}
	if (flow1 > 65.0)
	{
		flow1_2 = flow1_2 + 0.0007;
		if (flow1_2 > 10.0)
		{
			flow1_2 = 10.0;
		}
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1500, 600);
	glutInitWindowPosition(20, 100);
	glutCreateWindow("exe");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(flowDisplay);
	glutMainLoop();
	return 0;
}