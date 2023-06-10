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

	//�Ʒ� �ظ� �׸���
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();		// ���� �𵨺� ��Ʈ���� ���ÿ� ����
	glTranslatef(0.0, -1.0, 0.0);	// ���� ����� ��ȯ ��Ŀ� ��(x,y,z)
	glBegin(GL_QUADS);			// �ظ� �׸� �׸���
	glVertex3f(2.0, 0.0, 3.0);		// x,y,z
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 3.0);
	glEnd();					// ���� �׸��� ����!
	glPopMatrix();

	// ���� �� ������ �׸���
	glColor3f(0.0, 0.0, 1.0); // �Ķ��� ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(-1.0, 0.0, 0.0);		// x -1��ŭ �̵�
	glRotatef(-45.0, 1.0, 0.0, 0.0); // x���� �߽����� -45�� ȸ��
	glutWireTeapot(0.5); // ������ �׸��� 
	glPopMatrix(); // ������ �𵨺� ����� ����


	// ������ �Ʒ� ������ �׸���
	glColor3f(1.0, 0.0, 0.0); // ������ ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(1.0, 0.0, 1.5);	// x 1��ŭ z 1.5��ŭ �̵�
	glRotatef(-30.0, 0.0, 1.0, 0.0); // y���� �߽����� -30�� ȸ��
	glRotatef(30.0, 0.0, 0.0, 1.0); // z���� �߽����� 30�� ȸ��
	glRotatef(-10.0, 1.0, 0.0, 0.0); // x���� �߽����� -10�� ȸ��
	glutWireTeapot(0.5); // ������ �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����


	// ������ �� ���� �׸���
	glColor3f(1.0, 0.0, 0.0); // ������ ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(1.0, 0.0, 0.5);	// x 1��ŭ z 0.5��ŭ �̵�
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x���� �߽����� -90�� ȸ��
	glutWireCone(0.3, 1.8, 16, 16); // ���� �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����

	// ���� �Ʒ� ť�� �׸���
	glColor3f(0.0, 0.0, 1.0); // �Ķ��� ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(-1.0, 0.0, 1.5);	// x -1��ŭ z 1.5��ŭ �̵�
	glRotatef(-45.0, 0.0, 1.0, 0.0); // y���� �߽����� -45�� ȸ��
	glScalef(0.3, 1.0, 0.5); // x������ 0.3��, y������ 1��, z������ 0.5�� �����ϸ�(�׸� ũ�� �����ϱ�)(������ ���簢��)
	glutWireCube(1.0); // �簢�� �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0, 1.0, 2.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);		//ī�޶� ��ġ, ����, ī�޶� ���� ����(x,y,z)������ �� ����
	DrawScene();	//������ ������ �ֱ�
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
