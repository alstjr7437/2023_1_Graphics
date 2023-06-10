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

	//아래 밑면 그리기
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();		// 현재 모델뷰 메트릭스 스택에 저장
	glTranslatef(0.0, -1.0, 0.0);	// 현재 행렬을 변환 행렬에 곱(x,y,z)
	glBegin(GL_QUADS);			// 밑면 네모 그리기
	glVertex3f(2.0, 0.0, 3.0);		// x,y,z
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 3.0);
	glEnd();					// 도형 그리기 끄읕!
	glPopMatrix();

	// 왼쪽 위 주전자 그리기
	glColor3f(0.0, 0.0, 1.0); // 파란색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(-1.0, 0.0, 0.0);		// x -1만큼 이동
	glRotatef(-45.0, 1.0, 0.0, 0.0); // x축을 중심으로 -45도 회전
	glutWireTeapot(0.5); // 주전자 그리기 
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원


	// 오른쪽 아래 주전자 그리기
	glColor3f(1.0, 0.0, 0.0); // 빨간색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(1.0, 0.0, 1.5);	// x 1만큼 z 1.5만큼 이동
	glRotatef(-30.0, 0.0, 1.0, 0.0); // y축을 중심으로 -30도 회전
	glRotatef(30.0, 0.0, 0.0, 1.0); // z축을 중심으로 30도 회전
	glRotatef(-10.0, 1.0, 0.0, 0.0); // x축을 중심으로 -10도 회전
	glutWireTeapot(0.5); // 주전자 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원


	// 오른쪽 위 원뿔 그리기
	glColor3f(1.0, 0.0, 0.0); // 빨간색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(1.0, 0.0, 0.5);	// x 1만큼 z 0.5만큼 이동
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x축을 중심으로 -90도 회전
	glutWireCone(0.3, 1.8, 16, 16); // 원뿔 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원

	// 왼쪽 아래 큐브 그리기
	glColor3f(0.0, 0.0, 1.0); // 파란색 선택
	glPushMatrix(); // 현재 모델뷰 행렬을 저장
	glTranslatef(-1.0, 0.0, 1.5);	// x -1만큼 z 1.5만큼 이동
	glRotatef(-45.0, 0.0, 1.0, 0.0); // y축을 중심으로 -45도 회전
	glScalef(0.3, 1.0, 0.5); // x축으로 0.3배, y축으로 1배, z축으로 0.5배 스케일링(네모 크기 지정하기)(원래는 정사각형)
	glutWireCube(1.0); // 사각형 그리기
	glPopMatrix(); // 이전의 모델뷰 행렬을 복원
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0, 1.0, 2.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);		//카메라 위치, 초점, 카메라 상향 벡터(x,y,z)순으로 쭉 나열
	DrawScene();	//만들진 도형들 넣기
	glPopMatrix();

	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("mid test");
	Init();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
