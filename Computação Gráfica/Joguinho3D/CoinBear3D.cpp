#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
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

int numFrame = 0;
int playerScore = 0;
float minX = -10, maxX =10;
float minZ = -10, maxZ =10;
float startX = 0, startY = 0, startZ = 0;
float objectSpeed = 1.0f, objectDir = 0.0f;
float objectX = 0, objectZ = 0;
float olhoX = 0, olhoZ = 0,olhoY = 20, centroX = 0, centroY=1, centroZ = 0, upX=1,upY=1,upZ=1;
const double PI = 3.141592654;
bool gameOver = false;
bool bigornaVisivel = false;
bool moedaVisivel = false;
bool bigornaPega = false;
bool moedaPega = false;
float moedaX = 0;
float moedaY = 15;
float moedaZ = 0;
float bigornaX = 0;
float bigornaY = 5;
float bigornaZ = 0;
bool pov = false;
float aux = 0;

GLuint texID[6];  // Texture ID's for the three textures.

char* textureFileNames[6] = {   // file names for the files from which texture images are loaded
            "texturas/texturaferro.jpg",
			"texturas/texturafolhas.jpg",
			"texturas/texturagrama.jpg",
			"texturas/texturaouro.jpg",
			"texturas/texturatronco.jpg",
			"texturas/texturaurso.jpg"
       };

void loadTextures() {
	int width, height, nrChannels;
	unsigned char *data;

	glGenTextures(6, texID);

	for(int i = 0; i < 6;i++)
	{
		glBindTexture(GL_TEXTURE_2D, texID[i]);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture

		data = stbi_load(textureFileNames[i], &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			//glGenerateMipmap(GL_TEXTURE_2D);
			//glTexParameteri  (GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE );
		}
		else
		{
			 printf("Failed to load texture\n");
		}
		stbi_image_free(data);
	}

}


void moveObjectX(float objectSpeedLocal) {

    float dX = objectSpeedLocal * cosf(objectDir * PI / 180.0f);

    objectX += dX;


    if (objectX < minX) {

        objectX = maxX;

    }

    if (objectX > maxX) {

        objectX = minX;

    }

}

void moveObjectZ(float objectSpeedLocal){
	 float dz = objectSpeedLocal * cosf(objectDir * PI / 180.0f);

	    objectZ += dz;

	    if (objectZ < minZ) {

	        objectZ = maxZ;

	    }

	    if (objectZ > maxZ) {

	        objectZ = minZ;

	    }
}

void primitivaQ(){
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	//glEnd();
	//glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	//glEnd();
	//glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	//glEnd();
	//glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5,-0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	//glEnd();
	//glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5,0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	//glEnd();
	//glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5,0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
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

        	cout << "Rodei para a esquerda" << endl;
        	aux += 1;
        	//moveObjectX(objectSpeed);
        	break;

        case GLUT_KEY_RIGHT:
        	aux-=1;
        	cout << "Rodei para a direita" << endl;
        	//moveObjectX(objectSpeed * (-1));
        	break;

        case GLUT_KEY_UP:
        	moveObjectZ(objectSpeed*(1));
        	break;

        case GLUT_KEY_DOWN:
        	moveObjectZ(objectSpeed*(-1));
        	break;
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

//função que escreve a string indicada na tela
void drawText(const string& text, float x, float y) {

	glRasterPos2f(x, y);

    for (const char& c : text) {

        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void primitivaMoeda(){
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

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    	case 'c':
    		cout << "teste" << endl;
            if(olhoY == 20){
            	olhoY = 1.5;
            	olhoX = objectX;
            	olhoZ = objectZ;
            	centroX = cos(aux * PI/180);
            	centroY = 0;
            	upX=2;
            	upY=2;
            	upZ=2;
            	if(pov == true){
            		pov = false;
            	}else{
            		pov = true;
            	}
            }else if(olhoY == 1.5){
            	olhoY = 20;
            	olhoX = 0;
            	centroY = 1;
            	upX=1;
            	upY=1;
            	upZ=1;
            }
            break;

    }

    //redesenha a cena
    glutPostRedisplay();
}

void chao(){

	//glRotatef(35.0, 1.0, 1.0, 0.0);

	glPushMatrix();
	glScalef(20, 0.1, 20);
	glColor3f(0,0.5,0);
	//glTranslatef(0.05, 1.9, 0.8);
	glutSolidCube(1);
	glPopMatrix();

}

void arvore(){

	glScalef(0.5,0.5,0.5);

	glBindTexture( GL_TEXTURE_2D, texID[4] );
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glScalef(1.2,3,1.2);
	primitivaQ();
	glPopMatrix();

	glBindTexture( GL_TEXTURE_2D, texID[1] );
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

void moeda(){

	moedaY = moedaY - 0.3;

	glPushMatrix();
	glColor3f(1,0.8,0);
	primitivaMoeda();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8, 0.8, 1);
	glColor3f(1,1,0);
	primitivaMoeda();
	glColor3f(0,0,0);
	glPopMatrix();

	 if(moedaY <= 0){

		 moedaVisivel = false;
	     moedaY = 60;
	 }
}

void bigorna(){

	bigornaY = bigornaY - 0.3;

	glPushMatrix();
	glColor3f(0.4,0.4,0.4);
	primitivaQ();
	glPopMatrix();

	if(bigornaY <= 0){

		bigornaVisivel = false;
		bigornaY = 60;
	}

}

//função que trata a colisão do personagem com o objeto moeda
void pegaMoeda(){

	if(((moedaX <= objectX + 3)&&(moedaX >= objectX + 1))&&(moedaY <= 1)){

		moedaPega = true;
		playerScore++;
		moedaVisivel = false;
	}

}

//função que trata a colisão do personagem com o objeto bigorna
void pegaBigorna(){

	if(((bigornaX <= objectX + 1)&&(bigornaX >= objectX - 1))&&(bigornaY <= 1)){

		bigornaPega = true;
		playerScore--;
		bigornaVisivel = false;
	}

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glEnable(GL_COLOR_MATERIAL);
	//gluLookAt(olhoX, olhoY, olhoZ, objectX, centroY,objectZ, upX,upY,upZ);
	if(pov == false){
		gluLookAt(olhoX,olhoY,olhoZ,0,centroY,0,upX,upY,upZ);
	}else{
		gluLookAt(objectX,olhoY,objectZ,aux,centroY,0,upX,upY,upZ);
	}
	glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
	//gluLookAt(olhoX + objectX,olhoY,olhoZ + objectZ,0,centroY,0,upX,upY,upZ);
	//gluLookAt(objectX, olhoY, objectZ, objectX, centroY, objectZ - 10, upX, upY, upZ);
	//gluLookAt(0, olhoY, 10, objectX, centroY, objectZ, upX, upY, upZ);
	glPushMatrix();

	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHTING);

	// Rotate the scene so we can see the tops of the shapes.
	//glRotatef(35.0, 1.0, 1.0, 0.0);

	glBindTexture( GL_TEXTURE_2D, texID[2] );
	glPushMatrix();
	chao();
	glPopMatrix();

	//glBindTexture( GL_TEXTURE_2D, texID[1] );
	glPushMatrix();
	glTranslatef(0,1.5,0);
	arvore();
	glPopMatrix();

	//glBindTexture( GL_TEXTURE_2D, texID[1] );
	glPushMatrix();
	glTranslatef(3,1.5,0);
	arvore();
	glPopMatrix();

	//glBindTexture( GL_TEXTURE_2D, texID[1] );
	glPushMatrix();
	glTranslatef(0,1.5,3);
	arvore();
	glPopMatrix();

	glBindTexture( GL_TEXTURE_2D, texID[5] );
	glPushMatrix();
	glTranslatef(objectX,0.5,objectZ);
	urso();
	glPopMatrix();

	//desenha a moeda
	if(moedaVisivel){

		glBindTexture( GL_TEXTURE_2D, texID[3] );
		glPushMatrix();
		glTranslatef(moedaX,2,moedaZ);
		glScalef(0.7, 0.7, 1);
		//pegaMoeda();
		moeda();
		glPopMatrix();
	}

	//desenha a bigorna
	if(bigornaVisivel){
		glBindTexture( GL_TEXTURE_2D, texID[0] );
		glPushMatrix();
		glTranslatef(bigornaX,2,bigornaZ);
		glScalef(1.3, 0.7, 1);
		//pegaBigorna();
		bigorna();
		glPopMatrix();
	}

	//desenha a tela de "game over"
	if(gameOver){

		glLoadIdentity();
		glPushMatrix();
		glTranslatef(0.0f, 5.0f, 0.0f);
		glColor3f(1, 0, 0);
		drawText("GAME OVER! MUITO RUIM KK NUB XD!", 0.0f, 0.0f);
		glPopMatrix();
	}
	//desenha o score
	else{
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(0.0f, 5.0f, 0.0f);
		string scoreText = "Score: " + to_string(playerScore);
		glColor3f(1, 0, 0);
		drawText(scoreText, 0.0f, 0.0f);
		glPopMatrix();
	}

	glFlush();
}

// atualiza a lógica do jogo e controla o fluxo de frames
void doFrame(int v) {

	//incrementa o número de frames
    numFrame++;

    //gera um número aleatório entre 0 e 1
    float rand = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);

    //torna a moeda visível a cada 150 frames
    if (numFrame % 150 == 0){

    	//define um momento aleatório para a moeda ficar visível
    	if((moedaVisivel == false)&&(rand > 0.4)){

    		moedaVisivel = true;
    		moedaX = objectX + 1;
    		moedaY = 5;
    		moedaZ = objectZ + 1;
    	}
    }

    //torna a bigorna visível a cada 150 frames
    if (numFrame % 150 == 0){

    	//define um momento aleatório para a bigorna ficar visível
    	if((bigornaVisivel == false)&&(rand <= 0.4)){

        	bigornaVisivel = true;
        	bigornaX = objectX + 1;
        	bigornaY = 5;
        	bigornaZ = objectZ + 1;
        }
    }

    //encerra o jogo caso o placar fique negativo
    if(playerScore < 0){

    	gameOver = true;

    	return;

    }

    //redesenha a cena
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
    glutSwapBuffers();
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

	glEnable(GL_TEXTURE_GEN_S);
	 glEnable(GL_TEXTURE_GEN_T);
	glMatrixMode(GL_MODELVIEW);
	     glLoadIdentity();


	     glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	     glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	     glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	     glLightfv(GL_LIGHT0, GL_POSITION, direction);

	     glEnable(GL_LIGHTING);
	     glEnable(GL_DEPTH_TEST);
	     glEnable(GL_LIGHT0);

	     glEnable(GL_BLEND);
	     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	     glEnable(GL_NORMALIZE);

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("CoinBear3D");

	init();
	loadTextures();
	glutDisplayFunc(display);

	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	glutTimerFunc(20,doFrame,0);

	glutReshapeFunc(reshape);

	glutMainLoop();
}
