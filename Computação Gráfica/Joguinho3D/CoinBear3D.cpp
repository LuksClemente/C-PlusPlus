#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
  GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
  GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
  GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat direction[] = { 0.0, 0.0, 10.0, 1.0 };
  GLfloat direction1[] = { 0.0,0.0, 10.0, 1.0 };

void primitivaQ(){
	glutSolidCube(1);
}

void primitivaC(){
	glutSolidSphere(10,0,0);
}


void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
   gluLookAt(0,0,10,0,0,0,0,1,0);
  glPushMatrix();

  //glEnable(GL_LIGHT1);
  //glEnable(GL_LIGHTING);



  // Rotate the scene so we can see the tops of the shapes.
  //glRotatef(35.0, 1.0, 1.0, 0.0);

  glPushMatrix();
  primitivaC();
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
  gluPerspective (60,aspect, 0.1, 20);


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

