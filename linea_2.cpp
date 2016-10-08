#include <GL/glut.h>
#include <iostream>

GLfloat x1,x2,y1,y2;

using namespace std;

void reshape(int width, int height)
{
	 glViewport(0, 0, width, height);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glOrtho(-1, 1, -1, 1, -1, 1);
	 glMatrixMode(GL_MODELVIEW);
}

void display()
{
	//Algoritmo PUNTO MEDIO	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,1);
	glLoadIdentity();
	GLfloat dx, dy, incE, incNE, d, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	d = 2.0 * dy-dx;
	incE = 2.0 * dy;
	incNE = 2.0 * (dy-dx);
	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex3f(x,y,0.0f);
	while(x<x2){
		if(d<=0.0){
			// Escolhe E
			d = d + incE;	
			x = x + 0.00001;
	}else{
		//Escolhe NE
		d = d + incNE;
		x = x + 0.00001;
		y = y + 0.00001;
	}
	glVertex3f(x,y,0.0f);
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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	cout<<"ingrese los puntos"<<endl;
	cout<<"X1:"<<endl;
	cin>>x1;
	cout<<"Y1:"<<endl;
	cin>>y1;
	cout<<"X2:"<<endl;
	cin>>x2;
	cout<<"Y2:"<<endl;
	cin>>y2;
	x1/=100; x2/=100; y1/=100; y2/=100;
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("La Linea: Con Punto Medio");
	init();
	glutDisplayFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

// g++ linea_2.cpp -o linea_2 -lglut -lGL -lGLU
// ./linea_2