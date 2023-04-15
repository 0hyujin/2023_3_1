#include <GL/glut.h>
#include <math.h>

#define PI 3.141592    // ����

GLfloat Delta = 0.0;   // Delta ������ �����ϰ� 0���� �ʱ�ȭ��
GLfloat x, y;          // x, y ��ǥ
GLfloat radius = 0.8;  // ������ 0.8

bool goup = true;      // ��ü�� �ö󰡴� ������ ���θ� ��Ÿ���� ����

void MyDisplay() {     //ȭ���� �׸��� �Լ�. ���� ���ļ� ������ó�� ���̰� ��.
    glClear(GL_COLOR_BUFFER_BIT);

    // 1�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);  //������ ������ ���������� ������
    for (float i = 0; i < 360; i++) {           // i�� �� �������� �ǹ���.
        GLfloat angle = i * PI / 180;           // angle�� ���� ����. ���� ������ ���� ������ �ٲ��ش�. 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // cos(angle)=x/������. ���� x��ǥ�� ������*cos(angle). ���⼭ angle�� ������ �ǹ���.
        y = 0.1 + Delta + radius * sin(angle);  // sin(angle)=y/������. ���� y��ǥ�� ������*sin(angle). ���⼭ angle�� ������ �ǹ���.
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();


    // 2�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0.0); //������ ������ ��Ȳ������ ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // x��ǥ
        y = 0.0 + Delta + radius * sin(angle);  // y��ǥ. ���� �߽�(-0.2, 0.0)
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 3�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0); //������ ������ ��������� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // x��ǥ
        y = -0.1 + Delta + radius * sin(angle);  // y��ǥ ���� �߽�(-0.5, 0.3)
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 4�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1, 0.0); //������ ������ �ʷϻ����� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // x��ǥ
        y = -0.2 + Delta + radius * sin(angle);  // y��ǥ ���� �߽�(-0.5, 0.2)
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 5�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); //������ ������ �Ķ������� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // x��ǥ
        y = -0.3 + Delta + radius * sin(angle);  // y��ǥ. ���� �߽�(-0.5, 0.1)
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 6�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5); //������ ������ �������� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;           // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle); // x��ǥ
        y = -0.4 + Delta + radius * sin(angle);  // y��ǥ. ���� �߽�(-0.5, 0.0)
        glVertex3f(x, y, 0.0);                  // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 7�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 1); //������ ������ ��������� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;            // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle);  // x��ǥ
        y = -0.5 + Delta + radius * sin(angle);  // y��ǥ. ���� �߽�(-0.5, -0.1)
        glVertex3f(x, y, 0.0);                   // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();

    // 8�� ��ü
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1); // ������ó�� ���̵��� ������ ������ ������� ������
    for (float i = 0; i < 360; i++) {
        GLfloat angle = i * PI / 180;            // 1�� = PI/180����
        x = -0.2 + Delta + radius * cos(angle);  // x��ǥ
        y = -0.6 + Delta + radius * sin(angle);  // y��ǥ. ���� �߽�(-0.5, -0.2)
        glVertex3f(x, y, 0.0);                   // ������ x,y��ǥ�� glVertex �Լ��� ����� ����
    }
    glEnd();


    glutSwapBuffers(); // �� ������ ���� ����
}

//���� �ð����� Delta ������ ���� ��Ű�� ȭ���� �ٽ� �׷��ֱ� ���� �Լ�
void MyTimer(int Value) {
    if (goup) {
        Delta = Delta + 0.001;        // Delta �� ����
        if (Delta >= 0.2) {           // ���� ���̿� �����ϸ�
            goup = false;             // ��ü�� �������� ������ ����
        }
    }
    else {
        Delta = Delta - 0.001;        // Delta �� ����
        if (Delta <= 0.0) {           // ��ü�� ���� ��ġ�� �����ϸ�
            goup = true;              // ��ü�� �ö󰡴� ������ ����
        }
    }
    glutPostRedisplay();            // �׸� �׷���. �� �����찡 ����Ǿ������ ǥ��
    glutTimerFunc(50, MyTimer, 1);  // ���� Ÿ�̸Ӹ� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                       //������ �ʱ�ȭ. ������ �ü���� ���� ����
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //���÷��� ��� ����. RGB �÷����� ���� ���۸� ��� ���
    glutInitWindowSize(600, 600);                //������ ������ 600x600
    glutInitWindowPosition(0, 0);                //������ ��ġ ����
    glutCreateWindow("OpenGL Drawing Rainbow");  //������ ����
    glClearColor(1.0, 1.0, 1.0, 1.0);            //ȭ���� ���� ��� ����
    glMatrixMode(GL_PROJECTION);                 // �� �� ��� ����
    glLoadIdentity();                            // �׵� ��ķ� �ʱ�ȭ
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);    //glOrtho(left, right, bottom, top, near, far); ���� ���� �Ϻθ� ����(�Կ�)�ϴ� �Լ�
    glutDisplayFunc(MyDisplay);                  //MyDisplay �Լ��� ���÷��� �ݹ� �Լ��� ���
    glutTimerFunc(50, MyTimer, 1);               // 50ms �Ŀ� (50ms���� �ƴ�) �Լ� ȣ������
    glutMainLoop();
    return 0;
}