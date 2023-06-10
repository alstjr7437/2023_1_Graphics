#include <windows.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);		// �ٰ��� POLYGON 
    glVertex3f(-0.5, -0.5, 0.0);		// Vertex3f�� 4���� ������ ���� 
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();		//������� ���� ��ɾ ���μ����� ���� 
}

//main�� ���� glut �Լ� 
int main(int argc, char** argv) {
    glutInit(&argc, argv);	//���̺귯�� �ʱ�ȭ, �÷����� ������ý��� ���� 
    glutInitWindowPosition(100, 100);		//(x,y) �۾������� ũ�� ����(default : 300 300) 
    glutInitWindowSize(400, 500);		// ������ ���� 
    glutInitDisplayMode(GLUT_RGBA);		// ���÷��� ǥ���� �ֿ� Ư¡ ���� 
    glutCreateWindow("OpenGL Drawing Example");		//���ο� ������ ���� ��ɾ� (�̸�) 

    glutDisplayFunc(MyDisplay); // MyDisplay�Լ� ���÷��� �̺�Ʈ�� ���� �ݹ� �Լ� ��� 
    glutMainLoop();		// ���� �Լ��� �������� MainLoop�� �� �̺�Ʈ ���� ������ �ϱ� ���� 
    return 0;

}

/*
���                                              ����
GLUT_RGBA, GLUT_RGB                 Ʈ���÷� ���, �⺻��
GLUT_INDEX                                  �ȷ�Ʈ�� ����ϴ� �ε��� ���, ���� ������
GLUT_SINGLE                                �̱۹��� ���, �⺻��
GLUT_DOUBLE                               ������� ���
GLUT_DEPTH                                 ���̹��۸� ����Ѵ�
GLUT_ACCUM                                �������۸� ����Ѵ�
GLUT_ALPHA                                 ���� ���İ��� ����Ѵ�
GLUT_STENCIL                               ���ٽ� ���۸� ����Ѵ�
GLUT_MULTISAMPLE                      ��Ƽ���ø��� �����Ѵ�. 
                                                     Ŭ���̾�Ʈ�� ������ ���������ؾ��Ѵ�.
GLUT_STEREO                               ���׷��� �����츦 ����Ѵ�.
GLUT_LUMINANCE                          ��̳ͽ� ������� ����Ѵ�.

���ٸ� ������ ������ 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
�� �ʱ�ȭ�մϴ�.
*/
