#include <windows.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <gl\glu.h>

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);		// 다각형 POLYGON 
    glVertex3f(-0.5, -0.5, 0.0);		// Vertex3f로 4개의 정점들 구성 
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glFlush();		//현재까지 쌓은 명령어를 프로세서에 전달 
}

//main은 전부 glut 함수 
int main(int argc, char** argv) {
    glutInit(&argc, argv);	//라이브러리 초기화, 플랫폼과 윈도우시스템 연결 
    glutInitWindowPosition(100, 100);		//(x,y) 작업공간의 크기 설정(default : 300 300) 
    glutInitWindowSize(400, 500);		// 사이즈 설정 
    glutInitDisplayMode(GLUT_RGBA);		// 디스플레이 표면의 주요 특징 설정 
    glutCreateWindow("OpenGL Drawing Example");		//새로운 윈도우 생성 명령어 (이름) 

    glutDisplayFunc(MyDisplay); // MyDisplay함수 디스플레이 이벤트에 대한 콜백 함수 등록 
    glutMainLoop();		// 메인 함수의 마지막은 MainLoop로 끝 이벤트 루프 돌려야 하기 때문 
    return 0;

}

/*
모드                                              설명
GLUT_RGBA, GLUT_RGB                 트루컬러 모드, 기본값
GLUT_INDEX                                  팔레트를 사용하는 인덱스 모드, 거의 사용안함
GLUT_SINGLE                                싱글버퍼 사용, 기본값
GLUT_DOUBLE                               더블버퍼 사용
GLUT_DEPTH                                 깊이버퍼를 사용한다
GLUT_ACCUM                                누적버퍼를 사용한다
GLUT_ALPHA                                 색상에 알파값을 사용한다
GLUT_STENCIL                               스텐실 버퍼를 사용한다
GLUT_MULTISAMPLE                      멀티샘플링을 지원한다. 
                                                     클라이언트와 서버가 동시지원해야한다.
GLUT_STEREO                               스테레오 윈도우를 사용한다.
GLUT_LUMINANCE                          루미넌스 색상모델을 사용한다.

별다른 지정이 없으면 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
로 초기화합니다.
*/
