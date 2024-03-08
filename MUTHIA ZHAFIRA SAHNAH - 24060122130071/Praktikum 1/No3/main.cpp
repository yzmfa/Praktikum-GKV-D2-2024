// Nama : Muthia Zhafira Sahnah 
// NIM : 24060122130071 
// lAB Praktikum : D2 
// TUGAS Praktikum 1 , nomer 3 



#include <GL/glut.h>

void display() {
       glClear(GL_COLOR_BUFFER_BIT);
    
    //PERSEGI 1 
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(-0.3f, -0.1f); // bawah kiri
    glVertex2f(-0.15f, -0.1f);// bawah kanan
    glVertex2f(-0.15f, 0.1f); //atas kanan
    glVertex2f(-0.3f, 0.1f); // atas kiri 
    glEnd();

    // Gambar outline
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.3f, -0.1f); // bawah kiri
    glVertex2f(-0.15f, -0.1f);// bawah kanan
    glVertex2f(-0.15f, 0.1f); //atas kanan
    glVertex2f(-0.3f, 0.1f); // atas kiri 
    glEnd();
    
    
    //PERSEGI 2
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(-0.09f, -0.1f); // bawah kiri
    glVertex2f(0.09f, -0.1f); // bawah kanan
    glVertex2f(0.09f, 0.1f); //atas kanan
    glVertex2f(-0.09f, 0.1f); // atas kiri 
    glEnd();

    // Gambar outline
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.09f, -0.1f); // bawah kiri
    glVertex2f(0.09f, -0.1f); // bawah kanan
    glVertex2f(0.09f, 0.1f); //atas kanan
    glVertex2f(-0.09f, 0.1f); // atas kiri 
    glEnd();
    
    //PERSEGI 3
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(0.15f, -0.1f); // bawah kiri
    glVertex2f(0.3f, -0.1f); // bawah kanan
    glVertex2f(0.3f, 0.1f); //atas kanan
    glVertex2f(0.15f, 0.1f); // atas kiri 
    glEnd();

    // Gambar outline 
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(0.15f, -0.1f); // bawah kiri
    glVertex2f(0.3f, -0.1f); // bawah kanan
    glVertex2f(0.3f, 0.1f); //atas kanan
    glVertex2f(0.15f, 0.1f); // atas kiri  
    glEnd();
    
    //PERSEGI 4
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(-0.2f, 0.1f); // bawah kiri
    glVertex2f(-0.05f, 0.1f);// bawah kanan
    glVertex2f(-0.05f, 0.3f); //atas kanan
    glVertex2f(-0.2f, 0.3f); // atas kiri 
    glEnd();

    // Gambar outline 
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.2f, 0.1f); // bawah kiri
    glVertex2f(-0.05f, 0.1f);// bawah kanan
    glVertex2f(-0.05f, 0.3f); //atas kanan
    glVertex2f(-0.2f, 0.3f); // atas kiri 
    glEnd();
    
    //PERSEGI 5
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(0.05f, 0.1f); // bawah kiri
    glVertex2f(0.2f, 0.1f);// bawah kanan
    glVertex2f(0.2f, 0.3f); //atas kanan
    glVertex2f(0.05f, 0.3f); // atas kiri 
    glEnd();

    // Gambar outline 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(0.05f, 0.1f); // bawah kiri
    glVertex2f(0.2f, 0.1f);// bawah kanan
    glVertex2f(0.2f, 0.3f); //atas kanan
    glVertex2f(0.05f, 0.3f); // atas kiri 
    glEnd();
    
    // PERSEGI 6
    glBegin(GL_QUADS);
    glColor3f(1.5f, 0.0f, 0.5f); // pink
    glVertex2f(-0.1f, 0.3f); // bawah kiri
    glVertex2f(0.1f, 0.3f);// bawah kanan
    glVertex2f(0.1f, 0.5f); //atas kanan
    glVertex2f(-0.1f, 0.5f); // atas kiri 
    glEnd();

    // Gambar outline 
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.1f, 0.3f); // bawah kiri
    glVertex2f(0.1f, 0.3f);// bawah kanan
    glVertex2f(0.1f, 0.5f); //atas kanan
    glVertex2f(-0.1f, 0.5f); // atas kiri 
	glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // Buat ukuran jendela nya
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // entahlah mandatory ajah 
    glutCreateWindow("piramida kubus"); //Ini buat judul di jendelanya
    glutDisplayFunc(display); // ini buat manggil fungsi yang kamu buat diatas
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // warna background jendela
    glutMainLoop(); // ini biar jalan terus kecuali kamu close 
    return 0;
    return 0;
}
