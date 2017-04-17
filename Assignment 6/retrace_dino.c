#include<GL/glut.h> 
#include<stdio.h>
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
	 FILE* file = fopen ("/home/student/die/dk/ass6/coordinates_dino.txt", "r");
  	int z = 0;

  		fscanf(file,"(%4d,%3d)\t-->\t\t(%4d,%3d)\n",&x,&y,&a,&b);    
  		while (!feof (file))
   		 {  
   		 		glVertex2i(x,y);
      			glVertex2i(a,b);
      			printf("%d %d\t%d %d\n",x,y,a,b);
      			fscanf(file,"(%4d,%3d)\t-->\t\t(%4d,%3d)\n",&x,&y,&a,&b); 
      			  
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
	 glutMainLoop();
 }
