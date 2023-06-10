/* #민석이형 원뿔 3개 코드
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

// 전처리기 디렉티브
// OpenGL 라이브러리 및 GLUT 라이브러리를 사용하기 위해 헤더 파일을 불러온다.

int Width, Height;

void Init() {
   // OpenGL 초기화 함수
   glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색을 흰색으로 지정한다.
   glMatrixMode(GL_PROJECTION); // 프로젝션 매트릭스 선택
   glLoadIdentity(); // 현재 프로젝션 매트릭스를 단위행렬로 초기화한다.
   glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // 직각 좌표계에 해당하는 왼쪽, 오른쪽, 아래쪽, 위쪽, 근단면, 원단면 값을 사용하여 큐브에 해당하는 공간을 정의한다.
   glMatrixMode(GL_MODELVIEW); // 모델뷰 매트릭스 선택
   glLoadIdentity(); // 현재 모델뷰 매트릭스를 단위행렬로 초기화한다.
}

void DrawScene() {
   // 씬을 그리는 함수
   glColor3f(0.7, 0.7, 0.7); // 회색으로 지정
   glPushMatrix();   // 현재 모델뷰 매트릭스를 스택에 저장한다.
   glTranslatef(0.0, -1.0, 0.0);   // 좌표축을 기준으로 y축 방향으로 이동한다.
   glBegin(GL_QUADS);
   // 정사각형 그리기 시작
   glVertex3f(2.0, 0.0, 2.0);
   glVertex3f(2.0, 0.0, -2.0);
   glVertex3f(-2.0, 0.0, -2.0);
   glVertex3f(-2.0, 0.0, 2.0);
   // 정사각형 그리기 끝
   glEnd();   // 그리기 종료
   glPopMatrix();   // 스택에서 모델뷰 매트릭스를 꺼내서 현재 모델뷰 매트릭스로 사용한다.
   glColor3f(0.3, 0.3, 0.7);   // 파란색으로 지정
   glPushMatrix();   // 현재 모델뷰 매트릭스를 스택에 저장한다.
   glTranslatef(0.0, 0.0, -0.5);   // 좌표축을 기준으로 z축 방향으로 이동한다.
   glutWireTeapot(1.0);   // 티팟을 그린다.
   glPopMatrix();   // 스택에서 모델뷰 매트릭스를 꺼내서 현재 모델
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
   glutInit(&argc, argv);  // GLUT 초기화
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
/* #1 기본 사각형 출력
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
   glFlush(); //드라이버가 헛짓거리 하지 못하게 하고 현재까지의 함수를 모두 프로세서로 보냄
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

/* #2 윈도우와 뷰포트 공부
#include <gl\glut.h> // 무조건 glut - gl - glu 순으로 작성해야 함 왜그런지는 나도 모르겠음 ㅜㅜ
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glViewport(0, 0, 300, 300); // 뷰포트 설정 이거 설정 해놓으면 화면 크기 조정 시 그래픽 비율이 조정 되는 것을 막을 수 있음.
   glColor3f(1.0, 1.0, 0.0); // 3차원 물체의 색상, 미리 정의 해놓고 glBegin 해야함.
   glBegin(GL_POLYGON); // 사각형 그리는 코드 이하는 정점의 위치임
      glVertex3f(-0.5, -0.5, 0.0);
      glVertex3f(0.5, -0.5, 0.0);
      glVertex3f(0.5, 0.5, 0.0);
      glVertex3f(-0.5, 0.5, 0.0);
   glEnd(); //사각형 그리기 끝
   glFlush(); //드라이버가 헛짓거리 하지 못하게 하고 현재까지의 함수를 모두 프로세서로 보냄
}

int main(int argc, char **argv) {
   glutInit(&argc, argv); // 나는 이거 안하면 안돌아갔음.
   glutInitDisplayMode(GLUT_RGB); // 윈도우의 기본 컬러 모드를 RGB로 설정함.
   glutInitWindowSize(300, 300); // 윈도우 창 사이즈를 300X300으로 설정
   glutInitWindowPosition(0,0); // 왼쪽 상단에 나오도록 함
   glutCreateWindow("first example");
   glClearColor(0, 0, 0, 1); // 윈도우 창 색 초기화 R,G,B,불투명도(1이면 불투명 0이면 뒤에가 보이는 투명)
   glMatrixMode(GL_PROJECTION); // 공간을 앞으로 계산하겠다는 뜻입니다. 투상을 표현하기 전에 선언합니다.
   glLoadIdentity(); //좌표계 초기화
   glOrtho(-1, 1, -1, 1, -1, 1); //https://learn.microsoft.com/ko-kr/windows/win32/opengl/glortho
   glutDisplayFunc(MyDisplay); //다 설정해주고 디스플레이 함수 실행
   glutMainLoop();
   return 0;
}
*/

/* 5-5 리셰이프 콜백
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
   glViewport(0, 0, NewWidth, NewHeight); // 어느 지점에 출력될 것인가.
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

/* #5-6 키보드 콜백
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
/*5-7 마우스 콜백 
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
   if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { //GLUT_DOWN = 누른 상태 UP은 누르지 않은 상태 
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
   glutMouseFunc(MyMouseClick); // 마우스 함수에는 클릭 , 모션 , 휠이 있다. 
   glutMotionFunc(MyMouseMove);
   glutMainLoop();
   return 0;
}
*/
/* 5-7 + 5-6 응용
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void Mydisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5);
   glBegin(GL_POLYGON); // 나누기 정수가 아니라 float 300 말고 300.0으로 해야 돌아감
      glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0);
      glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0);
      glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0);
      glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0);
   glEnd();
   glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
   if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {//GL_LEFT가 아니라 GLUT_LEFT_BUTTON이었음
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
   //이하 코드들 이해 해야함
   glClearColor(1, 1, 1, 1);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 1, 0, 1, -1, 1);
   //여기까지
   glutDisplayFunc(Mydisplay);
   glutKeyboardFunc(MyKeyBoard);
   glutMouseFunc(MyMouseClick);
   glutMotionFunc(MyMouseMotion);
   glutMainLoop();
   return 0;
}
*/

/*5-8 메뉴
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

   //투영 행렬 모드
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, - 1.0, 1.0, - 1.0, 1.0); //직교 투영(orthographic projection)을 수행하며, 왼쪽, 오른쪽, 아래쪽, 위쪽, 가까운 면, 먼 면의 경계를 정의

   //메뉴 만드는 라인들
   GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //MyMainMenu라는 메뉴를 생성하고 거기에 들어갈 값은 MyMainMenuID이다.
   glutAddMenuEntry("Draw Sphere", 1); // 1 할당하는 메뉴
   glutAddMenuEntry("Draw Torus", 2); // 2 할당하는 메뉴
   glutAddMenuEntry("Exit", 3); // 3 할당하는 메뉴
   glutAttachMenu(GLUT_RIGHT_BUTTON); // 우클릭 시 메뉴 생성 되게 연결함

   glutDisplayFunc(MyDisplay);
   glutMainLoop();
   return 0;
}
*/

/*5-9 계단식 메뉴
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

GLboolean isSphere = true;
GLboolean isSmall = true;

void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.5, 0.5, 0.5); // glColor3f의 RGB값과 glClearColor RGB값이랑 같으면 안됨 그러면 구분이 안감
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

/*5-11 타이머
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
