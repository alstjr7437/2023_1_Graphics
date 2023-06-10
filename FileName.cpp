#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include <math.h>

#define Pi 3.141592

void MyDisplay() {
	double radius=0.7, rad;
	GLushort  pattern = 0x00FF;
	int scalefactor = 1;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

/*	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(10);
	glEnable(GL_LINE_STIPPLE);
	for (float ang = -0.8; ang < 1.0; ang += 0.4) {
		// rad = (double)ang / 180.0 * 3.141592;
		// glVertex3f(radius * cos(rad), radius * sin(rad), 0);
		glLineStipple(scalefactor, pattern);
		glBegin(GL_LINES);
			glVertex3f(-1.0, ang, 0.0);
			glVertex3f(1.0, ang, 0.0);
		glEnd();
		scalefactor *= 2;
	}
*/
	glShadeModel(GL_FLAT); //  (GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);  glVertex3f(-0.5, -0.7, 0);
	glColor3f(0, 1, 0);   glVertex3f(0, 0.8, 0);
	glColor3f(0, 0, 1);  glVertex3f(0.8, -0.2, 0);
	glEnd();
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("opengl rasterization test");

	glClearColor(0.5, 0.5, 0.5, 0.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}