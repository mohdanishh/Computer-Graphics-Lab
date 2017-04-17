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
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
	myDisplay(-40,-40);
	glutMouseFunc(myMouse);
}

void myDisplay(int x, int y){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	int i, j;
	for(i=0; i<=l; i+=40){
		for(j=0; j<=b; j+=40){
			glVertex2i(0,j);
			glVertex2i(l,j);
			glVertex2i(i,0);
			glVertex2i(i,b);
		}
	}
	for(i=x-x%40; i<=x-x%40+40; i++){
		for(j=y-y%40; j<=y-y%40+40; j++){
			glVertex2i(i,b-j);
			glVertex2i(i,b-j+1);	
		}
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(l, b);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Grid Highlighting");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}


