#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include <math.h>

#define Pi 3.141592

void MyDisplay() {
    GLushort pattern = 0xFFF5; //0xFF00 0xFFF5 0xFF55
    double rad = 0.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glPointSize(10);
    //glEnable(GL_LINE_STIPPLE);
    //glLineStipple(1, pattern);
    glShadeModel(GL_FLAT); //GL_SMOOTH (색깔 그라데이션 나옴 이거 그리고 이거 할거면 이 명령어 없어도 나옴) GL_FLAT (색깔 하나만 나옴)
    glBegin(GL_LINE_LOOP);
    for (float ang = 0.0; ang < 360.0; ang += 10.0) {
        rad = ang / 180.0 * Pi;
        glVertex3f(0.7 * cos(rad), 0.7 * sin(rad), 0);
    }
    glEnd();
    glFlush();
    /*
    glBegin(GL_POLYGON);      // LINE, LINE_STRIP, LINE_LOOP, TRANGLES, GL_TRIANGLE_STRIP, GL_POLYGON, GL_QUAD_STRIP
    glColor3f(1, 0, 0); glVertex3f(0.7, -0.6, 0.0);
    glColor3f(0, 1, 0); glVertex3f(0.1, 0.7, 0.0);
    glColor3f(0, 0, 1); glVertex3f(-0.6, -0.7, 0.0);
    */

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
