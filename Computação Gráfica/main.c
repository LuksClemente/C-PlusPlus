/* A simple program to show how to set up an X window for OpenGL rendering.
 * X86 compilation: gcc -o -L/usr/X11/lib   main main.c -lGL -lX11
 * X64 compilation: gcc -o -L/usr/X11/lib64 main main.c -lGL -lX11
 */
#include <stdio.h>
#include <stdlib.h>

#include <GL/glx.h>    /* this includes the necessary X headers */
#include <GL/gl.h>

#include <X11/X.h>    /* X11 constant (e.g. TrueColor) */
#include <X11/keysym.h>

#include <math.h>
//#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int numFrame = 0;
GLuint texID[6];

GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat pink[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat pink2[] = { 0.5, 1.0, 0.5, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat direction[] = { 0.0, 0.0, 10.0, 1.0 };
GLfloat direction1[] = { 0.0,1.0, 15.0, 1.0 };

char* textureFileNames[6] = {
            "texturas/spidertexture.jpg"
       };

void loadTextures() {
	int width, height, nrChannels;
	unsigned char *data;

	glGenTextures(6, texID);

	for(int i = 0; i < 6;i++)
	{
		glBindTexture(GL_TEXTURE_2D, texID[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		data = stbi_load(textureFileNames[i], &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);


		}
		else
		{
			 printf("Failed to load texture\n");
		}
		stbi_image_free(data);
	}

}

void primitivaC(){
	glutSolidSphere(10,0,0);
}

void cabeca(){
    glBindTexture( GL_TEXTURE_2D, texID[0] );
	glPushMatrix();
	primitivaC();
	glPopMatrix();
}

void corpo(){
    glBindTexture( GL_TEXTURE_2D, texID[0] );
	glPushMatrix();
	glScalef(2,2,2);
	primitivaC();
	glPopMatrix();
}

void olho(){
    glPushMatrix();
    glColor3f(0,0,0);
    glScalef(0.2, 0.2, 0.2)
	primitivaC();
	glPopMatrix();
}

void pata(){
    glScalef(0.1,0.5,2);
	glutSolidCube(1);
}

void aranha(){

    glPushMatrix();
    corpo();
	glPopMatrix();

	glPushMatrix();
    cabeca();
	glPopMatrix();

	glPushMatrix();
    olho();
	glPopMatrix();

	glPushMatrix();
    olho();
	glPopMatrix();

	glPushMatrix();
    pata();
	glPopMatrix();

	glPushMatrix();
    pata();
	glPopMatrix();

	glPushMatrix();
    pata();
	glPopMatrix();

	glPushMatrix();
    pata();
	glPopMatrix();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0,20,0,0,1,0,1,1,1);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	glBindTexture( GL_TEXTURE_2D, texID[0] );
	glPushMatrix();
	primitivaC();
	glPopMatrix();

}

void doFrame(int v) {
    numFrame++;

    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
    glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	GLfloat aspect = GLfloat(w) / GLfloat(h);
	glLoadIdentity();
	gluPerspective (60,aspect, 0.1, 20);

}


void init() {

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1,1,1,1);


	glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, direction);

	glLightfv(GL_LIGHT1, GL_AMBIENT, white);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightfv(GL_LIGHT1, GL_POSITION, direction1);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_NORMALIZE);

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Prova Final");

	init();
	loadTextures();
	glutDisplayFunc(display);

	glutTimerFunc(20,doFrame,0);
	glutReshapeFunc(reshape);

	glutMainLoop();
}
