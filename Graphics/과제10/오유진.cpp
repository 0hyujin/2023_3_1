#include <GL/glut.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define DEFAULT 0.0

float jump = 0;  //1���� ������ �������� ����
float angle = 0;
float Delta = 0; //2���� ������ �������� ����� �̵�
float t = 0;
GLUquadricObj* cyl;

// �������� ����� �ʱ� ��ġ
float dog_x = -0.6;
float dog_y = -0.5;
float apple_x = 0.0f;  // w,a,s,d�� ���� ����� ������ �Ӹ��� ������ �����
float apple_y = -0.6f;

// ����� ũ��
float apple_radius = 0.08;

int col = 0;    // ���¸� �����ϴ� ��������

static GLfloat ear = DEFAULT;     // ��
static GLfloat tail = DEFAULT;     // ����
int incEar = TRUE;        // ���� ���� ����/���� Ȯ�� ����
int incTail = TRUE;       // ������ ���� ����/���� Ȯ�� ����

void MyTimer(int Value) {
    t = t + 2.0f;
    if (col == 2)
        Delta = Delta + 0.0001;          // Delta �� ����

    if (incEar) {               // �ʹ� -10~10 ������ �������� ȸ����.
        ear += 0.02;
        if (ear >= 10)        incEar = FALSE;
    }
    else {
        ear -= 0.02;
        if (ear <= -10)    incEar = TRUE;
    }
    if (incTail) {               // ������ -10~10 ������ �������� ȸ����.
        tail += 0.05;
        if (tail >= 10)        incTail = FALSE;
    }
    else {
        tail -= 0.05;
        if (tail <= -10)    incTail = TRUE;
    }
    angle += 0.5;
    if (angle > 360.0) {
        angle -= 360.0;        // ������ ����
    }
    jump = sin(angle * 3.14 / 180) / 10.0;

    glutPostRedisplay();
    glutTimerFunc(1, MyTimer, 1);  // ���� Ÿ�̸Ӹ� ����
}
// �浹 ���� �Լ�
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

    //////////////////�ܵ�///////////////////////
    glPushMatrix();
    glRotatef(10, 1, 0, 0);
    glRotatef(-10, 0, 1, 0);
    glColor3f(0.4, 0.7, 0.4);
    glScalef(7, 0.3, 7);
    glTranslatef(0.1, -2, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    //////////////////��///////////////////////
    glPushMatrix();
    glRotatef(10, 1, 0, 0);
    glRotatef(-10, 0, 1, 0);
    glColor3f(0.6, 0.6, 0.3);
    glScalef(2, 0.3, 7);
    glTranslatef(0.1, -2, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    /////////////////////���/////////////////////
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(apple_x, apple_y, 0);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    // �浹 ���� �� ó��
    if (check_collision()) {
        apple_x = 2.0f;  // �浹 �� ����� �̵����Ѽ� ������ �ʵ��� ��
        apple_y = 2.0f;
    }

    ////////////////////���/////////////////////////
    // ��
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    if (col == 2)
        glTranslatef(0.25, 0.55 - Delta, 0.0 + Delta);
    else
        glTranslatef(0.25, 0.55, 0);
    glutSolidSphere(0.1, 20, 20);

    //��
    glPushMatrix();
    glRotatef(-90, 1, 0, 0); // -90
    glTranslatef(0.0, 0.0, -0.15);
    gluCylinder(cyl, 0.05, 0.03, 0.05, 5, 5);
    glPopMatrix();
    glPopMatrix();



    // 1. ����
    glPushMatrix();
    glColor3f(0, 0, 1);
    if (col == 2)
        //glTranslatef(-0.3, -0.55 + Delta, 0);
        glTranslatef(0.25, 0 - Delta, 0.0 + Delta);
    else
        glTranslatef(0.25, 0, 0.0);
    glRotatef(-90, 1, 0, 0); // -90
    // Cynliner�� +z�������� �������.
    gluCylinder(cyl, 0.2, 0.1, 0.4, 30, 30); // ������, ������, ������, ����


    // 2. ��1
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(0.15, 0.0, 0.4);
    glutWireSphere(0.05, 20, 20);
    //glRotatef( t*0.01, 1, 0, 0);
    glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //�Ȳ�ġ�� �ȶ�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 - 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    // ��
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.06, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    // 3. ��2
    glPushMatrix();
    glTranslatef(-0.15, 0.0, 0.4);
    glutWireSphere(0.05, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //�Ȳ�ġ�� �ȶ�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 - 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    // ��
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.06, 20, 20);
    glPopMatrix();

    glPopMatrix();



    glPopMatrix();

    // �ٸ�1
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(-0.12, 0.0, 0.0);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //������ �����
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 + 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.25, 20, 1);

    // ��


    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0.0, 0.05, 0.25);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.13, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    // �ٸ�2
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6);
    glTranslatef(0.12, 0.0, 0.0);
    glutWireSphere(0.05, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 180, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 20, 1);

    //������ �����
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.2);
    glutWireSphere(0.05, 20, 20);
    glRotatef(sin(t * 0.001) * 45 + 45, 1, 0, 0);
    gluCylinder(cyl, 0.05, 0.05, 0.25, 20, 1);

    // ��
    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0.0, 0.05, 0.25);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.13, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    glPopMatrix(); // ���� ��

    ////////////////////////������///////////////////////////

    // ������ ��
    glPushMatrix();
    glColor3f(0.5, 0.3, 0.0);

    if (col == 1)
        glTranslatef(-0.6, -0.5 + jump, 0);
    else if (col == 2)
        glTranslatef(-0.6, -0.5 - Delta, 0 + Delta);
    else
        glTranslatef(dog_x, dog_y, 0);

    glutWireSphere(0.1, 20, 20);

    // ������ ��1
    glPushMatrix();
    glTranslatef(0.1, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(ear, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.1, 20, 20);
    glPopMatrix();
    // ������ ��2
    glPushMatrix();
    glTranslatef(0.26, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(ear, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.1, 20, 20);
    glPopMatrix();

    // ������ ��
    glPushMatrix();
    glRotatef(-45, 1, 0, 0); // -90
    glTranslatef(0.1, -0.1, 0);
    gluCylinder(cyl, 0.05, 0.03, 0.07, 5, 5);
    glPopMatrix();

    // ������ ����
    glPushMatrix();

    glColor3f(0.5, 0.3, 0.0);
    glTranslatef(-0.1, -0.25, -1);
    gluCylinder(cyl, 0.08, 0.08, 0.5, 20, 30);


    // 2. �մٸ�
    glPushMatrix();
    //glColor3f(0.8, 0.6, 0.4);
    glColor3f(0.5, 0.3, 0.0);
    glTranslatef(0.04, -0.1, 0.4);
    glutWireSphere(0.03, 20, 20);
    //glRotatef( t*0.01, 1, 0, 0);
    glRotatef(sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);
    // �չ�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();


    glPopMatrix();

    // 3. �մٸ�2
    glPushMatrix();
    glTranslatef(-0.1, -0.1, 0.4);
    glutWireSphere(0.03, 20, 20);
    glRotatef(sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);

    // �չ�
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();

    glPopMatrix();

    // �޴ٸ�
    glPushMatrix();
    glTranslatef(-0.09, -0.1, -0.1);
    glutWireSphere(0.03, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);

    // �޹�1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();

    glPopMatrix();

    // �޴ٸ�2
    glPushMatrix();
    glTranslatef(0.02, -0.1, -0.1);
    glutWireSphere(0.03, 20, 20);
    glRotatef(-sin(t * 0.001) * 60 + 100, 1, 0, 0);
    gluCylinder(cyl, 0.03, 0.03, 0.15, 20, 1);
    // �޹�2
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glutWireSphere(0.04, 20, 20);
    glPopMatrix();
    glPopMatrix();

    //����
    glPushMatrix();
    glTranslatef(0.2, 0.2, 0.4);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(tail, 0.0, 0.0, 1.0);
    glScalef(0.4, 1.0, 0.3);
    glutWireSphere(0.05, 20, 20);
    glPopMatrix();

    glPopMatrix(); // ���� ��

    glPopMatrix(); // ������ �� ��



    glPopMatrix(); // ������ ��

    glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
        case '1':
            col = 1;  // ������ ����
            glutPostRedisplay();
            break;
        case '2':
            col = 2;  // ��� �̵�
            glutPostRedisplay();
            break;
        case '3':
            col = 3;  // ������� �̵�
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
        case 27:  // 'esc' Ű�� �ƽ�Ű �ڵ� ��
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
    //Ű���� ������ ���� �Լ� ȣ�� ���~
    glutKeyboardFunc(MyKeyboard);

    glutTimerFunc(1, MyTimer, 1);
    glutMainLoop();
    return 0;
}