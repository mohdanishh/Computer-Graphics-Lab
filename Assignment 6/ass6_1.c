#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define X 1300
#define Y 700
void drawer(int,int,int);
void plot(int x,int y);
void BLA(int x1,int y1,int x2,int y2);
char s[20];

void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
	glViewport(0,0,X,Y);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glPointSize(1.0);
	glLoadIdentity();
	gluOrtho2D(0,X,0,Y);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void BLA(int xa,int ya,int xb, int yb)
{
    int dx=xa-xb,dy=ya-yb,h=1;
    if((dx<0&&dy>0)||(dx>0&&dy<0))
    		h=-1;
    dx=abs(dx);
    dy=abs(dy);
    int p,x,y,xEnd,yEnd;
    if(dx>dy)
    {
        p = 2*dy-dx;
        if(xa>xb)
        {
            x=xb;
            y=yb;
            xEnd=xa;
        }
        else
        {
            x=xa;
            y=ya;
            xEnd=xb;
        }
        plot(x,y);
        while(x < xEnd)
        {
            x++;
            if(p>=0)
            {
                y+=h;
                p+=-2*dx;
            }
            p+=2*dy;
            plot(x,y);
        }
    }
    else
    {
        p = 2*dx-dy;
        if(ya>yb)
        {
            y=yb;
            x=xb;
            yEnd=ya;
        }
        else
        {
            y=ya;
            x=xa;
            yEnd=yb;
        }
        plot(x,y);
        while(y < yEnd)
        {
            y++;
            if(p>=0)
            {
                x+=h;
                p+=-2*dy;
            }
            p+=2*dx;
            plot(x,y);
        }
    }            
}

void plot(int a,int b)
{
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a,b);
    glEnd();
    glFlush();
    FILE *fp=fopen(s,"a");
	fprintf(fp,"%d %d\n",a,b);
	fclose(fp);
}


void myMouse(int button, int state, int x, int y)
{
    y=Y-y;
    static int h=0;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
    	    glColor3f(0.1, 0.0, 0.0);
	        glBegin(GL_POINTS);
	        glVertex2i(x,y);
	        glEnd();
            drawer(x,y,h);
	        glFlush();
	        h=1;
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		h=0;
}

void drawer(int a,int b,int h)
{
	static int x1,y1,x2,y2;
	x2=a;
	y2=b;
	if(h==1)
		BLA(x1,y1,x2,y2);
	x1=x2;
	y1=y2;
}
     
void main(int argc, char** argv)
{
	printf("Enter file name for figure\n");
	scanf("%s",s);
	FILE *fp=fopen(s,"w");
	fclose(fp);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(X,Y);
	glutInitWindowPosition(10,50);
	glutCreateWindow("Ass 6_1");
	glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}

