#include <GL/glut.h>
#include <math.h>

#define PI 3.141592    // 파이

GLfloat Delta = 0.0;   // Delta 변수를 선언하고 0으로 초기화함
GLfloat x, y;          // x, y 좌표
GLfloat radius = 0.8;  // 반지름 0.8

bool goup = true;      // 물체가 올라가는 중인지 여부를 나타내는 변수

void MyDisplay() {     //화면을 그리는 함수. 원을 겹쳐서 무지개처럼 보이게 함.
    glClear(GL_COLOR_BUFFER_BIT);

    // 1번 물체
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);  //도형의 색상을 빨간색으로 지정함
    for (float i = 0; i < 360; i++) {           // i는 몇 도인지를 의미함.
        GLfloat angle = i * PI / 180;           // angle은 라디안 단위. 따라서 각도를 라디안 단위로 바꿔준다. 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // cos(angle)=x/반지름. 따라서 x좌표는 반지름*cos(angle). 여기서 angle은 라디안을 의미함.
        y = 0.1 + Delta + radius * sin(angle);  // sin(angle)=y/반지름. 따라서 y좌표는 반지름*sin(angle). 여기서 angle은 라디안을 의미함.
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();


    // 2번 물체
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0.0); //도형의 색상을 주황색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // x좌표
        y = 0.0 + Delta + radius * sin(angle);  // y좌표. 원의 중심(-0.2, 0.0)
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 3번 물체
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0); //도형의 색상을 노란색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // x좌표
        y = -0.1 + Delta + radius * sin(angle);  // y좌표 원의 중심(-0.5, 0.3)
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 4번 물체
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1, 0.0); //도형의 색상을 초록색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // x좌표
        y = -0.2 + Delta + radius * sin(angle);  // y좌표 원의 중심(-0.5, 0.2)
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 5번 물체
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); //도형의 색상을 파란색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // x좌표
        y = -0.3 + Delta + radius * sin(angle);  // y좌표. 원의 중심(-0.5, 0.1)
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 6번 물체
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); //도형의 색상을 남색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle); // x좌표
        y = -0.4 + Delta + radius * sin(angle);  // y좌표. 원의 중심(-0.5, 0.0)
        glVertex3f(x, y, 0.0);                  // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 7번 물체
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 1); //도형의 색상을 보라색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;            // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle);  // x좌표
        y = -0.5 + Delta + radius * sin(angle);  // y좌표. 원의 중심(-0.5, -0.1)
        glVertex3f(x, y, 0.0);                   // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();

    // 8번 물체
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // 무지개처럼 보이도록 마지막 도형은 흰색으로 지정함
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;            // 1도 = PI/180라디안
        x = -0.2 + Delta + radius * cos(angle);  // x좌표
        y = -0.6 + Delta + radius * sin(angle);  // y좌표. 원의 중심(-0.5, -0.2)
        glVertex3f(x, y, 0.0);                   // 도형의 x,y좌표를 glVertex 함수를 사용해 지정
    }
    glEnd();


    glutSwapBuffers(); // 현 프레임 버퍼 변경
}

//일정 시간마다 Delta 변수를 증가 시키고 화면을 다시 그려주기 위한 함수
void MyTimer(int Value) {
    if (goup) {
        Delta = Delta + 0.001;        // Delta 값 증가
        if (Delta >= 0.2) {           // 일정 높이에 도달하면
            goup = false;             // 물체가 내려가는 중으로 변경
        }
    }
    else {
        Delta = Delta - 0.001;        // Delta 값 감소
        if (Delta <= 0.0) {           // 물체가 원래 위치에 도달하면
            goup = true;              // 물체가 올라가는 중으로 변경
        }
    }
    glutPostRedisplay();            // 그림 그려줘. 현 윈도우가 재생되어야함을 표시
    glutTimerFunc(50, MyTimer, 1);  // 다음 타이머를 예약
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                       //윈도우 초기화. 윈도우 운영체제와 세션 연결
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //디스플레이 모드 설정. RGB 컬러모드와 더블 버퍼링 모드 사용
    glutInitWindowSize(600, 600);                //윈도우 사이즈 600x600
    glutInitWindowPosition(0, 0);                //윈도우 위치 설정
    glutCreateWindow("OpenGL Drawing Rainbow");  //윈도우 생성
    glClearColor(1.0, 1.0, 1.0, 1.0);            //화면의 배경색 흰색 지정
    glMatrixMode(GL_PROJECTION);                 // 모델 뷰 행렬 선택
    glLoadIdentity();                            // 항등 행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);    //glOrtho(left, right, bottom, top, near, far); 공간 속의 일부를 관찰(촬영)하는 함수
    glutDisplayFunc(MyDisplay);                  //MyDisplay 함수를 디스플레이 콜백 함수로 등록
    glutTimerFunc(50, MyTimer, 1);               // 50ms 후에 (50ms마다 아님) 함수 호출해줘
    glutMainLoop();
    return 0;
}