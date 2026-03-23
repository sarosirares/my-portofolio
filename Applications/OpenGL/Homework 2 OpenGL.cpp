#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat flow1 = 0.0;   //parameter that changes the liquid in the tank where it starts
static GLfloat flow2 = 0.0;   //parameter that helps the liquid to pass through the pipe
static GLfloat flow3 = 0.0;   //parameter that changes the height of the liquid from the pipe
static GLfloat flow4 = 0.0;   //parameter that changes the height of the liquid in the final tank
static GLint ok = 0;		  //variable that shows the option of the user (0 - initial state, 1 - left tank animation, 2 - right tank animation)
static GLboolean click = true;//boolean variable (true - left and right click can change the animation, false - left and right click are blocked)

void init(void)				  //background
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)			  //function that creates the entities depending on the user's option
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	
	glColor3f(1.0, 0.40, 0.0);
	glRectf(-45.0, -40.0, -25.0, 40.0);
	glColor3f(1.0, 0.40, 0.0);
	glRectf(25.0, -40.0, 45.0, 40.0);
	glColor3f(1.0, 0.40, 0.0);
	glRectf(-25.0, -35.0, 25.0, -25.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-5.0, 10.0, 5.0, 30.0);

	if (ok == 1)			  //it means that the animation starts from the left tank
	{
		glColor3f(0.0, 0.50, 1.0);
		glRectf(-45.0, -40.0, -25.0, 40.0 - flow1);

		glColor3f(0.0, 0.50, 1.0);
		glRectf(25.0, -40.0, 45.0, -40.0 + flow4);

		glColor3f(0.0, 0.50, 1.0);
		glRectf(-25.0, -35.0, -25.0 + flow2, -25.0 - flow3);

		if (flow4 == 75.0)	  //when the animation is finished, the led turns green
		{
			glColor3f(0.0, 1.0, 0.0);
			glRectf(-5.0, 10.0, 5.0, 30.0);
		}
	}

	if (ok == 2)			  //it means that the animation starts from the right tank
	{
		glColor3f(0.0, 0.50, 1.0);
		glRectf(-45.0, -40.0, -25.0, -40.0 + flow4);

		glColor3f(0.0, 0.50, 1.0);
		glRectf(25.0, -40.0, 45.0, 40.0 - flow1);

		glColor3f(0.0, 0.50, 1.0);
		glRectf(25.0 - flow2, -35.0, 25.0, -25.0 - flow3);

		if (flow4 == 75.0)	  //when the animation is finished, the led turns red
		{
			glColor3f(1.0, 0.0, 0.0);
			glRectf(-5.0, 10.0, 5.0, 30.0);
		}
	}

	glPopMatrix();
	glutSwapBuffers();

	glFlush();
}

void flowDisplay(void)		  //function that changes the value for the "flow" variables
{
		if (ok > 0)			  //the animation
		{
			click = false;	  //during the animation, left and right clicks are blocked
			flow1 = flow1 + 0.005;
			flow2 = flow2 + 0.02;
			if (flow1 > 75.0)
			{
				flow1 = 75.0;
			}
			if (flow2 > 50.0)
			{
				flow2 = 50.0;
			}
			if (flow2 > 45.0)
			{
				flow4 = flow4 + 0.0059;
				if (flow4 > 75.0)
				{
					flow4 = 75.0;
				}
			}
			if (flow1 > 65.0)
			{
				flow3 = flow3 + 0.005;
				if (flow3 > 10.0)
				{
					flow3 = 10.0;
				}
			}
			if (flow4 == 75.0)
				click = true;
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

void mouse(int button, int state, int x, int y)	 //function that changes the variables influenced by mouse
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN && click == true) //left click for the first option
		{
			flow1 = 0.0;
			flow2 = 0.0;
			flow3 = 0.0;
			flow4 = 0.0;
			ok = 1;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN && click == true) //right click for the second option
		{
			flow1 = 0.0;
			flow2 = 0.0;
			flow3 = 0.0;
			flow4 = 0.0;
			ok = 2;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)					 //middle click to reset the animation
		{
			flow1 = 0.0;
			flow2 = 0.0;
			flow3 = 0.0;
			flow4 = 0.0;
			ok = 0;
			click = true;
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1500, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sarosi Rares");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(flowDisplay);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}