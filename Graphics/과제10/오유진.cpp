#include <GL/glut.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define DEFAULT 0.0

float jump = 0;  //1번을 누르면 강아지가 점프
float angle = 0;
float Delta = 0; //2번을 누르면 강아지와 사람이 이동
float t = 0;
GLUquadricObj* cyl;

// 강아지와 사과의 초기 위치
float dog_x = -0.6;
float dog_y = -0.5;
float apple_x = 0.0f;  // w,a,s,d를 눌러 사과에 강아지 머리가 닿으면 사라짐
float apple_y = -0.6f;

// 사과의 크기
float apple_radius = 0.08;

int col = 0;    // 상태를 저장하는 전역변수

static GLfloat ear = DEFAULT;     // 귀
static GLfloat tail = DEFAULT;     // 꼬리
int incEar = TRUE;        // 귀의 각도 증가/감소 확인 변수
int incTail = TRUE;       // 꼬리의 각도 증가/감소 확인 변수

void MyTimer(int Value) {
    t = t + 2.0f;
    if (col == 2)
        Delta = Delta + 0.0001;          // Delta 값 증가

    if (incEar) {               // 귀는 -10~10 사이의 각도에서 회전함.
        ear += 0.02;
        if (ear >= 10)        incEar = FALSE;
    }
    else {
        ear -= 0.02;
        if (ear <= -10)    incEar = TRUE;
    }
    if (incTail) {               // 꼬리는 -10~10 사이의 각도에서 회전함.
        tail += 0.05;
        if (tail >= 10)        incTail = FALSE;
    }
    else {
        tail -= 0.05;
        if (tail <= -10)    incTail = TRUE;
    }
    angle += 0.5;
    if (angle > 360.0) {
        angle -= 360.0;        // 강아지 점프
    }
    jump = sin(angle * 3.14 / 180) / 10.0;

    glutPostRedisplay();
    glutTimerFunc(1, MyTimer, 1);  // 다음 타이머를 예약
}
// 충돌 감지 함수
bool check_collision() {
    float distance = sqrt(pow(dog_x - apple_x, 2) + pow(dog_y - apple_y, 2));
    if (distance < apple_radius)
        return true;
    else
        return false;  
}
void MyDisplay() {
    cyl = gluNewQuadric();
    gluQuadricDrawStyle(cyl, GLU_LINE);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    //////////////////잔디///////////////////////
    glPushMatrix();
    glRotatef(10, 1, 0, 0);
    glRotatef(-10, 0, 1, 0);
    glColor3f(0.4, 0.7, 0.4);
    glScalef(7, 0.3, 7);
    glTranslatef(0.1, -2, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    //////////////////길///////////////////////
    glPushMatrix();
    glRotatef(10, 1, 0, 0);
    glRotatef(-10, 0, 1, 0);
    glColor3f(0.6, 0.6, 0.3);
    glScalef(2, 0.3, 7);
    glTranslatef(0.1, -2, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    /////////////////////사과/////////////////////
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(apple_x, apple_y, 0);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    // 충돌 감지 및 처리
    if (check_collision()) {
        apple_x = 2.0f;  // 충돌 시 사과를 이동시켜서 보이지 않도록 함
        apple_y = 2.0f;
    }

    ////////////////////사람/////////////////////////
    // 얼굴
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    if (col == 2)
        glTranslatef(0.25, 0.55 - Delta, 0.0 + Delta);
    else
        glTranslatef(0.25, 0.55, 0);
    glutSolidSphere(0.1, 20, 20);

    //목
    glPushMatrix();
    glRotatef(-90, 1, 0, 0); // -90
    glTranslatef(0.0, 0.0, -0.15);
    gluCylinder(cyl, 0.05, 0.03, 0.05, 5, 5);
    glPopMatrix();
    glPopMatrix();



    // 1. 몸통
    glPushMatrix();
    glColor3f(0, 0, 1);
    if (col == 2)
        //glTranslatef(-0.3, -0.55 + Delta, 0);
        glTranslatef(0.25, 0 - Delta, 0.0 + Delta);
    else
        glTranslatef(0.25, 0, 0.0);
    glRotatef(-90, 1, 0, 0); // -90
    // Cynliner는 +z방향으로 길어진다.
    gluCylinder(cyl, 0.2, 0.1, 0.4, 30, 30); // 포인터, 반지름, 반지름, 높이


    // 2. 팔1
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(0.15, 0.0, 0.4);
    glutWireSphere(0.05, 20, 20);
    //glRotatef( t*0.01, 1, 0, 0);
    glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //팔꿈치와 팔뚝
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 - 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    // 손
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.06, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    // 3. 팔2
    glPushMatrix();
    glTranslatef(-0.15, 0.0, 0.4);
    glutWireSphere(0.05, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //팔꿈치와 팔뚝
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 - 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    // 손
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.06, 20, 20);
    glPopMatrix();

    glPopMatrix();



    glPopMatrix();

    // 다리1
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(-0.12, 0.0, 0.0);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //무릎과 허벅지
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 + 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.25, 20, 1);

    // 발


    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0.0, 0.05, 0.25);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.13, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    // 다리2
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(0.12, 0.0, 0.0);
    glutWireSphere(0.05, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //무릎과 허벅지
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 + 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.25, 20, 1);

    // 발
    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0.0, 0.05, 0.25);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.13, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    glPopMatrix(); // 몸통 끝

    ////////////////////////강아지///////////////////////////

    // 강아지 얼굴
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.0);

    if (col == 1)
        glTranslatef(-0.6, -0.5 + jump, 0);
    else if (col == 2)
        glTranslatef(-0.6, -0.5 - Delta, 0 + Delta);
    else
        glTranslatef(dog_x, dog_y, 0);

    glutWireSphere(0.1, 20, 20);

    // 강아지 귀1
    glPushMatrix();
    glTranslatef(0.1, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(ear, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.1, 20, 20);
    glPopMatrix();
    // 강아지 귀2
    glPushMatrix();
    glTranslatef(0.26, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(ear, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.1, 20, 20);
    glPopMatrix();

    // 강아지 목
    glPushMatrix();
    glRotatef(-45, 1, 0, 0); // -90
    glTranslatef(0.1, -0.1, 0);
    gluCylinder(cyl, 0.05, 0.03, 0.07, 5, 5);
    glPopMatrix();

    // 강아지 몸통
    glPushMatrix();

    glColor3f(0.5, 0.3, 0.0);
    glTranslatef(-0.1, -0.25, -1);
    gluCylinder(cyl, 0.08, 0.08, 0.5, 20, 30);


    // 2. 앞다리
    glPushMatrix();
    //glColor3f(0.8, 0.6, 0.4);
    glColor3f(0.5, 0.3, 0.0);
    glTranslatef(0.04, -0.1, 0.4);
    glutWireSphere(0.03, 20, 20);
    //glRotatef( t*0.01, 1, 0, 0);
    glRotatef(sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);
    // 앞발
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();


    glPopMatrix();

    // 3. 앞다리2
    glPushMatrix();
    glTranslatef(-0.1, -0.1, 0.4);
    glutWireSphere(0.03, 20, 20);
    glRotatef(sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);

    // 앞발
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();

    glPopMatrix();

    // 뒷다리
    glPushMatrix();
    glTranslatef(-0.09, -0.1, -0.1);
    glutWireSphere(0.03, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);

    // 뒷발1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();

    glPopMatrix();

    // 뒷다리2
    glPushMatrix();
    glTranslatef(0.02, -0.1, -0.1);
    glutWireSphere(0.03, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);
    // 뒷발2
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();
    glPopMatrix();

    //꼬리
    glPushMatrix();
    glTranslatef(0.2, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(tail, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.05, 20, 20);
    glPopMatrix();

    glPopMatrix(); // 몸통 끝

    glPopMatrix(); // 강아지 얼굴 끝



    glPopMatrix(); // 강아지 끝

    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
        case '1':
            col = 1;  // 강아지 점프
            glutPostRedisplay();
            break;
        case '2':
            col = 2;  // 사람 이동
            glutPostRedisplay();
            break;
        case '3':
            col = 3;  // 원래대로 이동
            glutPostRedisplay();
            break;
        case 'w':
        case 'W':
            dog_y += 0.1f;
            break;
        case 's':
        case 'S':
            dog_y -= 0.1f;
            break;
        case 'a':
        case 'A':
            dog_x -= 0.1f;
            break;
        case 'd':
        case 'D':
            dog_x += 0.1f;
            break;
    
        case 'Q':
        case 'q':
        case 27:  // 'esc' 키의 아스키 코드 값
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Walking Person and Dog");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20, 1, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.5, 0.6, 5.2, 0, 0, 0, 0, 1, 0);

    glutDisplayFunc(MyDisplay);
    //키보드 눌리면 다음 함수 호출 약속~
    glutKeyboardFunc(MyKeyboard);

    glutTimerFunc(1, MyTimer, 1);
    glutMainLoop();
    return 0;
}