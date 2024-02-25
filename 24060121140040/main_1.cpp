#include <GL/glut.h>
#include "windows.h"
int x=1;
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    for(int i=0; i<4; i++){
    glTranslatef(i*50,0,0);
    glScalef(x,x,1);
    x=x*0.8;
    glRecti(0,0,60,40);
    }
    glPopMatrix();
    glFlush();
}
void init(){
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0,0.0,0.0);
glViewport(0,0,300,200);
gluOrtho2D(-200.0,200.0,-200.0,200.0);
}
int main(int argc, char* argv[]){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(300,200);
glutCreateWindow("Drejkendeshi");
init();
glutDisplayFunc(Display);
glutMainLoop();
return 0;
}
