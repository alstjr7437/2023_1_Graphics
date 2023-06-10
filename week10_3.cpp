#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include <math.h>

#define Pi 3.141592

void MyDisplay() {
    GLushort pattern = 0xFF00;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glPointSize(10);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, pattern);
    glBegin(GL_LINES);      // LINE, LINE_STRIP, LINE_LOOP, TRANGLES, GL_TRIANGLE_STRIP, GL_POLYGON, GL_QUAD_STRIP
        glVertex3f(0.7, 0.2, 0.0);
        glVertex3f(0.2, 0.8, 0.0);
        glVertex3f(-0.3, 0.7, 0.0);
        glVertex3f(-0.7, 0.2, 0.0);
        glVertex3f(-0.6, -0.2, 0.0);
        glVertex3f(-0.25, -0.8, 0.0);
        glVertex3f(0.2, -0.7, 0.0);
        glVertex3f(0.6, -0.2, 0.0);
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
