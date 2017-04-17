#include<GL/glut.h> 
#include<stdio.h>

int count=1; 	int a,b;
void myInit(void)
 {
     glClearColor(1.0,1.0,1.0,0.0);
	 glColor3f(0.0f,0.0f,0.0f);
	 glPointSize(4.0);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0.0,1600.0,880.0,0.0);
 }
 void myDisplay(void)
 {
     glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_POINTS);
     glEnd();
	 glFlush();
  }
  void Display(int x,int y)
 {
      glBegin(GL_POINTS);
	 glVertex2i(x,y);
     glEnd();
	 glFlush();
  }
   void Displaylines(int x,int y,int a,int b)
 {
      glBegin(GL_LINES);
	 glVertex2i(x,y);
	  glVertex2i(a,b);
     glEnd();
	 glFlush();
  }
  void mouse(int btn, int state, int x, int y)
  {
   	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  		{
	  		if(count==1)
	  		{
	  			a=x;
	  			b=y;
	  			  		FILE *fp;
				   		fp = fopen("coordinatesofdemo.txt", "a+");
				   		fprintf(fp,"%d %d\n",x,y);
				   		fclose(fp);
				  		puts("Left button clicked");
				  		printf("%d\t%d",x,y);
  		
	  		}
	   		if(count>=2)
	  		{
	  			Displaylines(a,b,x,y);
	  			a=x;b=y;
	  			  		FILE *fp;
				   		fp = fopen("coordinatesofdemo.txt", "a+");
				   		fprintf(fp,"%d %d\n",x,y);
				   		fclose(fp);
				  		puts("Left button clicked");
				  		printf("%d\t%d",x,y);
  		
			}  		
	  		else
	  		{
	  			count++;
	  		}
  		}
  		if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
  		{
  			puts("Refreshed!");
  			x=-1;y=-1;
  			count=1;
  			  		FILE *fp;
			   		fp = fopen("coordinatesofdemo.txt", "a+");
			   		fprintf(fp,"%d %d\n",x,y);
			   		fclose(fp);
			  		puts("Left button clicked");
			  		printf("%d\t%d",x,y);
			  		
  		}
  }
  void main(int argc,char** argv)
 {
 	 glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(1600,900);
	 glutInitWindowPosition(0,0);
	 glutCreateWindow("Dinosaur");
	 glutMouseFunc(mouse);
	 glutDisplayFunc(myDisplay);
	 myInit();
	 glutMainLoop();
 }
