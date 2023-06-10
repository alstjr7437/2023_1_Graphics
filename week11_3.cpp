//조명 및 음영 실습자료 

#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\GLU.h>

GLfloat angle = 0;

void light_spec() {
	GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };	//전역 주변반사

	GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; 	//0번 광원 특성
	GLfloat light0_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };	//1번 광원 특성
	GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0 };
	GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };

	GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 };	//물체 특성
	GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat material_specular[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_SMOOTH);	//구로 셰이딩
	glEnable(GL_DEPTH_TEST);	//깊이 버퍼 활성화
	glEnable(GL_LIGHTING);		//조명 활성화   //두꺼집과 같은 역할

	glEnable(GL_LIGHT0);		//0번 광원 활성화
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);	//0번 광원 특성할당
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glEnable(GL_LIGHT1);		//1번 광원 활성화
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);	//1번 광원 특성할당
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);//물체 특성할당
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//전역주변반사 
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); //근접시점

}
void MyDisplay() {
	GLfloat  lightPosition0[] = { 0,0,2.0,1.0 };  // 0번조명
	GLfloat lightPosition1[] = { 1,1,1,1 };       // 1번 조명 : 서치라이트
	GLfloat lightDirection[] = { -0.5, -1.0, -1.0 };
	GLfloat SpotAngle[] = { 20 };

	angle += 1;
	light_spec();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection);
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glRotatef(angle, 1, 1, 1);
	glTranslatef(0.3, 0.3, 0);
	glutSolidTorus(0.3, 0.6, 800, 800);

	glutSwapBuffers(); //  glFlush();

}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("opengl light test ");

	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
