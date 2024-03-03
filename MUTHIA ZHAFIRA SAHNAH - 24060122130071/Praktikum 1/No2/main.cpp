// Nama : Muthia Zhafira Sahnah 
// NIM : 24060122130071 
// lAB Praktikum : D2 
// TUGAS Praktikum 1 , nomer 2 

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Langit 
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0); 
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0, -0.4);
    glVertex2f(1.0, -0.4);
    glVertex2f(1.0, 1.0);
    glEnd();
    
    // Tanah
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.6, 0.3); 
    glVertex2f(-1.0, -0.4);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, -0.4);
    glEnd();
    
   // Jalan
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5, 0.5, 0.5); 
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glVertex2f(0.3, -0.6);
    glVertex2f(-0.3, -0.6);
    glVertex2f(0.2, -0.8);
    glVertex2f(-0.2, -0.8);
    glVertex2f(0.3, -1.0);
    glVertex2f(-0.2, -1.0);
    glEnd();
    

	// Kerangka rumah 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0); 
    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.4, 0.4);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.4, -0.4);
    glEnd();
    
    // Gambar outline 
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.4, 0.4);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.4, -0.4);
    glEnd();
    
    // Pintu  
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.0); 
    glVertex2f(-0.15, -0.4);
    glVertex2f(-0.15, 0.0);
    glVertex2f(0.15, 0.0);
    glVertex2f(0.15, -0.4);
    glEnd();
    
     // Gambar outline 
    glBegin(GL_LINE_LOOP); 
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(-0.15, -0.4);
    glVertex2f(-0.15, 0.0);
    glVertex2f(0.15, 0.0);
    glVertex2f(0.15, -0.4);
    glEnd();
    
    // 2 Jendela 
    glBegin(GL_LINE_STRIP);
    glLineWidth(50.0);
    glColor3f(0.0, 0.0, 0.0); 
    glVertex2f(-0.35, 0.2);
    glVertex2f(-0.35, 0.35);
    glVertex2f(-0.2, 0.35);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.35, 0.2);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glLineWidth(50.0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.35, 0.2);
    glVertex2f(0.35, 0.35);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.35, 0.2);
    glEnd();
    
    // Atap
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.2, 0.5); // Merah tua
    glVertex2f(0.0, 0.8); // Puncak atap
    glVertex2f(-0.5, 0.4);
    glVertex2f(0.5, 0.4);
    glEnd();
    
      // Gambar outline 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glVertex2f(0.0, 0.8); // Puncak atap
    glVertex2f(-0.5, 0.4);
    glVertex2f(0.5, 0.4);
    glEnd();
    
    // Pot kanan
    glBegin(GL_LINE_LOOP);
    glLineWidth(10.0);
    glColor3f(0.5, 0.3, 0.1); // Coklat
    glVertex2f(0.7, -0.4);
    glVertex2f(0.7, -0.6);
    glVertex2f(0.8, -0.6);
    glVertex2f(0.8, -0.4);
    glEnd();
    
    // tangkai kanan
    glBegin(GL_LINE_STRIP);
    glLineWidth(10.0);
    glColor3f(0.0, 0.6, 0.0); // Hijau
    glVertex2f(0.75, -0.6);
    glVertex2f(0.75, -0.2);
    glEnd();
    
    // bunga kanan
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 1.0); // 
    glVertex2f(0.7, -0.2); // Puncak bunga
    glVertex2f(0.75, -0.1);
    glVertex2f(0.8, -0.2);
    glEnd();
    
    // pot kiri
    glBegin(GL_LINE_LOOP);
    glLineWidth(10.0);
    glColor3f(0.5, 0.3, 0.1); // Coklat
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.7, -0.6);
    glVertex2f(-0.8, -0.6);
    glVertex2f(-0.8, -0.4);
    glEnd();
    
    // tangkai kiri
    glBegin(GL_LINE_STRIP);
    glLineWidth(10.0);
    glColor3f(0.0, 0.6, 0.0); // Hijau
    glVertex2f(-0.75, -0.6);
    glVertex2f(-0.75, -0.2);
    glEnd();
    
    // bunga kanan
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 1.0); // Merah
    glVertex2f(-0.7, -0.2); // Puncak bunga
    glVertex2f(-0.75, -0.1);
    glVertex2f(-0.8, -0.2);
    glEnd();

    glFlush();
    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Tugas No 2 Praktikum GKV 1 Muthia");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna latar belakang putih
    glutMainLoop();
    return 0;
}

