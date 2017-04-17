#include<GL/glut.h> 
#include<stdio.h>
float fillCol[3] = {0.4,0.0,0.0};  
float borderCol[3] = {0.0,0.0,0.0}; 
int ww = 1600, wh = 880;
void myInit(void)
 {
     glClearColor(1.0,1.0,1.0,0.0);
	 glColor3f(0.0f,0.0f,0.0f);
	 glPointSize(4.0);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0.0,1600.0,880.0,0.0);
 }
   void setPixel(int pointx, int pointy, float f[3])  
  {  
       glBegin(GL_POINTS);  
           glColor3fv(f);  
           glVertex2i(pointx,pointy);  
       glEnd();  
       glFlush();  
  } 
 
 void getPixel(int x, int y, float pixels[3])  
 	{  
    	  glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
	}
void boundaryFill4(int x,int y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];  
       getPixel(x,y,interiorColor);  
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]))  
       {  
            setPixel(x,y,fillColor);  
           boundaryFill4(x+1,y,fillColor,borderColor); 
           puts("HERE!"); 
            boundaryFill4(x-1,y,fillColor,borderColor);  
            puts("H!");
            boundaryFill4(x,y+1,fillColor,borderColor);  
            boundaryFill4(x,y-1,fillColor,borderColor);  
      }  
  }  	
	
	
	  
 void mouse(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
           int yi = (y);  
           boundaryFill4(xi,yi,fillCol,borderCol);  
      }  
  } 
 void myDisplay(void)
 {
 	int x,y,a,b;
     glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_LINES);
	 FILE* file = fopen ("/home/student/die/dk/ass6/coordinatesofdemo.txt", "r");
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
      			glVertex2i(x,y);
      			glVertex2i(a,b);
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
	  glutMouseFunc(mouse);
	 myInit();
	 glutMainLoop();
 }
