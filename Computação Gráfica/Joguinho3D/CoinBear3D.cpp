#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <iostream>
#endif

using namespace std;

GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat direction[] = { 0.0, 0.0, 10.0, 1.0 };
GLfloat direction1[] = { 0.0,0.0, 10.0, 1.0 };

float startX = 0, startY = 0, startZ = 0;
float objectSpeed = 1.5f;
float objectX = 0, objectY = 0;
float olhoX = 0, olhoZ = 0,olhoY = 10, centroY=1, upX=1,upY=1,upZ=1;

/*void moveObjectForward(float objectSpeedLocal){

}*/

void primitivaQ(){
	glutSolidCube(1);
}

void primitivaC(){
	glutSolidSphere(10,0,0);
}

void primitivaT(){
	glutSolidTorus(0.5, 1, 20, 20);
}

//callback do teclado
//trata eventos das setinhas quando pressionadas
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:

        	//moveObjectX(objectSpeed * (-1));
        	break;

        case GLUT_KEY_RIGHT:

        	//moveObjectX(objectSpeed);
        	break;

        case GLUT_KEY_UP:
        	cout << "teste" << endl;
        	if(olhoY == 10){
        		olhoY = 0;
        		olhoX = 3;
        		olhoZ = 0;
        		centroY = 0;
        		upX=1;
        		upY=0;
        		upZ=0;
        	}else if(olhoY == 0){
        		olhoY = 10;
        		olhoX = 0;
        		centroY = 1;
        		upX=1;
        		upY=1;
        		upZ=1;
        	}
            break;

        case GLUT_KEY_DOWN:

        	//if(run){

        		//run = false;
        		//objectSpeed = 0.7f;
        	//}
        	//else{

        		//run = true;
        		//objectSpeed = 1.4f;
        	//}

        	break;



    }

    //redesenha a cena
    glutPostRedisplay();
}

void moeda(){
	  glPushMatrix();
	  glTranslatef(0,-0.03,0);
	  glScalef(0.2,0.05,0.2);
	  glutSolidSphere(1.0,30,30);
	  glPopMatrix();
	  glPushMatrix();
	  glRotatef(90,1,0,0);
	  glScalef(0.35,0.35,0.1);
	  glutSolidTorus(0.5,1,20,20);
	  glPopMatrix();
}

void chao(){

	//glRotatef(35.0, 1.0, 1.0, 0.0);

	 glPushMatrix();
	 glScalef(20, 0.1, 20);
	 glColor3f(1,1,1);
	 //glTranslatef(0.05, 1.9, 0.8);
	 glutSolidCube(1);
	 glPopMatrix();

}

void arvore(){
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(1.2,3,1.2);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,1,0);
	glScalef(2.5,2.5,2.5);
	glTranslatef(0,1,0);
	primitivaQ();
	glPopMatrix();

}

void urso(){
	/*glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(0.5,1.3,0.5);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(0.5,1.3,0.5);
	glTranslatef(3,0,0);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(0.5,1.3,0.5);
	glTranslatef(0,0,3);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(0.5,1.3,0.5);
	glTranslatef(3,0,3);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(2.5,1,2.5);
	glTranslatef(0.3,0,0);
	primitivaQ();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5,0.35,0.05);
	glScalef(1,1,1);
	glTranslatef(0,0,5);
	primitivaQ();
	glPopMatrix();*/

	glPushMatrix();
	glColor3f(0.5,0.35,0.05);
	primitivaQ();
	glPopMatrix();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(olhoX,olhoY,olhoZ,0,centroY,0,upX,upY,upZ);
	glPushMatrix();

	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHTING);

	// Rotate the scene so we can see the tops of the shapes.
	//glRotatef(35.0, 1.0, 1.0, 0.0);

	glPushMatrix();
	chao();
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(0,1.5,0);
	arvore();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,1.5,0);
	arvore();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1.5,3);
	arvore();
	glPopMatrix();*/

	glPushMatrix();
	urso();
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
	glutCreateWindow("CoinBear3D");
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
