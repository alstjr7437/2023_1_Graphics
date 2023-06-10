//가시화 실습 예제 

#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void InitLight() {	// 조명 효과
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };		// 물체에 따른 각 빛 반사
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };	// 불빛 정의
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 2, 3.0, 0.0 };

	glShadeModel(GL_SMOOTH);	//랜더링 기법중 하나
	glEnable(GL_LIGHTING);		//사용하겟다
	glEnable(GL_LIGHT0);		//opengl은 조명 8개 까지 가능 0번 조명 
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void InitVisibility() {
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);		// 바라볼때 CW(시계 방향)냐 CCW(반시계 방향)
	glCullFace(GL_BACK);	// back을 지울지 front 지울지 선택
	glEnable(GL_DEPTH_TEST);	// 겹쳐졌을때 A가 보일지 B가 보일지 선택 / 뚫고 지날시 pixel마다 달라짐
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(-30.0, 0.0, 1.0, 0.0); // x축을 중심으로 30도 회전
	glutWireCube(1);
	//glFlush(); 애니매이션 위해서 glFlush X
	glutSwapBuffers();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.7, -0.5, -0.5);
	glVertex3f(1,1.3,0);
	glVertex3f(0.3, -0.5, 0.5);
	glEnd();

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 2.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.4, 0.5, 0.0, -0.5, -1.0, 0.0, 1.0, 0.0);	//카메라의 위치

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// double 애니매이션 용도, rgb a(알파값) 컬러, depth 카메라로 얼마나 멀리 
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(0.5, 0.5, 0.5, 0.0);
	InitLight();	// 조명에 따라서 색깔이 보여지게 할지
	InitVisibility();	// 가시성 
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	//glutIdleFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
