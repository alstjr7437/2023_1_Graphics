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

	// 왼쪽 위 주전자 그리기
	glColor3f(0.0, 0.0, 1.0); // 파란색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(-1.0, 0.0, -1.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x축 중심 90도 회전
	glutWireTeapot(0.5); // 주전자 그리기 
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원


	// 오른쪽 아래 주전자 그리기
	glColor3f(1.0, 0.0, 0.0); // 빨간색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(1.0, 0.0, 1.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x축 중심 90도 회전
	glRotatef(-50.0, 0.0, 1.0, 0.0); // x축 중심 90도 회전
	glRotatef(30.0, 0.0, 0.0, 1.0); // x축 중심 90도 회전
	glutWireTeapot(0.5); // 주전자 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원


	// 오른쪽 위 원뿔 그리기
	glColor3f(1.0, 0.0, 0.0); // 빨간색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(1.0, 0.0, -0.7);
	glRotatef(-210, 1.0, 0.0, 0.0); // x축 중심 90도 회전
	glutWireCone(0.3, 1.3, 16, 16); // 원뿔 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원

	// 왼쪽 아래 큐브 그리기
	glColor3f(0.0, 0.0, 1.0); // 파란색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(-1.0, 0.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0); // x축 중심 90도 회전
	glRotatef(120, 0.0, 1.0, 0.0); // x축 중심 90도 회전
	glRotatef(15, 0.0, 0.0, 1.0); // z축 중심 90도 회전
	glScalef(0.2, 1.0, 0.5); // x축으로 1배, y축으로 0.2배, z축으로 0.5배 스케일링
	glutWireCube(1.0); // 사각형 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
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
