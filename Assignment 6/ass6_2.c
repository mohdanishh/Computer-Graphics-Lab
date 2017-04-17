#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#define X 1300
#define Y 700
   
  char s[20]; 
  float fColor[3] = {0.4,0.6,0.0};  
  float bColor[3] = {0.0,0.0,0.0};
  float eColor[3] = {1.0,1.0,1.0}; 
  int sx,ex;
  void getPixel(int x, int y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
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
  
  void floodFill4(int x,int y,float fillColor[3],float empColor[3])  
  {  
       float iColor[3];  
       getPixel(x,y,iColor); 
       //printf("%d, %d    R-%f, G-%f, B-%f\n",x,y,iColor[0],iColor[1],iColor[2]); 
       if((iColor[0]==empColor[0] && (iColor[1])==empColor[1] && (iColor[2])==empColor[2]))  
       {  
            glBegin(GL_POINTS);  
            glColor3fv(fillColor);  
            glVertex2i(x,y);  
            glEnd();  
            glFlush();  
             
            floodFill4(x+1,y,fillColor,empColor);  
            floodFill4(x-1,y,fillColor,empColor);  
            floodFill4(x,y+1,fillColor,empColor);  
            //floodFill4(x,y-1,fillColor,empColor);  
       }  
  }
  
  void scanfill()
  {
        int i=0,j=0,k;
        for(i=Y-75;i>=0;i--)
        {
            float iColor[3],i1Color[3],i2Color[3],upColor[3],pColor[3],i3Color[3],nColor[3],up2Color[3],i4Color[3];
            int state=0;
            sx=-1;ex=-1;
            for(j=0;j<=X;j++)
            {
                getPixel(j,i,i1Color);
                if((i1Color[0])==bColor[0] && (i1Color[1])==bColor[1] && (i1Color[2])==bColor[2])
                {   
                    sx=j;
                    //printf("found start %d",sx);
                    break;
                }
            }
            for(k=X-10;k>=0;k--)
            {
                getPixel(k,i,i2Color);
                if((i2Color[0])==bColor[0] && (i2Color[1])==bColor[1] && (i2Color[2])==bColor[2])
                {   
                    ex=k;
                    //printf("found end %d",ex);
                    break;
                }
            }
            if(sx!=ex)
            {
            	 pColor[0]=bColor[0];
                 pColor[1]=bColor[1];
                 pColor[2]=bColor[2];
                 int c=0;
                //printf("found start %d",sx);
                for(j=sx+1;j<=ex-1;j++)
                {
                    getPixel(j,i,iColor);
                    getPixel(j,i+1,upColor);
                    if(iColor[0]!=pColor[0] && iColor[1]!=pColor[1] && iColor[2]!=pColor[2])
                    	c++;
                    if((iColor[0]!=bColor[0] && iColor[1]!=bColor[1] && iColor[2]!=bColor[2])&&((upColor[0]==fColor[0] && upColor[1]==fColor[1] && upColor[2]==fColor[2])||c%4==1))
					{
                        //printf("found end\n ");
                        if((upColor[0]==eColor[0] && upColor[1]==eColor[1] && upColor[2]==eColor[2]) && c%4==1)
                        	c=3;
                        else
                        {
                        	setPixel(j,i,fColor);
                        	if(c%4!=1)
                        		c=1;
                    	}
                    }
					
		    		pColor[0]=iColor[0];
                    pColor[1]=iColor[1];
                    pColor[2]=iColor[2];
                }
                for(j=ex-1;j>sx;j--)
                {
                	getPixel(j,i,i3Color);
	                getPixel(j-1,i,nColor);
	                getPixel(j,i+1,up2Color);
	                if((i3Color[0]==fColor[0] && i3Color[1]==fColor[1] && i3Color[2]==fColor[2])&&(nColor[0]==eColor[0] && nColor[1]==eColor[1] && nColor[2]==eColor[2]))
	                	setPixel(j-1,i,fColor);
	                else if((i3Color[0]==eColor[0] && i3Color[1]==eColor[1] && i3Color[2]==eColor[2])&&(nColor[0]==fColor[0] && nColor[1]==fColor[1] && nColor[2]==fColor[2]))
	        			setPixel(j-1,i,eColor);
	        		getPixel(j,i,i4Color);
	        		if((i4Color[0]==fColor[0] && i4Color[1]==fColor[1] && i4Color[2]==fColor[2])&&(up2Color[0]==eColor[0] && up2Color[1]==eColor[1] && up2Color[2]==eColor[2]))
	                	floodFill4(j,i+1,fColor,eColor);
	                else if((i4Color[0]==eColor[0] && i4Color[1]==eColor[1] && i4Color[2]==eColor[2])&&(up2Color[0]==fColor[0] && up2Color[1]==fColor[1] && up2Color[2]==fColor[2]))
	        			floodFill4(j,i+1,eColor,fColor);

                }
            }
       }  
  }
  
  void myDisplay(void)  
  {  
       glClear(GL_COLOR_BUFFER_BIT);   
       drawFigure(s,bColor);
       scanfill();
       glFlush();  
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
       glutCreateWindow("Ass6_2");  
       glutDisplayFunc(myDisplay);  
       myInit();  
       //glutMouseFunc(myMouse);  
       glutMainLoop();  
       return 0;  
  }
