#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);	// ��Ʈ������ ���ؼ� ���� ��ġ
	glLoadIdentity();				// ���� ��� �ʱ�ȭ
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);	// ����ü ������ ���ú��� ����(��,��,��,��,��,��)
	glMatrixMode(GL_MODELVIEW);		// �� �� ��Ʈ���� ����
	glLoadIdentity();	// ��� �ʱ�ȭ
}

// �׸��� �κ�
void DrawScene() {
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();		// ���� �𵨺� ��Ʈ���� ���ÿ� ����
	glTranslatef(0.0, -1.0, 0.0);	// ���� ����� ��ȯ ��Ŀ� ��(x,y,z)
	glBegin(GL_QUADS);			// �׸� �׸���
	glVertex3f(2.0, 0.0, 2.0);		// x,y,z
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();					// ���� �׸��� ����!
	glPopMatrix();	
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);		// ���� ����� ��ȯ ��Ŀ� ��(x,y,z)
	glutWireTeapot(1.0);	//������ �׸���
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	//���� �Ʒ�	x = 0 , y = 0 width height ���ݾ� �ؼ� 4�� ��������
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);	//x,y,width,height â�� ��ġ ���� 
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	//������ �Ʒ� x = width / 2�ؼ� ������ , y = 0 �ؼ� �Ʒ�
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	//���� �� x = 0�ؼ� ���� y = height / 2 �ؼ� �� ������
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();

	//������ �� x = width / 2�ؼ� y = height / 2 �ؼ� �� ������
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
