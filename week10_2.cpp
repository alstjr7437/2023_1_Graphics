/* #�μ����� ���� 3�� �ڵ�
#include <windows.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

static int Day = 0, Time = 0;

void Draw_shape() {
   glPushMatrix();
   glPushMatrix();
   glRotatef(-90, 1, 0, 0);
   glutWireCone(0.1, 0.6, 10, 10);
   glPopMatrix();
   glTranslatef(0, 0.5, 0);
   glutWireSphere(0.1, 15, 15);
   glPopMatrix();
}

void MyDisPlay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glRotatef(0.1, 0, 1, 0);
   glColor3f(1, 0, 0);
   Draw_shape();

   glPushMatrix();
   glColor3f(0, 1, 0);
   glTranslated(0.5, -0.5, 0.1);
   Draw_shape();

   glPopMatrix();
   glPushMatrix();
   glColor3f(0, 0, 1);
   glTranslated(-0.5, -0.5, 0.1);
   Draw_shape();

   glPopMatrix();
   glutSwapBuffers();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("homework2");
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glutDisplayFunc(MyDisPlay);
   glutMainLoop();
   return 0;
}
*/

/*#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

// ��ó���� ��Ƽ��
// OpenGL ���̺귯�� �� GLUT ���̺귯���� ����ϱ� ���� ��� ������ �ҷ��´�.

int Width, Height;

void Init() {
   // OpenGL �ʱ�ȭ �Լ�
   glClearColor(1.0, 1.0, 1.0, 1.0); // ������ ������� �����Ѵ�.
   glMatrixMode(GL_PROJECTION); // �������� ��Ʈ���� ����
   glLoadIdentity(); // ���� �������� ��Ʈ������ ������ķ� �ʱ�ȭ�Ѵ�.
   glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // ���� ��ǥ�迡 �ش��ϴ� ����, ������, �Ʒ���, ����, �ٴܸ�, ���ܸ� ���� ����Ͽ� ť�꿡 �ش��ϴ� ������ �����Ѵ�.
   glMatrixMode(GL_MODELVIEW); // �𵨺� ��Ʈ���� ����
   glLoadIdentity(); // ���� �𵨺� ��Ʈ������ ������ķ� �ʱ�ȭ�Ѵ�.
}

void DrawScene() {
   // ���� �׸��� �Լ�
   glColor3f(0.7, 0.7, 0.7); // ȸ������ ����
   glPushMatrix();   // ���� �𵨺� ��Ʈ������ ���ÿ� �����Ѵ�.
   glTranslatef(0.0, -1.0, 0.0);   // ��ǥ���� �������� y�� �������� �̵��Ѵ�.
   glBegin(GL_QUADS);
   // ���簢�� �׸��� ����
   glVertex3f(2.0, 0.0, 2.0);
   glVertex3f(2.0, 0.0, -2.0);
   glVertex3f(-2.0, 0.0, -2.0);
   glVertex3f(-2.0, 0.0, 2.0);
   // ���簢�� �׸��� ��
   glEnd();   // �׸��� ����
   glPopMatrix();   // ���ÿ��� �𵨺� ��Ʈ������ ������ ���� �𵨺� ��Ʈ������ ����Ѵ�.
   glColor3f(0.3, 0.3, 0.7);   // �Ķ������� ����
   glPushMatrix();   // ���� �𵨺� ��Ʈ������ ���ÿ� �����Ѵ�.
   glTranslatef(0.0, 0.0, -0.5);   // ��ǥ���� �������� z�� �������� �̵��Ѵ�.
   glutWireTeapot(1.0);   // Ƽ���� �׸���.
   glPopMatrix();   // ���ÿ��� �𵨺� ��Ʈ������ ������ ���� ��
}

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glViewport(0, 0, Width / 2, Height / 2);
   glPushMatrix();
   gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   DrawScene();
   glPopMatrix();
   glViewport(Width / 2, 0, Width / 2, Height / 2);
   glPushMatrix();
   gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   DrawScene();
   glPopMatrix();
   glViewport(0, Height / 2, Width / 2, Height / 2);
   glPushMatrix();
   gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
   DrawScene();
   glPopMatrix();
   glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   gluPerspective(30, 1.0, 3.0, 50.0);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   DrawScene();
   glPopMatrix();
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glFlush();
}

void MyReshape(int w, int h) {
   Width = w;   Height = h;
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);  // GLUT �ʱ�ȭ
   Width = 500; Height = 500;
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(Width, Height);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("OpenGL Sample Drawing");
   Init();
   glutDisplayFunc(MyDisplay);
   glutReshapeFunc(MyReshape);
   glutMainLoop();
   return 0;
}
*/
/* #1 �⺻ �簢�� ���
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
   glFlush(); //����̹��� �����Ÿ� ���� ���ϰ� �ϰ� ��������� �Լ��� ��� ���μ����� ����
   =
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutCreateWindow("first example");
   glutDisplayFunc(MyDisplay);
   glutMainLoop();
   return 0;
}
*/

/* #2 ������� ����Ʈ ����
#include <gl\glut.h> // ������ glut - gl - glu ������ �ۼ��ؾ� �� �ֱ׷����� ���� �𸣰��� �̤�
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glViewport(0, 0, 300, 300); // ����Ʈ ���� �̰� ���� �س����� ȭ�� ũ�� ���� �� �׷��� ������ ���� �Ǵ� ���� ���� �� ����.
   glColor3f(1.0, 1.0, 0.0); // 3���� ��ü�� ����, �̸� ���� �س��� glBegin �ؾ���.
   glBegin(GL_POLYGON); // �簢�� �׸��� �ڵ� ���ϴ� ������ ��ġ��
      glVertex3f(-0.5, -0.5, 0.0);
      glVertex3f(0.5, -0.5, 0.0);
      glVertex3f(0.5, 0.5, 0.0);
      glVertex3f(-0.5, 0.5, 0.0);
   glEnd(); //�簢�� �׸��� ��
   glFlush(); //����̹��� �����Ÿ� ���� ���ϰ� �ϰ� ��������� �Լ��� ��� ���μ����� ����
}

int main(int argc, char **argv) {
   glutInit(&argc, argv); // ���� �̰� ���ϸ� �ȵ��ư���.
   glutInitDisplayMode(GLUT_RGB); // �������� �⺻ �÷� ��带 RGB�� ������.
   glutInitWindowSize(300, 300); // ������ â ����� 300X300���� ����
   glutInitWindowPosition(0,0); // ���� ��ܿ� �������� ��
   glutCreateWindow("first example");
   glClearColor(0, 0, 0, 1); // ������ â �� �ʱ�ȭ R,G,B,������(1�̸� ������ 0�̸� �ڿ��� ���̴� ����)
   glMatrixMode(GL_PROJECTION); // ������ ������ ����ϰڴٴ� ���Դϴ�. ������ ǥ���ϱ� ���� �����մϴ�.
   glLoadIdentity(); //��ǥ�� �ʱ�ȭ
   glOrtho(-1, 1, -1, 1, -1, 1); //https://learn.microsoft.com/ko-kr/windows/win32/opengl/glortho
   glutDisplayFunc(MyDisplay); //�� �������ְ� ���÷��� �Լ� ����
   glutMainLoop();
   return 0;
}
*/

/* 5-5 �������� �ݹ�
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5);
   glBegin(GL_POLYGON);
      glVertex3f(-0.5, -0.5, 0.0);
      glVertex3f(0.5, -0.5, 0.0);
      glVertex3f(0.5, 0.5, 0.0);
      glVertex3f(-0.5, 0.5, 0.0);
   glEnd();
   glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
   glViewport(0, 0, NewWidth, NewHeight); // ��� ������ ��µ� ���ΰ�.
   GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
   GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1 * WidthFactor, 1 * WidthFactor, -1 * HeightFactor, 1 * HeightFactor, -1, 1);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-5");
   glClearColor(1, 1, 1, 1);
   glutDisplayFunc(MyDisplay);
   glutReshapeFunc(MyReshape);
   glutMainLoop();
   return 0;
}
*/

/* #5-6 Ű���� �ݹ�
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5);
   glBegin(GL_POLYGON);
      glVertex3f(-0.5, -0.5, 0.0);
      glVertex3f(-0.5, 0.5, 0.0);
      glVertex3f(0.5, 0.5, 0.0);
      glVertex3f(0.5, -0.5, 0.0);
   glEnd();
   glFlush();
}

void MyKeyBoard(unsigned char KeyPressed , int X ,int Y) {
   switch (KeyPressed)
   {
   case 'Q':
      exit(0); break;
   case 'q':
      exit(0); break;
   case '27':
      exit(0); break;
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-6");
   glutDisplayFunc(MyDisplay);
   glutKeyboardFunc(MyKeyBoard);
   glutMainLoop();
   return 0;
}
*/
/*5-7 ���콺 �ݹ� 
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5);
   glBegin(GL_POLYGON);
   glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0);
   glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
   glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
   glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0.0);
   glEnd();
   glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
   if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { //GLUT_DOWN = ���� ���� UP�� ������ ���� ���� 
      TopLeftX = X;
      TopLeftY = Y;
   }
}

void MyMouseMove(GLint X, GLint Y) {
   BottomRightX = X;
   BottomRightY = Y;
   glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-7");
   glClearColor(1, 1, 1, 1);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 1, 0, 1, -1, 1);
   glutDisplayFunc(MyDisplay);
   glutMouseFunc(MyMouseClick); // ���콺 �Լ����� Ŭ�� , ��� , ���� �ִ�. 
   glutMotionFunc(MyMouseMove);
   glutMainLoop();
   return 0;
}
*/
/* 5-7 + 5-6 ����
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void Mydisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5);
   glBegin(GL_POLYGON); // ������ ������ �ƴ϶� float 300 ���� 300.0���� �ؾ� ���ư�
      glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0);
      glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0);
      glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0);
      glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0);
   glEnd();
   glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
   if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {//GL_LEFT�� �ƴ϶� GLUT_LEFT_BUTTON�̾���
      TopLeftX = X;
      TopLeftY = Y;
   }
}
void MyMouseMotion(GLint X, GLint Y) {
   BottomRightX = X;
   BottomRightY = Y;
   glutPostRedisplay();
}
void MyKeyBoard(unsigned char keypressed, int x, int y) {
   switch (keypressed)
   {
   case 'Q':
      exit(0); break;
   case 'q':
      exit(0); break;
   case '27':
      exit(0); break;
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300,300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("apllication of 5-6 and 5-7");
   //���� �ڵ�� ���� �ؾ���
   glClearColor(1, 1, 1, 1);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 1, 0, 1, -1, 1);
   //�������
   glutDisplayFunc(Mydisplay);
   glutKeyboardFunc(MyKeyBoard);
   glutMouseFunc(MyMouseClick);
   glutMotionFunc(MyMouseMotion);
   glutMainLoop();
   return 0;
}
*/

/*5-8 �޴�
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLboolean isSphere = true;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.0, 0.5);
   if (isSphere) {
      glutWireSphere(0.2, 15, 15);
   }
   else glutWireTorus(0.1, 0.3, 40, 20);
   glFlush();
}
void MyMainMenu(int entryID) {
   if (entryID == 1)
      isSphere = 1;
   else if (entryID == 2)
      isSphere = 0;
   else if (entryID == 3)
      exit(0);
   glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-8");
   glClearColor(1.0, 1.0, 1.0, 1.0);

   //���� ��� ���
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, - 1.0, 1.0, - 1.0, 1.0); //���� ����(orthographic projection)�� �����ϸ�, ����, ������, �Ʒ���, ����, ����� ��, �� ���� ��踦 ����

   //�޴� ����� ���ε�
   GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //MyMainMenu��� �޴��� �����ϰ� �ű⿡ �� ���� MyMainMenuID�̴�.
   glutAddMenuEntry("Draw Sphere", 1); // 1 �Ҵ��ϴ� �޴�
   glutAddMenuEntry("Draw Torus", 2); // 2 �Ҵ��ϴ� �޴�
   glutAddMenuEntry("Exit", 3); // 3 �Ҵ��ϴ� �޴�
   glutAttachMenu(GLUT_RIGHT_BUTTON); // ��Ŭ�� �� �޴� ���� �ǰ� ������

   glutDisplayFunc(MyDisplay);
   glutMainLoop();
   return 0;
}
*/

/*5-9 ��ܽ� �޴�
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLboolean isSphere = true;
GLboolean isSmall = true;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5); // glColor3f�� RGB���� glClearColor RGB���̶� ������ �ȵ� �׷��� ������ �Ȱ�
   if ((isSphere) && (isSmall))
      glutWireSphere(0.2, 15, 15);
   else if ((isSphere) && (!isSmall))
      glutWireSphere(0.4, 15, 15);
   else if ((!isSphere) && (isSmall))
      glutWireTorus(0.1,0.3, 20, 40);
   else glutWireTorus(0.2, 0.5, 20, 40);
   glFlush();
}

void MyMainMenu(int entryID) {
   if (entryID == 1)
      isSphere = true;
   else if (entryID == 2)
      isSphere = false;
   else
      exit(0);
   glutPostRedisplay();
}

void MySubMenu(int entryID) {
   if (entryID == 1)
      isSmall = true;
   else if (entryID == 2)
      isSmall = false;
   glutPostRedisplay();
}

int main(int argc , char ** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-9");
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

   GLint MySubMenuID = glutCreateMenu(MySubMenu);
   glutAddMenuEntry("SMALL", 1);
   glutAddMenuEntry("BIG", 2);
   GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
   glutAddMenuEntry("SPHERE", 1);
   glutAddMenuEntry("TORUS", 2);
   glutAddSubMenu("CHANGE SIZE", MySubMenuID);
   glutAddMenuEntry("EXIT", 3);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
   glutDisplayFunc(MyDisplay);
   glutMainLoop();
   return 0;

}
*/
/*5-10 IDLE Mode
* #include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLfloat Delta = 0.0;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POLYGON);
      glColor3f(0.5, 0.5, 0.5);
      glVertex3f(-1.0 + Delta, -0.5, 0.0);
      glVertex3f(0.0 + Delta, -0.5, 0.0);
      glVertex3f(0.0 + Delta, 0.5, 0.0);
      glVertex3f(-1.0 + Delta, 0.5, 0.0);
   glEnd();
   glutSwapBuffers();
}

void MyIdle() {
   Delta = Delta + 0.001;
   glutPostRedisplay();
}

int main(int argc,char ** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE );
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-10");
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   glutDisplayFunc(MyDisplay);
   glutIdleFunc(MyIdle);
   glutMainLoop();
   return 0;
}
*/

/*5-11 Ÿ�̸�
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLfloat Delta = 0.0;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POLYGON);
      glColor3f(0.5, 0.5, 0.5);
      glVertex3f(-1.0 + Delta, 0.5, 1.0);
      glVertex3f(0.0 + Delta, 0.5, 1.0);
      glVertex3f(0.0 + Delta, -0.5, 1.0);
      glVertex3f(-1.0 + Delta, -0.5, 1.0);
   glEnd();
   glutSwapBuffers();
}

void MyTimer(int Value) {
   Delta = Delta + 0.001;
   glutPostRedisplay();
   glutTimerFunc(40, MyTimer, 1);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize(300, 300);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("5-11");
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   glutDisplayFunc(MyDisplay);
   glutTimerFunc(40,MyTimer,1);
   glutMainLoop();
   return 0;
}
*/
