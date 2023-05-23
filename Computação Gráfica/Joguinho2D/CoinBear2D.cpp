//CoinBear 2D
//Por Leonardo Bacellar e Lucas Clemente

#include <GL/glut.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

// variáveis iniciais
const double PI = 3.141592654;

int numFrame = 0;

float minX = -40.0f;
float maxX = 90.0f;

bool jump = false;

float objectX = 0.5f;
float objectY = -0.2f;

float objectSpeed = 0.7f;

float objectDir = 0.0f;

int playerScore = 0;

bool bigornaVisivel = false;
bool moedaVisivel = false;

bool bigornaPega = false;
bool moedaPega = false;

float moedaX = 0;
float moedaY = 0;

float bigornaX = 0;
float bigornaY = 0;

bool gameOver = false;

bool run = false;

//função que move os objetos no eixo X
//movimento esse de acordo com a velocidade e direção indicadas
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

//callback do teclado
//trata eventos das setinhas quando pressionadas
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:

        	moveObjectX(objectSpeed * (-1));
        	break;

        case GLUT_KEY_RIGHT:

        	moveObjectX(objectSpeed);
        	break;

        case GLUT_KEY_UP:

        	jump = true;
            break;

        case GLUT_KEY_DOWN:

        	if(run){

        		run = false;
        		objectSpeed = 0.7f;
        	}
        	else{

        		run = true;
        		objectSpeed = 1.4f;
        	}

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

//demais primitivas que serão utilizadas no projeto
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

//demais objetos que serão utilizados no projeto
//construídos a partir das primitivas
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

void moeda(){

	moedaY = moedaY - 0.3;

	glPushMatrix();
	glColor3f(1,0.8,0);
	primitivaC(5);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8, 0.8, 1);
	glColor3f(1,1,0);
	primitivaC(5);
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
	primitivaT();
	glPopMatrix();

	if(bigornaY <= -17){

		bigornaVisivel = false;
		bigornaY = 43;
	}

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

//personagem principal
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

//função que trata a colisão do personagem com o objeto moeda
void pegaMoeda(){

	if(((moedaX <= objectX + 30)&&(moedaX >= objectX + 10))&&(moedaY <= 20)){

		moedaPega = true;
		playerScore++;
		moedaVisivel = false;
	}

}

//função que trata a colisão do personagem com o objeto bigorna
void pegaBigorna(){

	if(((bigornaX <= objectX + 10)&&(bigornaX >= objectX - 10))&&(bigornaY <= 3)){

		bigornaPega = true;
		playerScore--;
		bigornaVisivel = false;
	}

}

//desenha a cena
void drawScene(void) {

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	//montanhas e morros
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

	//gramados
	glLoadIdentity();
	glPushMatrix();
	gramaA();
	glPopMatrix();
	glLoadIdentity();
	glPushMatrix();
	gramaB();
	glPopMatrix();

	//árvores
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

	//sol
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(10,70,0);
	sol();
	glPopMatrix();

	glPushMatrix();

	//mecânica do pulo
	if(jump){

		glTranslatef(0, objectY + 15.0f, 0);

	}

	//desenha o personagem principal
	glTranslatef(objectX, 0, 0);
	mainBear();

	if(jump){

		jump = false;

	}
	glPopMatrix();

	//desenha a moeda
	if(moedaVisivel){

		glPushMatrix();
		glTranslatef(moedaX,moedaY,0);
		glScalef(0.7, 0.7, 1);
		pegaMoeda();
		moeda();
		glPopMatrix();
	}

	//desenha a bigorna
	if(bigornaVisivel){

		glPushMatrix();
		glTranslatef(bigornaX,bigornaY,0);
		glScalef(1.3, 0.7, 1);
		pegaBigorna();
		bigorna();
		glPopMatrix();
	}

	//desenha a tela de "game over"
	if(gameOver){

		glLoadIdentity();
		glPushMatrix();
		glTranslatef(35.0f, 50.0f, 0.0f);
		glColor3f(1, 0, 0);
		drawText("GAME OVER! MUITO RUIM KK NUB XD!", 0.0f, 0.0f);
		glPopMatrix();
	}
	//desenha o score
	else{
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(2.5f, 90.0f, 0.0f);
		string scoreText = "Score: " + to_string(playerScore);
		glColor3f(1, 0, 0);
		drawText(scoreText, 0.0f, 0.0f);
		glPopMatrix();
	}

	glutSwapBuffers();

	//redesenha a cena
	glutPostRedisplay();
}

//rotina de inicialização
void Init(void) {
	glClearColor(0.75, 0.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(minX, maxX, -1.0, 4.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
    		moedaX = objectX + 40;
    		moedaY = 60;
    	}
    }

    //torna a bigorna visível a cada 150 frames
    if (numFrame % 150 == 0){

    	//define um momento aleatório para a bigorna ficar visível
    	if((bigornaVisivel == false)&&(rand <= 0.4)){

        	bigornaVisivel = true;
        	bigornaX = objectX + 25;
        	bigornaY = 43;
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
}

//redefine o tamanho da janela da cena
void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//rotina principal
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("CoinBear 2D");

	Init();

	glutDisplayFunc(drawScene);

	glutSpecialFunc(specialKeys);

	glutTimerFunc(20,doFrame,0);

	glutReshapeFunc(resize);

	glutMainLoop();
}
