#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

GLfloat a=0.9;
GLfloat b=0.45;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void ElipsePoints(GLfloat x, GLfloat y)
{
    glColor3f(0.8,0.2,0.0);
    glLoadIdentity();
    glBegin(GL_POINTS);
    //Algoritmo de SIMETRIA DE ORDEN 4
    glVertex3f( x, y, 0.0f);
    glVertex3f( x, -y, 0.0f);
    glVertex3f(-x, y, 0.0f);
    glVertex3f(-x, -y, 0.0f);
}

void MidpointElipse()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Valores Iniciales:
	GLfloat x;
	GLfloat y;
	GLfloat d1;
	GLfloat d2;

	x = 0.0;
	y = b;
	d1 = b * b - a * a * b + a * a / 4;
	ElipsePoints(x,y); //Simetria de Orden 4
	while(a*a*(y-0.0005) > b*b*(x+0.0001))
	{
		if (d1<0.0)
		{
			d1 = d1 + b*b*(2.0*x+0.0003);
			x+=0.0001;
		}
		else
		{
			d1 = d1 + b * b * (2.0* x + 0.0003) + a * a * (-2.0 * y + 0.0002);
			x+=0.0001;
			y-=0.0001;
		}
		ElipsePoints(x,y);
	}

	d2 = b * b * (x + 0.0005) * (x + 0.0005) + a * a * (y - 0.0001) * (y - 0.0001) - a * a * b * b;
	while(y>0.0)
	{
		//Para la region 2:
		if(d2<0.0)
		{
			d2 = d2 + b * b * (2.0 * x + 0.0002) + a * a * (-2.0 * y + 0.0003);
		
			x+=0.0001;
			y-=0.0001;
		}
		else
		{
			d2 = d2 + a * a * (-2.0 * y + 0.003);
			y-=0.0001;
		}
		ElipsePoints(x,y);
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
	//cout<<"Ingrese el numero de lados"<<endl;
	glutInitWindowPosition(50, 50); //Posicion "x" - "y" esquina superior izquierda
	glutInitWindowSize(600, 600); //Ancho y alto de la ventana
	glutCreateWindow("Elipse :");//Crea la ventana
	init();
	glutDisplayFunc(MidpointElipse);	
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}	

// g++ elipse.cpp -o elipse -lglut -lGL -lGLU
// ./elipse