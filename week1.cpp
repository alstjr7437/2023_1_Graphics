#include <windows.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 500);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("OpenGL Drawing Example");

    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;

}
