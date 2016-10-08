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

void drawEllipse()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	double i;
	double a=0.4;
	double b=0.8;
	GLfloat c;
	GLfloat angulo;
	glBegin(GL_POINTS);	
	for(i=0;i<360;i=i+=0.001)
	{
		angulo = (GLfloat)i*3.14159f/180.0f; //grados a radianes
		glVertex3f(cos(angulo)*a,sin(angulo)*b,0.0f);
	}
	glEnd();
	//glFlush();
}

void drawHyperbola()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();
	double a1=0.5;
	double b1=1.0;
	GLfloat k=b1/a1;
	GLfloat x,y,i;

	GLfloat c;
	c = sqrt(a1*a1+b1*b1);
	glBegin(GL_POINTS);	
	glVertex3f(c,0.0f,0.0f);
	glVertex3f(-c,0.0f,0.0f);
	glEnd();
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(a1,-b1,0.0);
	glVertex3f(a1,b1,0.0);
	glVertex3f(-a1,-b1,0.0);
	glVertex3f(-a1,b1,0.0);
	glEnd();
	glPopMatrix();

    glColor3f (1, 0.4, 0.4);                    // Vertical axis hyperbola

    glBegin (GL_POINTS);
       for (y = -10; y < 10; y += 0.01)  {     
          x = a1 * sqrt (1 + (y*y)/(b1*b1));
          glVertex2f ( x, y);
          glVertex2f (-x, y);
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
	glutCreateWindow("Hiperbola : ");//Crea la ventana
	init();
	glutDisplayFunc(drawHyperbola);	
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}	

// g++ hiperbola.cpp -o hiperbola -lglut -lGL -lGLU
// ./hiperbola