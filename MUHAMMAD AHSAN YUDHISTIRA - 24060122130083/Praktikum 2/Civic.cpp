/*  Nama    	: Muhammad Ahsan Yudhistira
    NIM     	: 24060122130083
    Deskripsi 	: Membuat Gambar Mobil dengan memanfaatkan object2 primitif dan transformasi
*/
#include <gl/glut.h>
#include <cmath>

float carX = 0.0f;
float carY = 0.0f;

void drawCar() {
    // Body Mobil
    glBegin(GL_POLYGON);
    glColor3ub(70, 120, 180);
    glVertex2f(-0.6, -0.35);
    glColor3ub(100, 100, 200);
    glVertex2f(-0.6, 0);
    glColor3ub(70, 120, 180);
    glVertex2f(-0.2, 0.2);
    glColor3ub(120, 90, 90);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.6, 0);
    glColor3ub(100, 100, 200);
    glVertex2f(0.9, -0.1);
    glVertex2f(0.9, -0.35);
    glEnd();

    // Jendela belakang
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.2, 0.15);
    glVertex2f(0.02, 0.15);
    glVertex2f(0.02, 0);
    glVertex2f(-0.2, 0);
    glEnd();

    // Jendela depan
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.03, 0.15);
    glVertex2f(0.3, 0.15);
    glVertex2f(0.5, 0);
    glVertex2f(0.03, 0);
    glEnd();

    // Ban kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 244, 0);
    for (int i = 0; i < 360; i++) {
        float rad = i * 3.14159 / 180;
        glVertex2f(-0.4 + 0.1 * cos(rad), -0.35 + 0.1 * sin(rad));
    }
    glEnd();

    // Ban kanan
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 244, 0);
    for (int i = 0; i < 360; i++) {
        float rad = i * 3.14159 / 180;
        glVertex2f(0.7 + 0.1 * cos(rad), -0.35 + 0.1 * sin(rad));
    }
    glEnd();
}

void civic() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5.0f);

    // Menggunakan stack untuk mengelompokkan transformasi mobil
    glPushMatrix();
    glTranslatef(carX, carY, 0.0f); // Translasi berdasarkan posisi mobil

    drawCar();

    glPopMatrix();

    glFlush();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        carX += 0.1f; // Gerak ke kanan
        break;
    case GLUT_KEY_LEFT:
        carX -= 0.1f; // Gerak ke kiri
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Honda Civic");
    glutDisplayFunc(civic);
    glutSpecialFunc(specialKeys);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
    return 0;
}
