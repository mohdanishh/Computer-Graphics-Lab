#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int X1, X2;
int Y1, Y2;

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int dx=X2-X1;
	int dy=Y2-Y1;
	int steps;
	if(abs(dx)>abs(dy)) steps=abs(dx);
	else steps=abs(dy);
	float Xinc=dx/(float)steps;
	float Yinc=dy/(float)steps;
	int i=0;
	float x=(float)X1, y=(float)Y1;
	for(i; i<steps; i++){
		x+=Xinc;
		y+=Yinc;
		glVertex2d(round(x),round(y));
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	printf("Enter the x coordinate of point 1: ");
	scanf("%d",&X1);
	X1+=320;
	printf("Enter the y coordinate of point 1: ");
	scanf("%d",&Y1);
	Y1+=240;
	printf("Enter the x coordinate of point 2: ");
	scanf("%d",&X2);
	X2+=320;
	printf("Enter the y coordinate of point 2: ");
	scanf("%d",&Y2);
	Y2+=240;
	glutCreateWindow("Digital Differential Analyser");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
