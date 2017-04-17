#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#define X 1300
#define Y 700
   
  char s[20]; 
  float fColor[3] = {0.4,0.6,0.0};  
  float bColor[3] = {0.0,0.0,0.0};  

  void getPixel(int x, int y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
  }  
  /*void drawPolygon(int x1, int y1, int x2, int y2)  
  {       
       glColor3f(0.0,0.0,0.0);  
       glBegin(GL_LINES);  
            glVertex2i(x1, y1);  
            glVertex2i(x1, y2);   
       glEnd();  
                   glBegin(GL_LINES);  
                        glVertex2i(x1-10, y1);  
                        glVertex2i(x1-10, y2);   
                   glEnd(); 
       glBegin(GL_LINES);  
            glVertex2i(x1-1, y2);  
            glVertex2i(x2, y2);  
       glEnd();  
                   glBegin(GL_LINES);  
                        glVertex2i(x1, y2+10);  
                        glVertex2i(x2, y2+10);  
                   glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x2, y2);
            glVertex2i(x2, y1);    
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x2, y1); 
            glVertex2i(x1, y1);   
       glEnd();  
                   glBegin(GL_LINES);  
                        glVertex2i(x2, y1-10);
                        glVertex2i(x1, y1-10);  
                   glEnd();  
       glFlush();  
  }  */
  void drawFigure(char *n, float Color[3])
  {
        int x,y;
        FILE *fp=fopen(n,"r");
        glBegin(GL_POINTS);  
        glColor3fv(Color);
        while(!feof(fp))
	    {    
	        fscanf(fp,"%d%d\n",&x,&y);
	        glVertex2i(x,y);  
	    }
	    glEnd();  
        glFlush(); 
	    fclose(fp);
  }
  
  /*void myDisplay(void)  
  {  
       glClear(GL_COLOR_BUFFER_BIT);  
       //drawPolygon(20,20,30,30); 
       drawFigure(s,bColor); 
       glFlush();  
  }  
  void boundaryFill4(int x,int y)  
  {  
       float iColor[3];  
       getPixel(x,y,iColor); 
       printf("%d, %d    R-%f, G-%f, B-%f\n",x,y,iColor[0],iColor[1],iColor[2]); 
       if((iColor[0]!=bColor[0] && (iColor[1])!=bColor[1] && (iColor[2])!=bColor[2]) && (iColor[0]!=fColor[0] && (iColor[1])!=fColor[1] && (iColor[2])!=fColor[2]))  
       {  
            fprintf(fp,"%d %d\n",x,y);  
             
            boundaryFill4(x+1,y);  
            boundaryFill4(x-1,y);  
            boundaryFill4(x,y+1);  
            boundaryFill4(x,y-1);  
       }  
  }*/
  /*void fillFigure(int x,int y)
  {
        char t[10]="temp.txt";
        FILE *fp=fopen(t,"w");
        boundaryFill4(x,y,fp);
        fclose(fp);
        drawFigure(t,fColor);
  }*/
  void myDisplay(void)  
  {  
       glClear(GL_COLOR_BUFFER_BIT);  
       //drawPolygon(20,20,100,100); 
       drawFigure(s,bColor); 
       glFlush();  
  } 
  void setPixel(int pointx, int pointy, float f[3])  
  {  
       glBegin(GL_POINTS);
	   glPointSize(1.0);  
       glColor3fv(f);  
       glVertex2i(pointx,pointy);  
       glEnd();  
       glFlush();  
  }   
  void boundaryFill4(int x,int y,float fColor[3],float bColor[3])  
  {  
       if(x>X||y<0||y>Y||x<0)
	        return;
       float iColor[3];  
       getPixel(x,y,iColor); 
       if((iColor[0]!=bColor[0] && (iColor[1])!=bColor[1] && (iColor[2])!=bColor[2]) && (iColor[0]!=fColor[0] && (iColor[1])!=fColor[1] && (iColor[2])!=fColor[2]))  
       {  
            /*glBegin(GL_POINTS);  
            glColor3fv(fColor);  
            glVertex2i(x,y);  
            glEnd();  
            glFlush(); */ 
            
            setPixel(x,y,fColor);
            boundaryFill4(x+1,y,fColor,bColor);  
            boundaryFill4(x-1,y,fColor,bColor);  
            boundaryFill4(x,y+1,fColor,bColor);  
            boundaryFill4(x,y-1,fColor,bColor);  
       }  
  } 
  void myMouse(int button, int state, int x, int y)  
  {  
       float pick_col[3]={0.0,0.0,0.0};
       if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (Y-y); 
            //fillFigure(xi,yi); 
            boundaryFill4(xi,yi,fColor,bColor);  
       }
  }  
  void myInit(void)  
  {    
       glClearColor(1.0,1.0,1.0,1.0);      
       glViewport(0,0,X,Y);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0.0,X,0.0,Y);  
       glMatrixMode(GL_MODELVIEW);  
  }  
  int main(int argc, char** argv)  
  {  
       printf("Enter file name of figure to be filled\n");
       scanf("%s",s);
       glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(X,Y);  
       glutCreateWindow("Ass6_3");  
       glutDisplayFunc(myDisplay);  
       myInit();  
       glutMouseFunc(myMouse);  
       glutMainLoop();  
       return 0;  
  }  
