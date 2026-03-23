#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat left = 0.0;
static GLfloat flow1_2 = 0.0;
static GLfloat middle1 = 0.0;
static GLfloat middle2 = 0.0;
static GLfloat right = 0.0;

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
	glRectf(-45.0, -40.0, -25.0, 40.0 - left);

	glColor3f(1.0, 0.40, 0.0);
	glRectf(25.0, -40.0, 45.0, 40.0);
	glColor3f(0.0, 0.50, 1.0);
	glRectf(25.0, -40.0, 45.0, -40.0 + right);

	glColor3f(1.0, 0.40, 0.0);
	glRectf(-25.0, -35.0, 25.0, -25.0);
	glColor3f(0.0, 0.50, 1.0);
	glRectf(-25.0 + middle2, -35.0, -25.0 + middle1, -25.0 - flow1_2);

	glPopMatrix();
	glutSwapBuffers();

	glFlush();
}

void flowDisplay(void)
{
		while (left <= 75.0)
		{
			left += 0.005;
			//if (left == 75.0)
				//while (middle2 <= 50.0)
					//middle2 += 0.02;
		}
		while (middle1 <= 70.0)
		{
			middle1 += 0.02;
			//if (middle1 >= 70.0)
				//while (right <= 75.0)
					//right += 0.006;
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1500, 600);
	glutInitWindowPosition(20, 100);
	glutCreateWindow("Sarosi Rares");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(flowDisplay);
	glutMainLoop();
	return 0;
}