#include<GL/glut.h>
double x1,yy1,x2,yy2; 
void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1600.0,0.0,900.0);
}
void myDisplay (void)
{
	int i,j;
    glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINES);
    for(i=1;i<=160;i++)
  	 {
	   	 glVertex2f(10*i,0);
	   	 glVertex2f(10*i,1600);
   	 }
   	  for(i=1;i<=90;i++)
  	 {
	   	 glVertex2f(0,10*i);
	   	 glVertex2f(1600,10*i);
   	 }
   	 for(i=-1;i<=1;i++)
   	 {
   	 glVertex2f(800+i,0);
   	 glVertex2f(800+i,900);
   	 glVertex2f(0,450+i);
   	 glVertex2f(1600,450+i);
   	 }
   	  glEnd();
   	  x1=10;x2=100;yy1=10;yy2=100;
   	  double d1,d2,d3;
   	      double m=(yy2-yy1)/(x2-x1);
   	   glBegin(GL_POINTS);
    	while(x1<=x2)
	 {
	 	d1=x1/10;
	 	d2=yy1/10;
		if(d1*10!=x1)
		d1=d1-(x1-d1*10);
	 	for(j=0;j<10;j++)
	 	for(i=0;i<10;i++)
	 	glVertex2i(d1*10+i+800, d2*10+j+450);	
	 	x1+=10/m;
	 	yy1=yy1+10;
	 }
	glEnd();
     glFlush();
}
void main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(1600,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My first program");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
