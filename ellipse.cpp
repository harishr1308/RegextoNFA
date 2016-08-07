#include <GL/glut.h>
#include <math.h>
using namespace std;

const float DEG2RAD = 3.14159/180.0;
const double PI = 3.14;
const double TWOPI = 2*3.14;

 
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
 
 
void display(void)
{
 glClearColor(1.0,0.0,0.0,0.0);
 glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0,1.0,1.0);
 
	drawEllipse(50,50,10,5);
 
	glFlush();
}
 

void setupEnv(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 400.0, 0.0, 400.0, 1.0, -1.0);
 
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
}
int main(int argc, char** argv)
{
 glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("GL01");
	glutInitWindowSize(400, 400);
	glutDisplayFunc(display);
	 gluOrtho2D(0,100,0,100);
	//setupEnv();
	glutMainLoop();
return 0;
}
