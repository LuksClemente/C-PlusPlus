#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat blackglass[] = { 0.0, 0.0, 0.0, 0.5 };
GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat direction[] = { 0.0, 0.0, 10.0, 1.0 };
GLfloat direction1[] = { 0.0,0.0, 10.0, 1.0 };

void prato(){

	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	glScalef(1, 0.05, 1);
	glutSolidSphere(1.0f, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 0.5);
	glutSolidTorus(0.5, 1, 20, 20);
	glPopMatrix();

}

void mesa(){

	//glRotatef(35.0, 1.0, 1.0, 0.0);

	 glColor3f(0.5, 0.35, 0.05);
	 glPushMatrix();
	 glScalef(0.5, 1.2, 0.5);
	 glTranslatef(1, 0, 2);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glScalef(0.5, 1.2, 0.5);
	 glTranslatef(-2, 0, 2);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glScalef(0.5, 1.2, 0.5);
	 glTranslatef(1, 0, 5);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glScalef(0.5, 1.2, 0.5);
	 glTranslatef(-2, 0, 5);
	 glutSolidCube(1);
	 glPopMatrix();

	 glPushMatrix();
	 glScalef(8, 0.3, 2.5);
	 glTranslatef(0.05, 1.9, 0.8);
	 glutSolidCube(1);
	 glPopMatrix();

}

void cadeira(){

	//pego no github =(
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);

	//Front
	//
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	//Right
	//
	glVertex3f(2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -0.2f, 2.0f);

	//Back
	//;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//Left
	;
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	//top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, 2.0f);
	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -3.0f, 1.6f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, 1.6f);
	glVertex3f(1.8f, -0.2f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.2f);
	glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.4f, -0.2f, 1.6f);
	glVertex3f(1.4f, -0.2f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.2f);
	glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -3.0f, -1.6f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.8f, -0.2f, -1.6f);
	glVertex3f(1.8f, -0.2f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.2f);
	glVertex3f(1.8f, -3.0f, -1.6f);

	//left
		//
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(1.4f, -0.2f, -1.6f);
	glVertex3f(1.4f, -0.2f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.2f);
	glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -3.0f, 1.6f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//back
	//;
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);

	//right

	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, 1.6f);
	glVertex3f(-1.8f, -0.2f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.2f);
	glVertex3f(-1.8f, -3.0f, 1.6f);

	//left
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.4f, -0.2f, 1.6f);
	glVertex3f(-1.4f, -0.2f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.2f);
	glVertex3f(-1.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);

	//back
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -3.0f, -1.6f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//right
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.8f, -0.2f, -1.6f);
	glVertex3f(-1.8f, -0.2f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.2f);
	glVertex3f(-1.8f, -3.0f, -1.6f);

	//left
	glColor3f(0.5, 0.35, 0.05);
	glVertex3f(-1.4f, -0.2f, -1.6f);
	glVertex3f(-1.4f, -0.2f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.2f);
	glVertex3f(-1.4f, -3.0f, -1.6f);

	//chair back
	//front
	//chair upper part
	glColor3f(0, 1, 0);
	glVertex3f(-1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 1.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	//chair upper side
	glColor3f(0, 1, 0);
	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 1.2f, -1.80f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	//chair upper top
	glColor3f(0, 1, 0);
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 1.2f, -1.80f);
	glVertex3f(-1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -0.6f);
	glVertex3f(1.8f, 1.2f, -1.8f);

	// chair top legs

	glColor3f(0.5, 0.35, 0.05);
	//side walls
	glVertex3f(-1.2f, 1.2f, -1.20f);
	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-.8f, 1.2f, -1.20f);
	glVertex3f(-.8f, 1.2f, -0.6f);
	glVertex3f(-.8f, .2f, -0.6f);
	glVertex3f(-.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glVertex3f(-1.2f, 1.2f, -1.2f);
	glVertex3f(-0.8f, 1.2f, -1.2f);
	glVertex3f(-0.8f, .2f, -1.2f);
	glVertex3f(-1.2f, .2f, -1.2f);

	glVertex3f(-1.2f, 1.2f, -0.6f);
	glVertex3f(-0.8f, 1.2f, -0.6f);
	glVertex3f(-0.8f, .2f, -0.6f);
	glVertex3f(-1.2f, .2f, -0.6f);

	//side walls
	glVertex3f(1.2f, 1.2f, -1.20f);
	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(.8f, 1.2f, -1.20f);
	glVertex3f(.8f, 1.2f, -0.6f);
	glVertex3f(.8f, .2f, -0.6f);
	glVertex3f(.8f, .2f, -1.2f);

	//froont walls adnd back walls
	glColor3f(0, 1, 0);
	glVertex3f(1.2f, 1.2f, -1.2f);
	glVertex3f(0.8f, 1.2f, -1.2f);
	glVertex3f(0.8f, .2f, -1.2f);
	glVertex3f(1.2f, .2f, -1.2f);

	glVertex3f(1.2f, 1.2f, -0.6f);
	glVertex3f(0.8f, 1.2f, -0.6f);
	glVertex3f(0.8f, .2f, -0.6f);
	glVertex3f(1.2f, .2f, -0.6f);

	//glVertex3f()

	glEnd();
}



void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0,0,10,0,0,0,0,1,0);
  glPushMatrix();

  glEnable(GL_LIGHT0);

  glRotatef(35.0, 1.0, 1.0, 0.0);

  glPushMatrix();
  mesa();
  glPopMatrix();

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);

  glPushMatrix();
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glScalef(0.4,0.4,0.4);
  glTranslatef(4, 2, 3);
  prato();
  glPopMatrix();

  glPushMatrix();
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glScalef(0.4,0.4,0.4);
  glTranslatef(-4, 2, 3);
  prato();
  glPopMatrix();

  glPushMatrix();
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glScalef(0.4,0.4,0.4);
  glTranslatef(-4, 2, 6.5);
  prato();
  glPopMatrix();

  glPushMatrix();
  //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glScalef(0.4,0.4,0.4);
  glTranslatef(4, 2, 6.5);
  prato();
  glPopMatrix();

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackglass);
  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);

  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  glTranslatef(-3,0,0);
  cadeira();
  glPopMatrix();
  glFlush();

  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  glTranslatef(3,0,0);
  cadeira();
  glPopMatrix();
  glFlush();

  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  glTranslatef(-3,0,7);
  glRotatef(180,0,1,0);
  cadeira();
  glPopMatrix();

  glPushMatrix();
  glScalef(0.5,0.5,0.5);
  glTranslatef(3,0,7);
  glRotatef(180,0,1,0);
  cadeira();
  glPopMatrix();;

  glPopMatrix();
  glFlush();
}


void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  GLfloat aspect = GLfloat(w) / GLfloat(h);
  glLoadIdentity();

 /*if (w <= h) {
    // width is smaller, so stretch out the height
    glOrtho(-4.5, 4.5, -4.5/aspect, 4.5/aspect, -7.0, 7.0);
  } else {
    // height is smaller, so stretch out the width
    glOrtho(-4.5*aspect, 4.5*aspect, -4.5, 4.5, -7.0, 7.0);
  }*/


  gluPerspective(60, aspect, 0.01, 20);


}


void init() {

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
  //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
 //glMaterialf(GL_FRONT, GL_SHININESS, 30);

  glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, yellow);
  glLightfv(GL_LIGHT1, GL_SPECULAR, white);
  glLightfv(GL_LIGHT1, GL_POSITION, direction);

  //glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  //glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
  //glLightfv(GL_LIGHT1, GL_SPECULAR, white);
  //glLightfv(GL_LIGHT1, GL_POSITION, direction1);

  glLightfv(GL_LIGHT2, GL_AMBIENT, black);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, pink);
  glLightfv(GL_LIGHT2, GL_SPECULAR, white);
  glLightfv(GL_LIGHT2, GL_POSITION, direction1);

  glLightfv(GL_LIGHT3, GL_AMBIENT, black);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, pink2);
  glLightfv(GL_LIGHT3, GL_SPECULAR, white);
  glLightfv(GL_LIGHT3, GL_POSITION, direction1);

  //glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
