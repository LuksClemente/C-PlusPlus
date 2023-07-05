#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int shoulder = 0, elbow = 0, polegar = 0, indicador = 0, medio = 0, eixoy = 0.0;

void init(void){

 glClearColor (0.0, 0.0, 0.0, 0.0);

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);

}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glPushMatrix();


  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  glTranslatef (1.0, 0.0, 0.0);


  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glColor3f(0,0,1);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glutWireCube (1.0);
  glPopMatrix();

  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);

  glPushMatrix();
  glTranslatef (1.0, 0.0, 0.0);
  glScalef (2.0, 0.4, 1.0);
  glColor3f(0,0,1);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glutWireCube (1.0);
  glPopMatrix();

  glTranslatef (2.0, 0.0, 0.0);

  glPushMatrix();
  glTranslatef (0.0, -0.2, 0.0);
  glRotatef ((GLfloat) polegar, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.1, 0.5);
  glColor3f(1,0,0);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glutWireCube (1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef (0.0, 0.2, 0.2);
  glRotatef ((GLfloat) medio, 0.0, 0.0, 1.0);
  glRotatef (90, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.1, 0.4);
  glColor3f(1,0,0);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glColor3f(1,0,0);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glutWireCube (1.0);
  glPopMatrix();


  glPushMatrix();
  glTranslatef (0.0, 0.2, -0.2);
  glRotatef ((GLfloat) indicador, 0.0, 0.0, 1.0);
  glRotatef (90, 0.0, 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef (0.5, 0.1, 0.4);
  glColor3f(1,0,0);
  glutSolidCube (1.0);
  glColor3f(0,0,0);
  glutWireCube (1.0);
  glPopMatrix();



  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(85, (GLfloat) w/(GLfloat) h, 0.1, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //glTranslatef (0, 0.0, -5);
  gluLookAt(0,0,5,0,0,0,0,1,0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;

  case 'i':
      indicador = (indicador + 5) % 360;
      glutPostRedisplay();
      break;
    case 'I':
      indicador = (indicador - 5) % 360;
      glutPostRedisplay();
      break;

    case 'm':
        medio = (medio + 5) % 360;
        glutPostRedisplay();
        break;
      case 'M':
        medio = (medio - 5) % 360;
        glutPostRedisplay();
        break;

      case 'p':
          polegar = (polegar + 5) % 360;
          glutPostRedisplay();
          break;
        case 'P':
          polegar = (polegar - 5) % 360;
          glutPostRedisplay();
          break;

        case 'y':
        	eixoy = (eixoy + 5) % 360;
            glutPostRedisplay();
            break;
          case 'Y':
        	  eixoy = (eixoy - 5) % 360;
            glutPostRedisplay();
            break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Braco Robo");
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
