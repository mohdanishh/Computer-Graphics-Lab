#include<GL/glut.h>

int l=640;
int b=480;

void myMouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		myDisplay(x,y);
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(-1);
}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.5f,0.0f);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
	myDisplay(-10,-10);
	glutMouseFunc(myMouse);
}

void myDisplay(int x, int y){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS); 
	glVertex2i(x,b-y);
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(l,b);
	glutInitWindowPosition(150,150);
	glutCreateWindow("Assignment3-Question4");
	glutDisplayFunc(myInit);
	myInit();
	glutMainLoop();
}

