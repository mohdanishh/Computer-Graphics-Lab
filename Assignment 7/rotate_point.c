#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>
static GLfloat rotat=0.0;
static GLint rotatq=0; 
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glShadeModel(GL_FLAT);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-350.0,350.0,-350.0,350.0);
}
void reshape(int w, int h)
{   glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350.0,350.0,-350.0,350.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
} 
void spindisplay(void)
{   if(rotatq==1)
    {   rotat+=0.1;
        if(rotat>360.0)
            rotat-=360.0;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{   switch(button)
    {   case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                rotatq=1;
            break;
        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                rotatq=0;
            break;
        default:
            break;
    }
}
void draw(){
glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(10,50);
	glEnd();
	//glFlush();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	draw();
	glRotatef(rotat,0.0,0.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250,10);
	glEnd();
	glPopMatrix();
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("rotation --Green Window");
	glutDisplayFunc(myDisplay);
	myInit();
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(spindisplay);
	glutMainLoop();
}
