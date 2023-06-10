#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);	// 매트릭스를 곱해서 실제 위치
	glLoadIdentity();				// 이전 행렬 초기화
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);	// 육면체 형식의 가시부피 설정(좌,우,하,상,전,후)
	glMatrixMode(GL_MODELVIEW);		// 모델 뷰 메트릭스 선택
	glLoadIdentity();	// 행렬 초기화
}

// 그리는 부분
void DrawScene() {
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();		// 현재 모델뷰 메트릭스 스택에 저장
	glTranslatef(0.0, -1.0, 0.0);	// 현재 행렬을 변환 행렬에 곱(x,y,z)
	glBegin(GL_QUADS);			// 네모 그리기
	glVertex3f(2.0, 0.0, 2.0);		// x,y,z
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();					// 도형 그리기 끄읕!
	glPopMatrix();	
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);		// 현재 행렬을 변환 행렬에 곱(x,y,z)
	glutWireTeapot(1.0);	//주전자 그리기
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	//왼쪽 아래	x = 0 , y = 0 width height 절반씩 해서 4개 나오도록
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);	//x,y,width,height 창에 위치 설정 
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	//오른쪽 아래 x = width / 2해서 오른쪽 , y = 0 해서 아래
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	//왼쪽 위 x = 0해서 왼쪽 y = height / 2 해서 위 가도록
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();

	//오른쪽 위 x = width / 2해서 y = height / 2 해서 위 가도록
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
	glutInit(&argc, argv);
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
