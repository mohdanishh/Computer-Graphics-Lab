#include<GL/glut.h>
#include<math.h>

int r, xc, yc;

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(xc,yc);
	int x=0, y=r;
	glVertex2i(x,y);
	int p=1-r;
	while(x<y){
		drawCircle(x,y);
		x+=1;
		if(p<0){
			p+=2*x+6;
		}else{
			y-=1;
			p+=2*(x-y)+1;
		}
		drawCircle(x,y);
	}
	glEnd();
	glFlush();
}

void drawCircle(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(xc+x, yc+y);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc-x, yc-y);
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc-y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-y, yc-x);
	glEnd();
	glFlush();	
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0,0);
	printf("Enter the Radius: ");
	scanf("%d",&r);
	printf("Enter the X-coordinate of the center: ");
	scanf("%d",&xc);
	xc+=320;
	printf("Enter the Y-coordinate of the center: ");
	scanf("%d",&yc);
	yc+=240;
	glutCreateWindow("Circle Drawing");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
