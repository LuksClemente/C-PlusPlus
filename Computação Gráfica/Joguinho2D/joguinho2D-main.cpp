#include <GL/glut.h>
#include <cstdlib>
#include <math.h>
#include <iostream>

// variáveis iniciais
const double PI = 3.141592654;

int numFrame = 0;

//float minX = 0.5f;
float minX = -50.0f;
//float maxX = 800.0f;
float maxX = 100.0f;

bool jump = false;

float objectX = 0.5f;
float objectY = -0.2f;

float objectSpeed = 0.7f;

float objectDir = 0.0f;

char string[100];

int playerScore = 0;

void moveObjectX(float objectSpeedLocal, bool jump) {

	float dX = objectSpeedLocal * cosf(objectDir * PI / 180.0f);
    float dY = objectSpeedLocal * sinf(objectDir * PI / 180.0f);
    objectX += dX;
    objectY += dY;

    if (objectX < minX) {

    	objectX = maxX;

    }

    if (objectX > maxX) {

    	//objectX = minX;
    	objectX = minX;

    }
}

void moveObjectY(float objectSpeedLocal, bool jump){

	if (jump == false){

		jump = true;

		float dY = objectSpeedLocal * sinf(objectDir * PI / 180.0f);

		while (objectY < 10 && jump == true){

			objectY += dY;

			if (objectY == 10){

				objectY = 10;

			}
        }
    }
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:

        	moveObjectX(objectSpeed * (-1), jump);
        	break;

        case GLUT_KEY_RIGHT:

        	moveObjectX(objectSpeed, jump);
        	break;

        case GLUT_KEY_UP:

        	//moveObjectY(objectSpeed, jump);
        	jump = true;
            break;

        case GLUT_KEY_DOWN:

        	break;

    }

    glutPostRedisplay();
}




void primitivaQ() {

	glBegin(GL_POLYGON);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glEnd();

	glFlush();
}

void primitivaT() {

	glBegin(GL_TRIANGLES);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(15.0, 30.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();

	glFlush();
}

void primitivaC(double rad){

	int d;

	glBegin(GL_POLYGON);
	for(d = 0; d<=32;d++){
		double angle = (2*PI/32) * d;
		glVertex2d(rad*cos(angle),rad*sin(angle));
	}
	glEnd();
}

void sol(){

	int i;
	glColor3f(1,1,0);

	for(i=0;i<13;i++){
		glRotatef(360/13,0,0,1);
		glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(0.75f,0);
		glEnd();
	}
	primitivaC(5);
	glColor3f(0,0,0);
}

void montanhaA(){

	glPushMatrix();
	glColor3f(0,0,0.75);
	primitivaT();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);
	glVertex3f(15,30,0);
	glVertex3f(13.5,27,0);
	glVertex3f(13.3,25,0);
	glVertex3f(15,26,0);
	glVertex3f(15.7,25,0);
	glVertex3f(16.5,27,0);
	glEnd();
	glPopMatrix();

	glFlush();
}

void morro(){

	glPushMatrix();
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(20, 10,0);
	glVertex3f(60, 10, 0);
	glVertex3f(50, 15, 0);
	glVertex3f(30,15,0);
	glEnd();
	glPopMatrix();

	glFlush();
}

void gramaA(){
	glPushMatrix();
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(0, 20, 0);
	glVertex3f(800, 20, 0);
	glVertex3f(800,0,0);
	glEnd();
	glPopMatrix();

	glFlush();
}

void gramaB(){

	glPushMatrix();
	glColor3f(0.5,1,0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0,20,0);
	glVertex3f(0, 25, 0);
	glVertex3f(800, 25, 0);
	glVertex3f(800,20,0);
	glEnd();
	glPopMatrix();

	glFlush();
}

void arvoreA(){

	glPushMatrix();
	glColor3f(0,0.6,0);
	glTranslatef(10,37,0);
	primitivaC(8);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.3,1.5,1);
	glTranslatef(18,2,0);
	primitivaQ();
	glPopMatrix();

	glFlush();
}

void arvoreB(){

	glPushMatrix();
	glColor3f(0,0.9,0);
	glScalef(1,2.3,1);
	glTranslatef(-5,-7,0);
	primitivaT();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.3,1.5,1);
	glTranslatef(18,2,0);
	primitivaQ();
	glPopMatrix();

	glFlush();
}

void mainBear(){

	//Torso
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(1.5,0.9,1);
	primitivaQ();
	glPopMatrix();

	//Perna1
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4,0.7,1);
	glTranslatef(32, -2, 0);
	primitivaQ();
	glPopMatrix();

	//Perna2
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4, 0.7, 1);
	glTranslatef(32, -2, 0);
	primitivaQ();
	glPopMatrix();

	//Perna3
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4, 0.7, 1);
	glTranslatef(47, -2, 0);
	primitivaQ();
	glPopMatrix();

	//Perna4
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4, 0.7, 1);
	glTranslatef(47, -2, 0);
	primitivaQ();
	glPopMatrix();

	//Cabeça
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4, 0.5, 1);
	glTranslatef(63, 17, 0);
	primitivaQ();
	glPopMatrix();

	//Nariz
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glScalef(0.4, 0.2, 1);
	glTranslatef(65.7, 58, 0);
	primitivaQ();
	glPopMatrix();

	//Rabo
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	glTranslatef(15, 15, 0);
	primitivaC(2);
	glPopMatrix();



	glFlush();
}

/*void drawText(char* string, int x, int y)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y,0);
	  glScalef(0.1,-0.1,1);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();

}*/

// Drawing routine.
void drawScene(void) {

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	//sprintf(string,"Score: %d ", playerScore);
	//drawText(string,0,0);

	glPushMatrix();
	glScalef(5,2.5,1);
	glTranslatef(-10,-10,0);
	montanhaA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glScalef(5, 2.46, 1);
	glTranslatef(-1, -10, 0);
	montanhaA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glScalef(1.7, 1.2, 1);
	glTranslatef(-30, 10.8, 0);
	morro();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glScalef(1.7, 1.2, 1);
	glTranslatef(0, 10.8, 0);
	morro();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	gramaA();
	glPopMatrix();
	glLoadIdentity();
	glPushMatrix();
	gramaB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(1,20,0);
	glScalef(0.3,0.3,1);
	arvoreA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(15,25.5,0);
	glScalef(0.3,0.3,1);
	arvoreA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(30, 25.5, 0);
	glScalef(0.3, 0.3, 1);
	arvoreB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(27, 23, 0);
	glScalef(0.3, 0.3, 1);
	arvoreB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(50, 24, 0);
	glScalef(0.3, 0.3, 1);
	arvoreB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(55, 22.5, 0);
	glScalef(0.3, 0.3, 1);
	arvoreA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(63, 20, 0);
	glScalef(0.3, 0.3, 1);
	arvoreB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(7, 23, 0);
	glScalef(0.3, 0.3, 1);
	arvoreB();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(59, 22.5, 0);
	glScalef(0.3, 0.3, 1);
	arvoreA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(70, 21.5, 0);
	glScalef(0.3, 0.3, 1);
	arvoreA();
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(10,70,0);
	sol();
	glPopMatrix();

	/*glLoadIdentity();
	glPushMatrix();
	mainBear();
	glPopMatrix();*/

	if(jump){

		glPushMatrix();
		glTranslatef(0, objectY + 15.0f, 0);

	}

	glTranslatef(objectX, 0, 0);
	mainBear();

	if(jump){

		jump = false;
		glPopMatrix();

	}


	glutSwapBuffers();


	glutPostRedisplay();
}

// Initialization routine.
void Init(void) {
	glClearColor(0.75, 0.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(minX, maxX, -1.0, 4.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void doFrame(int v) {
    numFrame++;
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
}

// OpenGL window reshape routine.
void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Main routine.
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("trabalho1");

	Init();

	glutDisplayFunc(drawScene);

	glutSpecialFunc(specialKeys);

	glutTimerFunc(20,doFrame,0);

	glutReshapeFunc(resize);

	//Init();

	glutMainLoop();
}
