#include<GL/glut.h>
#include<stdio.h>
#include<unistd.h>
#include <math.h>
#define PI 3.14159
#define dr  0.0174532925
#define s 4
#define xs 800
#define ys 450
int i=0,x1=1,x2,Y1,y2;
void myInit(void)
{
	glClearColor(0.0,0.8,0.6,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1600.0,900.0,0.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES);	
	FILE *fptr;
	for(double j=0.0; j<180.0;j+=0.5){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		fptr = fopen("/home/mohdanishh/backupPointsDino.txt","r");
		int z[] = {0,0,0,0};
		do
		{
			fscanf(fptr,"(%4d,%3d)\t-->\t\t(%4d,%3d)\n",&z[0],&z[1],&z[2],&z[3]);
			x1=z[0];
			Y1=z[1];
			x2=z[2];
			y2=z[3];
			printf("<%d %d %d %d>\t\t%d\n",z[0],z[1],z[2],z[3],++i);
				glBegin(GL_LINES);
				if(j<90)
				{ 
					glVertex2i(xs+(cos(j*dr))*x1/s-(sin(j*dr))*Y1/s,ys+(sin(j*dr))*x1/s+(cos(j*dr))*Y1/s);
				  	glVertex2i(xs+(cos(j*dr))*x2/s-(sin(j*dr))*y2/s,ys+(sin(j*dr))*x2/s+(cos(j*dr))*y2/s);
				}
				else
				{
					glVertex2i(xs+(sin(j*dr))*x1/s-(cos(j*dr))*Y1/s,ys+(cos(j*dr))*x1/s+(sin(j*dr))*Y1/s);
				  	glVertex2i(xs+(sin(j*dr))*x2/s-(cos(j*dr))*y2/s,ys+(cos(j*dr))*x2/s+(sin(j*dr))*y2/s);	
				}
				usleep(10);	

		}
		while (!feof (fptr));
		fclose(fptr); 	
		glEnd();
		glutSwapBuffers();
		glFlush();
	
	}
}
void main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1600,900);			
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotating Dino....");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
