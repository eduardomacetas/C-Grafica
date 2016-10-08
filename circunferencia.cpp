#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void CirclePoints(GLfloat x, GLfloat y)
{
    glColor3f(1,1,0);
    glLoadIdentity();
    glBegin(GL_POINTS);
    //Algoritmo de Simetría de orden 8
    glVertex3f( x, y, 0.0f);
    glVertex3f( x, -y, 0.0f);
    glVertex3f(-x, y, 0.0f);
    glVertex3f(-x, -y, 0.0f);
    glVertex3f( y, x, 0.0f);
    glVertex3f( y, -x, 0.0f);
    glVertex3f(-y, x, 0.0f);
    glVertex3f(-y, -x, 0.0f);
    glEnd();
    glFlush();
}

void MidPointCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);

    GLfloat r=0.9;
    GLfloat x, y;
    GLfloat d;

    x = 0.0;
    y = r;
    d = 5/4 - r;
    CirclePoints(x,y);
    while (y >   x){
        if (d < 0){
            d = d + 2 * x + 0.03;
            x+=0.0001;
        }
        else
        {
            d = d + 2 * (x - y) + 0.05;
            x+=0.0001;
            y-=0.0001;
        }
       CirclePoints(x,y);
    }
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); //Inicializa la GLUT, abre una ventana
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //solo se debe de usar un buffer | el color en que dibujara
    glutInitWindowPosition(50, 50); //Posicion "x" - "y" esquina superior izquierda
    glutInitWindowSize(600, 600); //Ancho y alto de la ventana
    glutCreateWindow("Circunferencia:");//Crea la ventana
    init();  
    glutDisplayFunc(MidPointCircle);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}   

// g++ circunferencia.cpp -o circunferencia -lglut -lGL -lGLU
// ./circunferencia