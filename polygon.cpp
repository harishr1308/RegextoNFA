#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <GL/glut.h>
#include "adiprog.cpp"
using namespace std;

 #define RADPERDEG 0.0174533

int sides=10; //number of sides
const double pi = 3.14;
static int k=0;
string inre;

vector<vector<double> > xycoordinates;
//vector<vector<int> >transitions;
double r = 350;

/*void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
}*/

void testing()
{
 for(int j=0;j<sides;j++)
   {
    vector<int> temp;
    for(int i=0;i<sides;i++)
    temp.push_back(1);
    transitions.push_back(temp);
    temp.erase(temp.begin(),temp.end());
   }
}

void testing2()
{
 for(int j=0;j<sides;j++)
   {
    vector<char> temp;
    for(int i=0;i<sides;i++)
    temp.push_back('a');
    alpha.push_back(temp);
    temp.erase(temp.begin(),temp.end());
   }
}

void output(int x, int y, float r, float g, float b, void* font, char st[])
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len = strlen(st);
  for (int i = 0; i < len; i++) 
  {
    glutBitmapCharacter(font, int(st[i]));
  }
}

void circlePlotPoints(int xc,int yc,int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2f(xc+x,yc+y);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc+x,yc-y);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc-x,yc+y);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc-x,yc-y);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc+y,yc+x);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc+y,yc-x);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc-y,yc+x);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(xc-y,yc-x);
	glEnd();
}

void circlePlot(int xc,int yc,int x,int y)
{
	glBegin(GL_POLYGON);
		glVertex2f(xc+x,yc+y);
		glVertex2f(xc+x,yc-y);
		glVertex2f(xc-x,yc+y);
		glVertex2f(xc-x,yc-y);
		glVertex2f(xc+y,yc+x);
		glVertex2f(xc+y,yc-x);
		glVertex2f(xc-y,yc+x);
		glVertex2f(xc-y,yc-x);
	glEnd();
}

void Bresenham(int xC,int yC, int radius)
{
	glPointSize(1);
	int x=0;
	int y=radius;
	int p=1-radius;
	circlePlotPoints(xC,yC,x,y);
	while(x<y)
	{
		x++;
		if(p<=0)
			p+= (2*x +1);
		else
		{
			y--;
			p+=(2*(x-y)+1);
		}
		//circlePlotPoints(xC,yC,x,y);
		circlePlot(xC,yC,x,y);
	}
	glFlush();
}

void BresenhamKrug(int xCenter, int yCenter,int r){ //napravite parametarski poziv
    int x=0,y=r;
    int d=3-(2*r);

  
    glBegin(GL_POLYGON);

    while(x<=y)
    {
        glVertex2i(xCenter+x,yCenter+y);  glVertex2i(xCenter+y,yCenter+x);
        glVertex2i(xCenter-x,yCenter+y);  glVertex2i(xCenter+y,yCenter-x); 
        glVertex2i(xCenter-x,yCenter-y);  glVertex2i(xCenter-y,yCenter-x); 
        glVertex2i(xCenter+x,yCenter-y);  glVertex2i(xCenter-y,yCenter+x); 

        if (d<0)
            d += (4*x)+6;
        else{
              d += (4*(x-y))+10;
              y--;
        }

        x++;
    }
    glEnd();
    glFlush();
}

void polygon()
{
 double d=0.75;
 int i=0; //it iterates from 0 to no of sides
 double x,y,t;
 while(i<sides)
 {
  t=2*pi*(double(i)/sides+d);
  x=cos(t)*r;
  y=sin(t)*r;
  vector<double> temp;
  temp.push_back(x+688);
  temp.push_back(y+384);
  xycoordinates.push_back(temp);
  temp.erase(temp.begin(),temp.end());
  i++;
 }
 /*for(int i=0;i<sides;i++)
  {
   for(int j=0;j<2;j++)
     cout<<xycoordinates[i][j]<<" ";
   cout<<endl;
  }*/
 cout<<inre<<endl;
}

void drawarrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D)
{
  double x=x2-x1;
  double y=y2-y1;
  double z=z2-z1;
  double L=sqrt(x*x+y*y+z*z);

    GLUquadricObj *quadObj;

    glPushMatrix ();

      glTranslated(x1,y1,z1);

      if((x!=0.)||(y!=0.)) {
        glRotated(atan2(y,x)/RADPERDEG,0.,0.,1.);
        glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.,1.,0.);
      } else if (z<0){
        glRotated(180,1.,0.,0.);
      }

      glTranslatef(0,0,L-4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, 2*D, 0.0, 4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      /*quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, 2*D, 32, 1);
      gluDeleteQuadric(quadObj);

      glTranslatef(0,0,-L+4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, D, D, L-4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, D, 32, 1);
      gluDeleteQuadric(quadObj);*/

    glPopMatrix ();
}

void drawline(double x1,double y1,double x2,double y2)
{
   glBegin(GL_LINES);
     glVertex2f(x1,y1);
     glVertex2f(x2,y2);
   glEnd();
}

void lines(double radius)
{
 double z=10,l=7;
 for(int i=0;i<sides;i++)
  {
    for(int j=0;j<sides;j++) 
     {
       if (alpha[i][j]!=' ' && alpha[j][i]==' ')
          {
            if (i!=j)
              {
		drawline(xycoordinates[i][0],xycoordinates[i][1],xycoordinates[j][0],xycoordinates[j][1]);
	 	drawarrow(xycoordinates[i][0],xycoordinates[i][1],z,xycoordinates[j][0],xycoordinates[j][1],z,l);
              }
          }
       else if (alpha[i][j]!=' ' && alpha[j][i]!=' ')
          {
            if (i!=j)
              {
                if (i<j)
                 {
		   drawline(xycoordinates[i][0],xycoordinates[i][1]+radius,xycoordinates[j][0],xycoordinates[j][1]+radius);
		   drawarrow(xycoordinates[i][0],xycoordinates[i][1],z,xycoordinates[j][0],xycoordinates[j][1],z,l);
                 }
                else if (i>j)
                 {
		   drawline(xycoordinates[i][0],xycoordinates[i][1]-radius,xycoordinates[j][0],xycoordinates[j][1]-radius);
		   drawarrow(xycoordinates[i][0],xycoordinates[i][1],z,xycoordinates[j][0],xycoordinates[j][1],z,l);
                 }
                
              }
          }
       
     }
  }
}


void drawalpha(double x,double y,char c)
{
 char ch[2];
 ch[0]=c;
 ch[1]='\0';
 output(x,y,1,1,1,GLUT_BITMAP_HELVETICA_18,ch);
}

void alphalines(double radius)
{
 for(int i=0;i<sides;i++)
  {
    for(int j=0;j<sides;j++) 
     {
       if (alpha[i][j]!=' ' && alpha[j][i]==' ')
          {
            if (i!=j)
              {
                double x=(xycoordinates[i][0]+xycoordinates[j][0])/2;
                double y=(xycoordinates[i][1]+xycoordinates[j][1])/2;
                drawalpha(x,y,alpha[i][j]);
              }
          }
       else if (alpha[i][j]!=' ' && alpha[j][i]!=' ')
          {
            if (i!=j)
              {
                if (i<j)
                 {
		   double x=((xycoordinates[i][0]+xycoordinates[j][0])/2);
                   double y=((xycoordinates[i][1]+xycoordinates[j][1])/2)+radius;
                   drawalpha(x,y,alpha[i][j]);
                 }
                else if (i>j)
                 {
		   double x=((xycoordinates[i][0]+xycoordinates[j][0])/2);
                   double y=((xycoordinates[i][1]+xycoordinates[j][1])/2)-radius;
                   drawalpha(x,y,alpha[i][j]);
                 }
                
              }
          }
       
     }
  }
}


void circle(double radius)
{
 double x1,y1,x2,y2;
  for(int i=0;i<sides;i++)
    {
     x1=xycoordinates[i][0];
     y1=xycoordinates[i][1];
     if(initial_state==i)
       {
         glColor3f(0.0,1.0,1.0); 
         BresenhamKrug(x1,y1,radius);
       }
     else if (final_state==i)
       {
         glColor3f(0.0,0.0,0.0); 
         BresenhamKrug(x1,y1,radius+5);
	 glColor3f(0.5,0.3,1.0); 
         BresenhamKrug(x1,y1,radius);
       }
     else
       {
         glColor3f(0.5,0.5,0.5); 
         BresenhamKrug(x1,y1,radius);
       }

    }
}

void text()
{
 string s="s";
 for (int i=0;i<sides;i++)
  { 
   string text;
   int temp=i;
    if(temp>9)
     {
       while(temp!=0)
        {
	  int t=temp%10;
          char cha=char(t+48);
          text=cha+text;
          temp/=10;
        }
     }
    else
     {
       char cha=char(i+48);
       text=text+cha;      
     }
     text=s+text;
     const int txtlen=text.length();
     char ch[txtlen];
   int j;
   for(j=0;j<txtlen;j++)
      {ch[j]=text[j];}
     ch[j]='\0';
   //glColor3f(1,0,0);
   output(xycoordinates[i][0],xycoordinates[i][1],1,1,1,GLUT_BITMAP_HELVETICA_12,ch);
  }
}
vector<char> in;
static int size=0;
void keyboard2(unsigned char key, int x, int y)
{
 while (key!=13)
  {
    in.push_back(key);
    size++;
  }
}

void display()
{
  double radius=15;
 if(k==0)
  {
   retonfa(inre);
   sides=cur;
   cout<<"total no of sides : "<<sides<<endl;
   polygon();
  }
   glClearColor(1.0,0.0,0.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,1.0,0.6);
   //testing();
   //lines();
   for(int i=0;i<inre.length();i++)
    {
      drawalpha(10+10*i,30,inre[i]);
    }
   lines(radius);
   circle(radius);
   alphalines(radius);
   text();
   //testing2();
   glFlush();
  k++;
  
}

void keyboard(unsigned char key, int x, int y)
{
 if(key==27) 
  {  
    xycoordinates.erase(xycoordinates.begin(),xycoordinates.end());
    transitions.erase(transitions.begin(),transitions.end());
    alpha.erase(alpha.begin(),alpha.end());
    exit(0);
  }
 else cout<<"You pressed "<<key<<endl;
}

int main(int argc, char** argv)
{
cout<<"Enter the string: ";
  cin>>inre;
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutCreateWindow("test");
 glutFullScreen();
 gluOrtho2D(0,1366,0,768);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}
