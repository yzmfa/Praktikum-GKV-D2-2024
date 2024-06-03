#include <GL/glut.h>
#include <cmath>
#include <sstream>

// Variabel untuk posisi mobil
float carX = 0.0f;
float carZ = 0.0f;
static int carAngle = 0.0f;
float wheelAngle = 0.0f;
static int cameraY = 0;
static int  cameraX = 0;
int distanceTravel = 0;
float speed = 0.1f;
bool gameOver = false;
bool cameraBehind = true;
bool cameraLeft = false;   
bool cameraRight = false;  
bool cameraAbove = false;

GLfloat lightPosition[] = { 5.0f, 10.0f, 5.0f, 1.0f };


// Fungsi untuk menginisialisasi OpenGL
void init() {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // Warna langit
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    // Pengaturan pencahayaan
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightPosition[] = { 0.0f, 10.0f, 10.0f, 1.0f };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

// Fungsi untuk menggambar mobil dengan detail tambahan
void drawCar() {
    glPushMatrix();
	    glTranslatef(carX, 0.5f, carZ);
	    glRotatef(carAngle, 0.0f, 1.0f, 0.0f);
	
	    // Body Bawah
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 1.0f);
		    glScalef(1.6f, 0.1f, 3.1f); 
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    glPushMatrix();
		    glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(0.0f, 0.1f, -1.0f);
		    glScalef(0.6f, 0.3f, 1.05f); 
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    // Main Body
		glPushMatrix();
		    glColor3f(1.0f, 0.0f, 0.0f);
		    glTranslatef(0.0f, 0.3f, 0.0f);
		    glScalef(1.5f, 0.6f, 3.0f); 
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    // Roof
	    glPushMatrix();
		    glColor3f(1.0f, 0.0f, 0.0f);
		    glTranslatef(0.0f, 0.7f, 0.0f);
		    glScalef(1.4f, 1.1f, 1.5f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    // Kaca Depan Belakang
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 0.0f);
		    glTranslatef(0.0f, 0.7f, 0.0f);
		    glScalef(1.3f, 0.9f, 1.55f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    // Kaca Samping
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 0.0f);
		    glTranslatef(0.0f, 0.7f, 0.35f);
		    glScalef(1.48f, 0.9f, 0.6f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 0.0f);
		    glTranslatef(0.0f, 0.7f, -0.38f);
		    glScalef(1.48f, 0.9f, 0.6f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    // Lampu
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 1.0f);
		    glTranslatef(-0.55f, 0.5f, 0.0f);
		    glScalef(0.3f, 0.15f, 3.1f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 1.0f);
		    glTranslatef(0.55f, 0.5f, 0.0f);
		    glScalef(0.3f, 0.15f, 3.1f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
		//Knalpot
		glPushMatrix();
			glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(0.55f, -0.1f, 0.25f);
		    glScalef(0.2f, 0.2f, 2.8f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	
	    // Roda Belakang 
	    glPushMatrix();
		    glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(0.66f, 0.0f, 0.8f);
		    glScalef(0.3f, 0.7f, 0.7f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    glPushMatrix();
		    glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(-0.66f, 0.0f, 0.8f);
		    glScalef(0.3f, 0.7f, 0.7f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    //Velg Belakang
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 1.0f);
		    glTranslatef(0.0f, 0.0f, 0.8f);
		    glScalef(1.7f, 0.3f, 0.3f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	
	    // Roda Depan
	    glPushMatrix();
		    glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(0.66f, 0.0f, -0.8f);
		    glScalef(0.3f, 0.7f, 0.7f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	
	    glPushMatrix();
		    glColor3f(0.0f, 0.0f, 0.0f);
		    glTranslatef(-0.66f, 0.0f, -0.8f);
		    glScalef(0.3f, 0.7f, 0.7f);
		    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    //Velg Depan
	    glPushMatrix();
		    glColor3f(1.0f, 1.0f, 1.0f);
		    glTranslatef(0.0f, 0.0f, -0.8f);
		    glScalef(1.7f, 0.3f, 0.3f);
		    glutSolidCube(1.0);
	    glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar rumah pertama
void drawHouse1(float x, float z, bool left) {
    glPushMatrix();
        glTranslatef(x, 0.0f, z);
        // Lantai dasar rumah
        glColor3f(0.8f, 0.8f, 0.8f); 
        glPushMatrix();
            glScalef(2.0f, 0.1f, 3.0f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Bangunan utama rumah
        glColor3f(0.6f, 0.4f, 0.2f);
        glPushMatrix();
            glTranslatef(0.0f, 1.0f, 0.0f);
            glScalef(1.5f, 2.0f, 2.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Atap rumah
        glColor3f(0.3f, 0.5f, 0.8f);
        glPushMatrix();
            glTranslatef(0.0f, 2.0f, 0.0f);
            glBegin(GL_TRIANGLES);
                // Atap kiri
                glVertex3f(-0.75f, 0.0f, 1.25f);  
                glVertex3f(0.75f, 0.0f, 1.25f);   
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap kanan
                glVertex3f(-0.75f, 0.0f, -1.25f); 
                glVertex3f(0.75f, 0.0f, -1.25f);  
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap belakang
                glVertex3f(-0.75f, 0.0f, 1.25f);  
                glVertex3f(-0.75f, 0.0f, -1.25f); 
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap depan
                glVertex3f(0.75f, 0.0f, 1.25f);   
                glVertex3f(0.75f, 0.0f, -1.25f);  
                glVertex3f(0.0f, 0.75f, 0.0f);    
            glEnd();
        glPopMatrix();

        // Jendela rumah
        if (left){
        	glRotatef(90, 0, 1, 0);
        } else {
        	glRotatef(-90, 0, 1, 0);	
        }
        glColor3f(0.2f, 0.2f, 0.7f);
        float windowWidth = 0.3f;
        float windowHeight = 0.4f;
        for (int i = 0; i < 2; i++) { 
            for (int j = -1; j <= 1; j += 2) { 
                glPushMatrix();
                    glTranslatef(j * 0.75f, 0.7f + i * 1.0f, 0.76f);
                    glScalef(windowWidth, windowHeight, 0.05f);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Pintu rumah
        glColor3f(0.5f, 0.35f, 0.05f); 
        glPushMatrix();
            glTranslatef(0.0f, 0.25f, 0.76f);
            glScalef(0.5f, 1.0f, 0.05f);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar rumah kedua
void drawHouse2(float x, float z, bool left) {
    glPushMatrix();
        glTranslatef(x, 0.0f, z);
        // Lantai dasar rumah
        glColor3f(0.8f, 0.8f, 0.8f); 
        glPushMatrix();
            glScalef(2.0f, 0.1f, 3.0f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Bangunan utama rumah
        glColor3f(0.6f, 1.0f, 0.2f);
        glPushMatrix();
            glTranslatef(0.0f, 1.0f, 0.0f);
            glScalef(1.5f, 2.0f, 2.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Atap rumah
        glColor3f(1.5f, 0.2f, 0.2f);
        glPushMatrix();
            glTranslatef(0.0f, 2.0f, 0.0f);
            glBegin(GL_TRIANGLES);
                // Atap kiri
                glVertex3f(-0.75f, 0.0f, 1.25f);  
                glVertex3f(0.75f, 0.0f, 1.25f);   
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap kanan
                glVertex3f(-0.75f, 0.0f, -1.25f); 
                glVertex3f(0.75f, 0.0f, -1.25f);  
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap belakang
                glVertex3f(-0.75f, 0.0f, 1.25f);  
                glVertex3f(-0.75f, 0.0f, -1.25f); 
                glVertex3f(0.0f, 0.75f, 0.0f);    

                // Atap depan
                glVertex3f(0.75f, 0.0f, 1.25f);   
                glVertex3f(0.75f, 0.0f, -1.25f);  
                glVertex3f(0.0f, 0.75f, 0.0f);    
            glEnd();
        glPopMatrix();

        // Jendela rumah
        if (left){
        	glRotatef(90, 0, 1, 0);
        } else {
        	glRotatef(-90, 0, 1, 0);	
        }
        glColor3f(0.2f, 0.2f, 0.7f); 
        float windowWidth = 0.3f;
        float windowHeight = 0.4f;
        for (int i = 0; i < 2; i++) { 
            for (int j = -1; j <= 1; j += 2) { 
                glPushMatrix();
                    glTranslatef(j * 0.75f, 0.7f + i * 1.0f, 0.76f);
                    glScalef(windowWidth, windowHeight, 0.05f);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Pintu rumah
        glColor3f(0.5f, 0.35f, 0.05f);
        glPushMatrix();
            glTranslatef(0.0f, 0.25f, 0.76f);
            glScalef(0.5f, 1.0f, 0.05f);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar rumah ketiga
void drawHouse3(float x, float z, bool left) {
    glPushMatrix();
        glTranslatef(x, 0.0f, z);
        // Lantai dasar rumah
        glColor3f(0.8f, 0.8f, 0.8f); 
        glPushMatrix();
            glScalef(2.0f, 0.1f, 2.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Bangunan utama rumah
        glColor3f(0.68f, 0.85f, 0.90f);
        glPushMatrix();
            glTranslatef(0.0f, 1.5f, 0.0f);
            glScalef(1.5f, 3.0f, 2.0f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Atap rumah
        glColor3f(0.5f, 0.5f, 0.5f);
        glPushMatrix();
            glTranslatef(0.0f, 3.0f, 0.0f);
            glBegin(GL_TRIANGLES);
                // Atap kiri
                glVertex3f(-0.75f, 0.0f, 1.0f);
                glVertex3f(0.75f, 0.0f, 1.0f);
                glVertex3f(0.0f, 0.75f, 0.0f);

                // Atap kanan
                glVertex3f(-0.75f, 0.0f, -1.0f);
                glVertex3f(0.75f, 0.0f, -1.0f);
                glVertex3f(0.0f, 0.75f, 0.0f);

                // Atap belakang
                glVertex3f(-0.75f, 0.0f, 1.0f);
                glVertex3f(-0.75f, 0.0f, -1.0f);
                glVertex3f(0.0f, 0.75f, 0.0f);

                // Atap depan
                glVertex3f(0.75f, 0.0f, 1.0f);
                glVertex3f(0.75f, 0.0f, -1.0f);
                glVertex3f(0.0f, 0.75f, 0.0f);    
            glEnd();
        glPopMatrix();

        // Jendela rumah
        if (left){
        	glRotatef(90, 0, 1, 0);
        } else {
        	glRotatef(-90, 0, 1, 0);	
        }
        glColor3f(0.2f, 0.2f, 0.7f); 
        float windowWidth = 0.3f;
        float windowHeight = 0.4f;
        for (int i = 0; i < 2; i++) { 
            for (int j = -1; j <= 1; j += 2) { 
                glPushMatrix();
                    glTranslatef(j * 0.6f, 0.9f + i, 0.76f);
                    glScalef(windowWidth, windowHeight, 0.05f);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Pintu rumah
        glColor3f(0.5f, 0.35f, 0.05f);
        glPushMatrix();
            glTranslatef(0.0f, 0.25f, 0.76f);
            glScalef(0.5f, 1.0f, 0.05f);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar apartemen pertama
void drawApartment1(float x, float z, bool left) {
    glPushMatrix();
        glTranslatef(x, 0.0f, z);
        // Lantai dasar apartemen
        glColor3f(0.7f, 0.7f, 0.7f); 
        glPushMatrix();
            glScalef(2.0f, 0.1f, 5.0f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Bangunan utama
        glColor3f(0.9f, 0.9f, 0.9f);
        glPushMatrix();
            glTranslatef(0.0f, 1.5f, 0.0f);
            glScalef(1.5f, 3.0f, 4.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Atap apartemen
        glColor3f(0.5f, 0.2f, 0.2f);
        glPushMatrix();
            glTranslatef(0.0f, 3.0f, 0.0f);
            glBegin(GL_QUADS);
                // Depan
                glVertex3f(-0.75f, 0.0f, 2.25f);
                glVertex3f(0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);

                // Belakang
                glVertex3f(-0.75f, 0.0f, -2.25f);
                glVertex3f(0.75f, 0.0f, -2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);

                // Kiri
                glVertex3f(-0.75f, 0.0f, -2.25f);
                glVertex3f(-0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);

                // Kanan
                glVertex3f(0.75f, 0.0f, -2.25f);
                glVertex3f(0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);
            glEnd();
        glPopMatrix();

        // Jendela Apartemen
        if (left){
        	glRotatef(90, 0, 1, 0);
        } else {
        	glRotatef(-90, 0, 1, 0);	
        }
        glColor3f(0.2f, 0.2f, 0.7f);
        for (int i = 0; i < 2; i++) {
            for (int j = -1; j <= 2; j++) { 
                glPushMatrix();
                    glTranslatef(j - 0.5f, 1.5f + i, 0.76f);
                    glScalef(0.3f, 0.5f, 0.05f);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Pintu apartemen
        glColor3f(0.5f, 0.35f, 0.05f);
        glPushMatrix();
            glTranslatef(0.0f, 0.5f, 0.76f);
            glScalef(0.5f, 1.0f, 0.05f);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar apartemen kedua
void drawApartment2(float x, float z, bool left) {
    glPushMatrix();
        glTranslatef(x, 0.0f, z);
        // Lantai dasar apartemen
        glColor3f(0.7f, 0.7f, 0.7f); 
        glPushMatrix();
            glScalef(2.0f, 0.1f, 5.0f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Bangunan utama
        glColor3f(1.0f, 0.5f, 0.0f);
        glPushMatrix();
            glTranslatef(0.0f, 1.5f, 0.0f);
            glScalef(1.5f, 3.0f, 4.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Atap apartemen
        glColor3f(0.0f, 0.5f, 0.0f);
        glPushMatrix();
            glTranslatef(0.0f, 3.0f, 0.0f);
            glBegin(GL_QUADS);
                // Depan
                glVertex3f(-0.75f, 0.0f, 2.25f);
                glVertex3f(0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);

                // Belakang
                glVertex3f(-0.75f, 0.0f, -2.25f);
                glVertex3f(0.75f, 0.0f, -2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);

                // Kiri
                glVertex3f(-0.75f, 0.0f, -2.25f);
                glVertex3f(-0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);

                // Kanan
                glVertex3f(0.75f, 0.0f, -2.25f);
                glVertex3f(0.75f, 0.0f, 2.25f);
                glVertex3f(0.0f, 0.5f, 2.25f);
                glVertex3f(0.0f, 0.5f, -2.25f);
            glEnd();
        glPopMatrix();

        // Jendela Apartemen
        if (left){
        	glRotatef(90, 0, 1, 0);
        } else {
        	glRotatef(-90, 0, 1, 0);	
        }
        glColor3f(0.2f, 0.2f, 0.7f);
        for (int i = 0; i < 2; i++) {
            for (int j = -1; j <= 2; j++) { 
                glPushMatrix();
                    glTranslatef(j - 0.5f, 1.5f + i, 0.76f);
                    glScalef(0.3f, 0.5f, 0.05f);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }

        // Pintu apartemen
        glColor3f(0.5f, 0.35f, 0.05f);
        glPushMatrix();
            glTranslatef(0.0f, 0.5f, 0.76f);
            glScalef(0.5f, 1.0f, 0.05f);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar pohon
void drawTree(float x, float z) {
    glPushMatrix();
        glTranslatef(x, 0.5f, z - 1.0f);

        // Batang Pohon
        glColor3f(0.5f, 0.35f, 0.05f);
        glPushMatrix();
            glTranslatef(0.0f, 0.5f, 0.0f);
            glScalef(0.5f, 1.5f, 0.5f);
            glutSolidCube(1.0);
        glPopMatrix();

        // Daun Pohon (Lapisan Bawah)
        glColor3f(0.0f, 0.5f, 0.0f);
        glPushMatrix();
            glTranslatef(0.0f, 1.0f, 0.0f);
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            glutSolidCone(1.2, 1.5, 10, 1);
        glPopMatrix();

        // Daun Pohon (Lapisan Atas)
        glPushMatrix();
            glTranslatef(0.0f, 2.0f, 0.0f);
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            glutSolidCone(0.9, 1.0, 10, 1);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi untuk menggambar rintangan
void drawObstacle(float x, float z) {
    glPushMatrix();
	    glTranslatef(x, 1.0f, z);
	    glColor3f(0.7f, 0.0f, 0.0f);
	    glPushMatrix();
		    glScalef(4.0f, 2.0f, 2.0f);
		    glutSolidCube(1.0);
	    glPopMatrix();
    glPopMatrix();
}

// Funggsi untuk membuat bayangan mobil
void drawShadow() {
    float shadowMat[4][4];
    float groundPlane[4] = {0, 1, 0, 0}; 
    float lightPos[4] = {carX + 5.0f, 10.0f, carZ, 1.0f}; 

    float dot = groundPlane[0] * lightPos[0] + 
                groundPlane[1] * lightPos[1] + 
                groundPlane[2] * lightPos[2] + 
                groundPlane[3] * lightPos[3];

    shadowMat[0][0] = dot - lightPos[0] * groundPlane[0];
    shadowMat[1][0] = 0.0f - lightPos[0] * groundPlane[1];
    shadowMat[2][0] = 0.0f - lightPos[0] * groundPlane[2];
    shadowMat[3][0] = 0.0f - lightPos[0] * groundPlane[3];

    shadowMat[0][1] = 0.0f - lightPos[1] * groundPlane[0];
    shadowMat[1][1] = dot - lightPos[1] * groundPlane[1];
    shadowMat[2][1] = 0.0f - lightPos[1] * groundPlane[2];
    shadowMat[3][1] = 0.0f - lightPos[1] * groundPlane[3];

    shadowMat[0][2] = 0.0f - lightPos[2] * groundPlane[0];
    shadowMat[1][2] = 0.0f - lightPos[2] * groundPlane[1];
    shadowMat[2][2] = dot - lightPos[2] * groundPlane[2];
    shadowMat[3][2] = 0.0f - lightPos[2] * groundPlane[3];

    shadowMat[0][3] = 0.0f - lightPos[3] * groundPlane[0];
    shadowMat[1][3] = 0.0f - lightPos[3] * groundPlane[1];
    shadowMat[2][3] = 0.0f - lightPos[3] * groundPlane[2];
    shadowMat[3][3] = dot - lightPos[3] * groundPlane[3];

	glClear(GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
	    glMultMatrixf((const GLfloat *)shadowMat);
	    glColor3f(0.0f, 0.0f, 0.0f);
	    glDisable(GL_COLOR_MATERIAL);
	    drawCar();
	    glEnable(GL_COLOR_MATERIAL);
    glPopMatrix();
}

// Fungsi untuk menggambar jalan dengan garis-garis
void drawRoad(float z) {
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, z);
	// Jalan
	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_QUADS);
		glVertex3f(-5.0f, 0.0f, -100.0f);
		glVertex3f(5.0f, 0.0f, -100.0f);
		glVertex3f(5.0f, 0.0f, 100.0f);
		glVertex3f(-5.0f, 0.0f, 100.0f);
	glEnd();
	    
    // Jalan trotoar kiri
	glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	    glVertex3f(-10.0f, 0.0f, -100.0f);
	    glVertex3f(-5.0f, 0.0f, -100.0f);
	    glVertex3f(-5.0f, 0.0f, 100.0f);
	    glVertex3f(-10.0f, 0.0f, 100.0f);
    glEnd();
	    
    // Jalan trotoar kanan
    glColor3f(1.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
	    glVertex3f(5.0f, 0.0f, -100.0f);
	    glVertex3f(10.0f, 0.0f, -100.0f);
	    glVertex3f(10.0f, 0.0f, 100.0f);
	    glVertex3f(5.0f, 0.0f, 100.0f);
    glEnd();
	
    // Garis tengah jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -100.0f; i < 100.0f; i += 4.0f) {
        glBegin(GL_QUADS);
	        glVertex3f(-0.1f, 0.01f, i);
	        glVertex3f(0.1f, 0.01f, i);
	        glVertex3f(0.1f, 0.01f, i + 2.0f);
	        glVertex3f(-0.1f, 0.01f, i + 2.0f);
        glEnd();
    }

    // Garis sisi jalan
    glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
        // Garis kiri
        glVertex3f(-5.0f, 0.01f, -100.0f);
        glVertex3f(-4.8f, 0.01f, -100.0f);
        glVertex3f(-4.8f, 0.01f, 100.0f);
        glVertex3f(-5.0f, 0.01f, 100.0f);

        // Garis kanan
        glVertex3f(5.0f, 0.01f, -100.0f);
        glVertex3f(4.8f, 0.01f, -100.0f);
        glVertex3f(4.8f, 0.01f, 100.0f);
        glVertex3f(5.0f, 0.01f, 100.0f);
    glEnd();
    glPopMatrix();
}

// Fungsi untuk menggambar lingkungan
void drawEnvironment() {
	// Menggambar jalan
	for (float i = 100.0f; i > -2000.0f; i -= 200.0f) {
		drawRoad(i);
	}
	
    // Menggambar rintangan, rumah, dan pohon
    for (float i = 100.0f; i > -2000.0f; i -= 20.0f) {
    	// Pinggir kanan 
    	
    	// Tepi kiri jalan
        drawTree(-6.0f, i);
        drawApartment1(-9.0f, i - 4.0f, true);
		drawHouse1(-9.0f, i + 0.3f, true);
        drawHouse2(-9.0f, i + 3.6f, true);
        drawApartment2(-9.0f, i + 7.9f, true);
        drawHouse3(-9.0f, i + 11.95f, true);

		// Tepi kanan jalan
		drawTree(6.0f, i);
		drawApartment1(9.0f, i + 2.0f, false);
        drawHouse1(9.0f, i - 2.3f, false);
        drawHouse2(9.0f, i - 5.6f, false);
        drawApartment2(9.0f, i - 9.9f, false);
        drawHouse3(9.0f, i - 13.95f, false);
    }
    for (float i = -50.0f; i > -2000.0f; i -= 20.0f) {
    	// pinggir kiri
    	drawObstacle(-2.5f, i - 20.0f);
    	drawObstacle(2.5f, i - 10.0f);
    }
    
}

// Fungsi untuk menggambar teks
void drawText(const char* text, int length, float x, float y) {
    glMatrixMode(GL_PROJECTION);
    double* matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
	    glLoadIdentity();
	    glRasterPos2i(x, y);
	    for (int i = 0; i < length; i++) {
	        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi untuk memeriksa tabrakan
bool checkCollision() {
    // Cek tabrakan dengan batas jalan (rumah dan pohon)
    if (carX < -5.0f || carX > 5.0f) {
        return true;
    }

	// Cek tabrakan dengan rintangan di pinggir kiri jalan
    for (float i = -50.0f; i > -2000.0f; i -= 20.0f) {
        if (std::abs(carZ - (i - 20.0f)) < 2.0f && std::abs(carX + 2.5f) < 3.0f) {
            return true;
        }
    }

    // Cek tabrakan dengan rintangan di pinggir kanan jalan
    for (float i = -50.0f; i > -2000.0f; i -= 20.0f) {
        if (std::abs(carZ - (i - 10.0f)) < 2.0f && std::abs(carX - 2.5f) < 3.0f) {
            return true;
        }
    }

    return false;
}


// Fungsi untuk memperbarui posisi mobil
void update(int value) {
    if (!gameOver) {
        carX += speed * sin(carAngle * M_PI / 180.0);
        carZ -= speed * cos(carAngle * M_PI / 180.0);
        distanceTravel += 1;

        if (checkCollision()) {
            gameOver = true;
        }

        // Meminta redisplay dan mengatur timer lagi
        glutPostRedisplay();
        glutTimerFunc(16, update, 0); // Memanggil update setiap 16 ms (~60 FPS)
    }
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (cameraBehind) {
        gluLookAt(carX, 4.0f, carZ + 10.0f, carX, 0.0f, carZ, 0.0f, 1.0f, 0.0f);
    } 
	else if (cameraLeft) {
        gluLookAt(carX - 10.0f, 4.0f, carZ, carX, 0.0f, carZ, 0.0f, 1.0f, 0.0f);
    } 
	else if (cameraRight) {
        gluLookAt(carX + 10.0f, 4.0f, carZ, carX, 0.0f, carZ, 0.0f, 1.0f, 0.0f);
    }
	else if (cameraAbove) {
		gluLookAt(carX, 15.0f, carZ, carX, 0.0f, carZ, 0.0f, 0.0f, -1.0f); 
	} 
	else {
        gluLookAt(carX, 4.0f, carZ - 10.0f, carX, 0.0f, carZ, 0.0f, 1.0f, 0.0f);
    }
    
    glPushMatrix();
		glRotatef((GLfloat)cameraY, 0.0, 1.0, 0.0);
	    drawShadow();
	    drawCar();
	    drawEnvironment();
    glPopMatrix();
    

    // Menampilkan UI
    glColor3f(10.0f, 10.0f, 10.0f);
    
    std::stringstream ss;

    ss.str("");
    ss << "Distance Travel: " << distanceTravel;
    drawText(ss.str().c_str(), ss.str().length(), 10, 580);

    ss.str("");
    ss << "Speed: " << speed;
    drawText(ss.str().c_str(), ss.str().length(), 10, 560);

    if (gameOver) {
        std::string gameOverText = "GAME OVER";
        drawText(gameOverText.c_str(), gameOverText.length(), 350, 300);

        std::string restartText = "Press 'R' to Restart";
        drawText(restartText.c_str(), restartText.length(), 320, 280);
    }

    glutSwapBuffers();
}

// Fungsi reshape
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi keyboard
void keyboard(int key, int x, int y) {
    if (!gameOver) {
        float angleSpeed = 5.0f;

        switch (key) {
            case GLUT_KEY_LEFT:
                carX-=0.5;
                break;
            case GLUT_KEY_RIGHT:
                carX+=0.5;
                break;
            case GLUT_KEY_UP:
                speed += 0.01f;
                break;
            case GLUT_KEY_DOWN:
                speed -= 0.01f;
                if (speed < 0.01f) {
                    speed = 0.01f;
                }
                break;
            
        }
        glutPostRedisplay();
    }
}

void normalKeys(unsigned char key, int x, int y) {
    if (gameOver && key == 'r') {
        gameOver = false;
        carX = 0.0f;
        carZ = 0.0f;
        carAngle = 0;
        wheelAngle = 0.0f;
        cameraY = 0.0f;
        cameraX = 0.0f;
        distanceTravel = 0;
        speed = 0.1f;
        cameraBehind = true;
        cameraLeft = false;
        cameraRight = false;
        glutTimerFunc(16, update, 0);
    } else if (gameOver) {
        switch (key) {
            case 'e':
                carAngle = (carAngle - 1) % 360;
                glutPostRedisplay();
                break;
        }
    } else {
        switch (key) {
			case 'z':
                if (cameraBehind) {
                    cameraBehind = false;
                    cameraLeft = false;
                    cameraRight = false;
                } else {
                    cameraBehind = true;
                    cameraLeft = false;
                    cameraRight = false;
                }
				cameraAbove = false;
                glutPostRedisplay();
                break;
            case 'x':
                if (cameraRight) {
                    cameraBehind = true;
                    cameraRight = false;
                } else {
                    cameraBehind = false;
                    cameraLeft = false;
                    cameraRight = true;
                }
                cameraAbove = false;
                glutPostRedisplay();
                break;
            case 'c':
                if (cameraLeft) {
                    cameraBehind = true;
                    cameraLeft = false;
                } else {
                    cameraBehind = false;
                    cameraLeft = true;
                    cameraRight = false;
                }
                cameraAbove = false;
                glutPostRedisplay();
                break;
            case 'v': // Tombol untuk kamera di atas
                if (cameraAbove) {
                    cameraBehind = true;
                    cameraAbove = false;
                } else {
                    cameraBehind = false;
                    cameraLeft = false;
                    cameraRight = false;
                    cameraAbove = true;
                }
                glutPostRedisplay();
                break;
        }
    }
}
 


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Car Game");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(normalKeys);

    // Menambahkan fungsi update
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
