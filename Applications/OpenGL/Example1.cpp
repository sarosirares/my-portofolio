#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
	/* Şterge toţi pixelii */
	glClear(GL_COLOR_BUFFER_BIT);
	/* draws a rectangle with corners at points
	* (0.25, 0.25, 0.0) şi (0.75, 0.75, 0.0)
	*/
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glColor3f(0.60, 0.75, 0.30);
	glBegin(GL_POLYGON);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.100, 0.75, 0.0);
	glVertex3f(0.75, 0.100, 0.0);
	glEnd();

	/* forces processing of drawing routines*/
	glFlush();
}
void init(void)
{
	/* Select screen erase color */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* Initializes scene viewpoint */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 2.0, 0.0, 2.0, -1.0, 1.0);
}
/*
* Declare the initial size of the window and display mode
* (single buffer and RGBA). Open the window with "hello" in the bar
* title. Calls startup routines. Records functions
* Display callback. Enter the main loop and process
* possible events.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sarosi Rares");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
