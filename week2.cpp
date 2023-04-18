#include <GL/glut.h>

void Draw_shape() {
    glPushMatrix();     // 현재 행렬 스택 저장
    glPushMatrix();     // 
    glRotatef(-90, 1, 0, 0);    // 현재 행렬에 회전 행렬 곱 (각도, x, y, z)
    glutWireCone(0.1, 0.6, 10, 10);     // 원뿔 그리기(반지름, 높이, 위 아래 면의 수, 가로 면의 수)
    glPopMatrix();      // 현재 행렬 스택 팝팝팝~
    glTranslatef(0, 0.5, 0);    // 현재 행렬을 변환 행렬에 곱(x,y,z)
    glutWireSphere(0.1, 15, 15);    // 구 그리기(반지름, 세로 세분화, 가로 세분화)
    glPopMatrix();
}

void MyDisPlay() {
    glClear(GL_COLOR_BUFFER_BIT);   // 색상 버퍼 지우기
    glMatrixMode(GL_MODELVIEW);     // 매트릭스 곱해서 실제적 위치 지정
    glRotatef(0.1, 0, 1, 0);        
    glColor3f(1, 0, 0);             // 컬러 넣기(빨,녹,파)
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
// glut 그래픽을 그리기 위한 껍데기 만들기
int main(int argc, char** argv) {
    glutInit(&argc, argv);  // 라이브러리 초기화, 플랫폼과 윈도우 시스템 연결
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //디스 플레이 표면의 주요 특징 결정
                                        // 더블 : 더블 버퍼 사용, 트루컬러 모드, 기본값
    glutInitWindowSize(800, 800);     
    glutInitWindowPosition(0, 0);
    glutCreateWindow("homework2");
    glClearColor(1.0, 1.0, 1.0, 1.0);       // r,g,b,투명도
    glMatrixMode(GL_PROJECTION);            // 화면에 뿌리기
    glLoadIdentity();       // 현재 행렬을 ID 행렬로 바꾸기
    glutDisplayFunc(MyDisPlay);     // 렌더 콜백 함수 렌더링 필요할때 접근하는 함수
    glutMainLoop();     // glut 이벤트 처리
    return 0;
}
