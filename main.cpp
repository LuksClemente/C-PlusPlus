// https://cs.lmu.edu/~ray/notes/openglexamples/
// g++ litsolids.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o r.exe
//
// This program shows three cyan objects illuminated with a single yellow
// light source.  It illustrates several of the lighting parameters.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Clears the window and depth buffer and draws three solids.
//
// The solids are placed so that they either sit or float above the x-z plane;
// therefore note one of the first things that is done is to rotate the whole
// scene 20 degrees about x to turn the top of the scene toward the viewer.
// This lets the viewer see how the torus goes around the cone.
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();

  // Rotate the scene so we can see the tops of the shapes.
  glRotatef(35.0, 1.0, 1.0, 0.0);

  glColor3f(1, 0, 0);
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
  glScalef(3, 0.5, 2.5);
  glTranslatef(-0.1, 1.6, 0.8);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.3, 1.4, 2);
  glutSolidSphere(0.4, 30, 30);

  glPopMatrix();
  glFlush();
}

// We don't want the scene to get distorted when the window size changes, so
// we need a reshape callback.  We'll always maintain a range of -2.5..2.5 in
// the smaller of the width and height for our viewbox, and a range of -10..10
// for the viewbox depth.

//PARAMETROS glOrtho
//left, right :Specify the coordinates for the left and right vertical clipping planes.
//bottom, top :Specify the coordinates for the bottom and top horizontal clipping planes.
//nearVal, farVal:Specify the distances to the nearer and farther depth clipping planes. These values are negative if the plane is to be behind the viewer.

void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  GLfloat aspect = GLfloat(w) / GLfloat(h);
  glLoadIdentity();

 if (w <= h) {
    // width is smaller, so stretch out the height
    glOrtho(-2.5, 2.5, -2.5/aspect, 2.5/aspect, -10.0, 10.0);
  } else {
    // height is smaller, so stretch out the width
    glOrtho(-2.5*aspect, 2.5*aspect, -2.5, 2.5, -10.0, 10.0);
  }


  //gluPerspective (60,aspect, 0.1, 15);

}

// Performs application specific initialization.  It defines lighting
// parameters for light source GL_LIGHT0: black for ambient, yellow for
// diffuse, white for specular, and makes it a directional source
// shining along <-1, -1, -1>.  It also sets a couple material properties
// to make cyan colored objects with a fairly low shininess value.  Lighting
// and depth buffer hidden surface removal are enabled here.
void init() {

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(90.0, 1.0, 0.0, 0.0);
  //gluLookAt(0, 2.5, 0, 0,0,0, 0, 0, -1);


  GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
  GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
  GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat direction[] = { 0.0, -10.0, 0.0, 1.0 };
  GLfloat direction1[] = { 0.0, 10.0, 0.0, 1.0 };

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);

  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, yellow);
  glLightfv(GL_LIGHT0, GL_SPECULAR, white);
  glLightfv(GL_LIGHT0, GL_POSITION, direction);

  glLightfv(GL_LIGHT1, GL_AMBIENT, black);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
  glLightfv(GL_LIGHT1, GL_SPECULAR, white);
  glLightfv(GL_LIGHT1, GL_POSITION, direction1);

  glEnable(GL_LIGHTING);                // so the renderer considers light
  glEnable(GL_LIGHT0);                  // turn LIGHT0 on
  glEnable(GL_LIGHT1);
  glEnable(GL_DEPTH_TEST);              // so the renderer considers depth

}

// The usual application statup code.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Cyan Shapes in Yellow Light");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
