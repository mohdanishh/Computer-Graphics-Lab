#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int pk1,x,y;
void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0,320.0,-240.0,240.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	x=0;
	y=100;
	pk1=-3/4.0;
	while(y>0){
		glVertex2i(x,y);
		glVertex2i(-x,y);
		if(pk1<0){
			pk1=pk1+2*x+1;
			x=x+1;
		}
		else{
			pk1=pk1-1;
		}y--;
	}
	glEnd();
	glFlush();
}

void main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Parabola Drawing");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

