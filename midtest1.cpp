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

	// ���� �� ������ �׸���
	glColor3f(0.0, 0.0, 1.0); // �Ķ��� ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(-1.0, 0.0, -1.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x�� �߽� 90�� ȸ��
	glutWireTeapot(0.5); // ������ �׸��� 
	glPopMatrix(); // ������ �𵨺� ����� ����


	// ������ �Ʒ� ������ �׸���
	glColor3f(1.0, 0.0, 0.0); // ������ ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(1.0, 0.0, 1.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0); // x�� �߽� 90�� ȸ��
	glRotatef(-50.0, 0.0, 1.0, 0.0); // x�� �߽� 90�� ȸ��
	glRotatef(30.0, 0.0, 0.0, 1.0); // x�� �߽� 90�� ȸ��
	glutWireTeapot(0.5); // ������ �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����


	// ������ �� ���� �׸���
	glColor3f(1.0, 0.0, 0.0); // ������ ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(1.0, 0.0, -0.7);
	glRotatef(-210, 1.0, 0.0, 0.0); // x�� �߽� 90�� ȸ��
	glutWireCone(0.3, 1.3, 16, 16); // ���� �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����

	// ���� �Ʒ� ť�� �׸���
	glColor3f(0.0, 0.0, 1.0); // �Ķ��� ����
	glPushMatrix(); // ���� �𵨺� ����� ����
	glTranslatef(-1.0, 0.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0); // x�� �߽� 90�� ȸ��
	glRotatef(120, 0.0, 1.0, 0.0); // x�� �߽� 90�� ȸ��
	glRotatef(15, 0.0, 0.0, 1.0); // z�� �߽� 90�� ȸ��
	glScalef(0.2, 1.0, 0.5); // x������ 1��, y������ 0.2��, z������ 0.5�� �����ϸ�
	glutWireCube(1.0); // �簢�� �׸���
	glPopMatrix(); // ������ �𵨺� ����� ����
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
