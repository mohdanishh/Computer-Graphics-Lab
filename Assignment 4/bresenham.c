#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int X0, X1, Y0, Y1;

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
	int dx=abs(X1-X0);
	int dy=abs(Y1-Y0);
	int p=2*dy-dx;
	int end;
	float x, y;
	dx=abs(X1-X0);
	dy=abs(Y1-Y0);
	if(X0>X1){
		x=X1;
		y=Y1;
		end=X0;
	}else{
		x=X0;
		y=Y0;
		end=X1;
	}
	glVertex2i(x,y);
	while(x<end){
		x+=1;
		if(p<0) p=p+2*dy;
		else{
			y+=1;
			p=p+2*(dy-dx);
		}
		glVertex2i(x,y);
	}	
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	printf("Enter the coordinates of the two points: \n");
	scanf("%d",&X0);
	X0+=320;
	scanf("%d",&Y0);
	Y0+=240;
	scanf("%d",&X1);
	X1+=320;
	scanf("%d",&Y1);
	Y1+=240;
	glutCreateWindow("Bresenham's Line Generation");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
