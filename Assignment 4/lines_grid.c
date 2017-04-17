#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int X1, Y1, X2, Y2;
int l=640, b=480;

void plot(int x, int y){
	glBegin(GL_LINES);
	x*=20;
	y*=20;
	int i, j;
	for(i=x-x%20; i<=x-x%20+20; i++){
		for(j=y-y%20; j<=y-y%20+20; j++){
			glVertex2i(i,b-j);
			glVertex2i(i,b-j+1);	
		}
	}
	glEnd();
	glFlush();
}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);	
	int i, j;
	for(i=0; i<=l; i+=20){
		for(j=0; j<=b; j=j+20){
			glVertex2i(0,j);
			glVertex2i(l,j);
			glVertex2i(i,0);
			glVertex2i(i,b);
		}
	}
	int dx=X2-X1;
	int dy=Y2-Y1;
	int steps;
	if(abs(dx)>abs(dy)) steps=abs(dx);
	else steps=abs(dy);
	float Xinc=dx/(float)steps;
	float Yinc=dy/(float)steps;
	i=0;
	float x=(float)X1, y=(float)Y1;
	plot(X1*20,Y1*20);
	for(i; i<steps; i++){
		x+=Xinc;
		y+=Yinc;
		plot(round(x),round(y));
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(l, b);
	glutInitWindowPosition(0,0);
	printf("Enter the coordinates of the two points:\n");
	scanf("%d",&X1);
	X1+=15;
	X1=32-X1;
	scanf("%d",&Y1);
	Y1+=11;
	Y1=12-Y1;
	scanf("%d",&X2);
	X2+=15;
	X2=31-X2;
	scanf("%d",&Y2);
	Y2+=11;
	Y2=12-Y2;
	glutCreateWindow("Line Printing in Grid");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
