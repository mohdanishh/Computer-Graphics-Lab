#include<GL/glut.h> 
#include<stdio.h>
#define X 1600
#define Y 900
  char s[20]; 
  float fColor[3] = {0.4,0.6,0.0};  
  float bColor[3] = {0.0,0.0,0.0};  
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
 	int x,y,a,b;
     glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_LINES);
	 FILE* file = fopen ("/home/student/die/dk/ass7/ka.txt", "r");
  	int i = 0;

  		fscanf(file, "%d %d", &x,&y);    
  		while (!feof (file))
   		 {  
      			fscanf(file, "%d %d", &a,&b);
      			printf("%d\t%d\n",a,b);
      			if(a == -1 && b == -1)
      			{
      				fscanf(file, "%d %d", &x,&y);
      				fscanf(file, "%d %d", &a,&b);
      				puts("true");
      		    }
      			glVertex2i(x/2,y/2);
      			glVertex2i(a/2,b/2);
      			glVertex2i(1600-x/2,y/2);
      			glVertex2i(1600-a/2,b/2);
      			x=a;y=b;
  
    }
	  fclose (file);        
	     glEnd();
		 glFlush();
	   }
 void main(int argc,char** argv)
 {
 	 glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(1600,900);
	 glutInitWindowPosition(200,100);
	 glutCreateWindow("Re tracing...");
	 glutDisplayFunc(myDisplay);
	 myInit();
  //   glutMouseFunc(myMouse);
	 glutMainLoop();
 }

