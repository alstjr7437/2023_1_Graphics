#include <GL/glut.h>

void Draw_shape() {
    glPushMatrix();     // ���� ��� ���� ����
    glPushMatrix();     // 
    glRotatef(-90, 1, 0, 0);    // ���� ��Ŀ� ȸ�� ��� �� (����, x, y, z)
    glutWireCone(0.1, 0.6, 10, 10);     // ���� �׸���(������, ����, �� �Ʒ� ���� ��, ���� ���� ��)
    glPopMatrix();      // ���� ��� ���� ������~
    glTranslatef(0, 0.5, 0);    // ���� ����� ��ȯ ��Ŀ� ��(x,y,z)
    glutWireSphere(0.1, 15, 15);    // �� �׸���(������, ���� ����ȭ, ���� ����ȭ)
    glPopMatrix();
}

void MyDisPlay() {
    glClear(GL_COLOR_BUFFER_BIT);   // ���� ���� �����
    glMatrixMode(GL_MODELVIEW);     // ��Ʈ���� ���ؼ� ������ ��ġ ����
    glRotatef(0.1, 0, 1, 0);        
    glColor3f(1, 0, 0);             // �÷� �ֱ�(��,��,��)
    Draw_shape();           // 

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
// glut �׷����� �׸��� ���� ������ �����
int main(int argc, char** argv) {
    glutInit(&argc, argv);  // ���̺귯�� �ʱ�ȭ, �÷����� ������ �ý��� ����
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //�� �÷��� ǥ���� �ֿ� Ư¡ ����
                                        // ���� : ���� ���� ���, Ʈ���÷� ���, �⺻��
    glutInitWindowSize(800, 800);     
    glutInitWindowPosition(0, 0);
    glutCreateWindow("homework2");
    glClearColor(1.0, 1.0, 1.0, 1.0);       // r,g,b,����
    glMatrixMode(GL_PROJECTION);            // ȭ�鿡 �Ѹ���
    glLoadIdentity();       // ���� ����� ID ��ķ� �ٲٱ�
    glutDisplayFunc(MyDisPlay);     // ���� �ݹ� �Լ� ������ �ʿ��Ҷ� �����ϴ� �Լ�
    glutMainLoop();     // glut �̺�Ʈ ó��
    return 0;
}
