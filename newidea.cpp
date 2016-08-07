#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <GL/glut.h>
#include "adiprog.cpp"
#include <queue>
using namespace std;

int sides=10; //number of sides
const double pi = 3.14;
const double PI = 3.14;
const double TWOPI = 2*3.14;

 #define RADPERDEG 0.0174533
static int k=0;
string inre="(a+b)*.a.b.b";
vector<vector<double> > xycoordinates;
vector<vector<double> > linexycoordinates;
vector<vector<double> > curvexycoordinates;
//vector<vector<int> >transitions;
//vector<vector<char> >alpha;
int stateradius=20;
//int initial_state=0,final_state=5;
int initial_x=50;
int initial_y=384;
int length_of_edge=300;
int angle=180-30;
int height=10;


void Init()
{
   glClearColor(1.0,0.0,0.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,1.0,0.6);
}

void printingtransitions()
{
  cout<<"   \t";
  for(int k=0;k<cur;k++)
    cout<<k<<"\t";
  cout<<endl;
  for(int i=0;i<cur;i++)
  {
   cout<<"h"<<i<<"\t";
   for(int j=0;j<cur;j++)
     cout<<transitions[i][j]<<"\t";
   cout<<endl;
  }
}

void printingxycoordinates()
{
   for(int i=0;i<cur;i++)
  {
   for(int j=0;j<2;j++)
     cout<<xycoordinates[i][j]<<" ";
   cout<<endl;
  }
}

void printinglinexycoordinates()
{
   for(int i=0;i<cur;i++)
  {
   for(int j=0;j<4;j++)
     cout<<linexycoordinates[i][j]<<" ";
   cout<<endl;
  }
}

void printingalpha()
{
   for(int i=0;i<cur;i++)
  {
   for(int j=0;j<cur;j++)
     cout<<alpha[i][j]<<" ";
   cout<<endl;
  }
}


void testing3()
{
 for(int j=0;j<sides;j++)
   {
    vector<double> temp;
    for(int i=0;i<2;i++)
       temp.push_back(0.0);
    xycoordinates.push_back(temp);
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
   // glFlush();
}

void drawline(double x1,double y1,double x2,double y2)
{
   glBegin(GL_LINES);
     glVertex2f(x1,y1);
     glVertex2f(x2,y2);
   glEnd();
  // glFlush();
}

static int nooflines=0;
static int noofcurves=0;

#define DEG2RAD 3.14159/180.0
 
void drawEllipse(int x,int y,int width, int height)
{
      float theta;
      float angle_increment;
      float x1;
      float y1;
      angle_increment = float(PI / 500);
      glPushMatrix();
      glTranslatef(x+(width/2), y+(height/2), 0);   
      glBegin(GL_LINE_LOOP);
      for(theta = 0.0f; theta < TWOPI; theta += angle_increment) 
      {
         x1 = float ((width/2 * cos(theta)));
         y1 = float ((height/2 * sin(theta)));
	 glVertex2f(x1, y1);
      }
      glEnd();
      glPopMatrix();
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

void drawlines()
{
 double z=6;
 for(int i=0;i<nooflines;i++)
   {
    drawline(linexycoordinates[i][0],linexycoordinates[i][1],linexycoordinates[i][2],linexycoordinates[i][3]);
    drawarrow(linexycoordinates[i][0],linexycoordinates[i][1],z,linexycoordinates[i][2],linexycoordinates[i][3],z,10);
   }
}

void drawcurves()
{
 double z=6;
 for(int i=0;i<noofcurves;i++)
   {
    double x=(linexycoordinates[i][0]+linexycoordinates[i][2])/2;
    double y=(linexycoordinates[i][1]+linexycoordinates[i][3])/2;
    double width=(linexycoordinates[i][2]-linexycoordinates[i][0]);
    if(width<0) width*=-1;
    drawEllipse(x,y,width,height);
    drawarrow(linexycoordinates[i][0],linexycoordinates[i][1],z,linexycoordinates[i][2],linexycoordinates[i][3],z,10);
   }
}


void iterativedisplay()
{
 std::queue<int> myqueue;
myqueue.push(initial_state);
xycoordinates[initial_state][0]=initial_x;
xycoordinates[initial_state][1]=initial_y;
 Init();

for(int j=0;j<sides;j++)
  {
   int temp=myqueue.front();
   myqueue.pop();   
   for(int i=0;i<sides;i++)
    {
      if(transitions[temp][i]!=-2) 
       {
        myqueue.push(i);
        if(transitions[temp][i]==0) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+length_of_edge;
            xycoordinates[i][1]=xycoordinates[temp][1];
	    vector<double> temp2;
            temp2.push_back(xycoordinates[temp][0]);
	    temp2.push_back(xycoordinates[temp][1]);
            temp2.push_back(xycoordinates[i][0]);
            temp2.push_back(xycoordinates[i][1]);
            linexycoordinates.push_back(temp2);
	    temp2.erase(temp2.begin(),temp2.end());
	    nooflines++;
          }
        else if(transitions[temp][i]==-1) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+length_of_edge*cos(angle);
            xycoordinates[i][1]=xycoordinates[temp][1]-length_of_edge*sin(angle);
	    vector<double> temp2;
            temp2.push_back(xycoordinates[temp][0]);
	    temp2.push_back(xycoordinates[temp][1]);
            temp2.push_back(xycoordinates[i][0]);
            temp2.push_back(xycoordinates[i][1]);
            linexycoordinates.push_back(temp2);
	    temp2.erase(temp2.begin(),temp2.end());
	    nooflines++;
          }
        else if(transitions[temp][i]==1) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+length_of_edge*cos(angle);
            xycoordinates[i][1]=xycoordinates[temp][1]+length_of_edge*sin(angle);
	    vector<double> temp2;
            temp2.push_back(xycoordinates[temp][0]);
	    temp2.push_back(xycoordinates[temp][1]);
            temp2.push_back(xycoordinates[i][0]);
            temp2.push_back(xycoordinates[i][1]);
            linexycoordinates.push_back(temp2);
	    temp2.erase(temp2.begin(),temp2.end());
	    nooflines++;
          }
	else if(transitions[temp][i]==2)
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+length_of_edge;
            xycoordinates[i][1]=xycoordinates[temp][1];
	    vector<double> temp2;
            temp2.push_back(xycoordinates[temp][0]);
	    temp2.push_back(xycoordinates[temp][1]);
            temp2.push_back(xycoordinates[i][0]);
            temp2.push_back(xycoordinates[i][1]);
            curvexycoordinates.push_back(temp2);
	    temp2.erase(temp2.begin(),temp2.end());
	    noofcurves++;
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
         glColor3f(0.5,1.0,0.9); 
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
         glColor3f(0.5,0.3,1.); 
         BresenhamKrug(x1,y1,radius);
       }

    }
}


void drawalpha(double x,double y,char c)
{
 char ch[2];
 ch[0]=c;
 ch[1]='\0';
 output(x,y,1,1,1,GLUT_BITMAP_9_BY_15,ch);
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
   output(xycoordinates[i][0],xycoordinates[i][1],0,0,1,GLUT_BITMAP_TIMES_ROMAN_10,ch);
  }
}

void display()
{ 
Init();
if (k==0) 
  {
    retonfa(inre);
    sides=cur;
    testing3();
    printingtransitions();
    iterativedisplay();
    printingxycoordinates();
    printingalpha();
  }
    for(int i=0;i<inre.length();i++)
    {
      drawalpha(10+10*i,30,inre[i]);
    }
 drawlines();
 drawcurves();
 circle(stateradius);
 alphalines(stateradius);
 text();
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
