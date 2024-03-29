#include <GL/glut.h>


void init(void);
void display(void);


int polygon = 4;

void init(void)
{
  // define a cor de background da janela
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // define o sistema de visualização - tipo de projeção
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho (0, 1, 0, 1, 0, 1);
}

void display() {

  // Limpa a janela, colocando na tela a cor definida pela função glClearColor
  glClear(GL_COLOR_BUFFER_BIT);


  
    glBegin(GL_POLYGON);
      glColor3f(1, 0, 0);
      glVertex3f(0.3, 0.3, 0);
      glVertex3f(0.5, 0.5, 0);
      glVertex3f(0.7, 0.3, 0);
    glEnd();

    glBegin(GL_POLYGON);
  	  glColor3f(1, 0, 1);
  	  glVertex3f(0.3, 0, 0);
	    glVertex3f(0.3, 0.3, 0);
	    glVertex3f(0.7, 0.3, 0);
	    glVertex3f(0.7, 0, 0);
  	glEnd();

    glBegin(GL_POLYGON);
  	  glColor3f(1, 1, 1);
  	  glVertex3f(0.45, 0.01, 0);
	    glVertex3f(0.45, 0.2, 0);
	    glVertex3f(0.55, 0.2, 0);
	    glVertex3f(0.55, 0.01, 0);
  	glEnd();

    glBegin(GL_POLYGON);
  	  glColor3f(1, 1, 1);
  	  glVertex3f(0.58, 0.1, 0);
	    glVertex3f(0.58, 0.18, 0);
	    glVertex3f(0.67, 0.18, 0);
	    glVertex3f(0.67, 0.1, 0);
  	glEnd();

    glLineWidth(3);

    glBegin(GL_LINES);
  	  glColor3f(1, 0, 1);
  	  glVertex2f(0.58, 0.135);
	    glVertex2f(0.67, 0.135);
  	glEnd();

    glBegin(GL_LINES);
  	  glColor3f(1, 0, 1);
  	  glVertex2f(0.625, 0.1);
	    glVertex2f(0.625, 0.18);
  	glEnd();
    

 // Libera o buffer de comando de desenho para fazer o desenho acontecer o mais rápido possível.
  glFlush();
}

void keyboard( unsigned char key, int x, int y )
{
	switch( key ) {
	case ' ' :
		glClearColor(0.0, 0.0, 0.0, 1.0);
	break;

	default : 
		glClearColor(1.0, 1.0, 1.0, 1.0);

	break;
	}
display();
}

void mouse(int button, int action, int x, int y)
{
  switch(button)
  {
    case GLUT_LEFT_BUTTON:
    {
    	polygon = 3;
      break;
    }
    case GLUT_MIDDLE_BUTTON:
    {

      break;
    }
    case GLUT_RIGHT_BUTTON:
    {
    	polygon = 4;
      break;
    }
    default: break;
  }

  display();
}

int main(int argc, char** argv)
{

 //Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas.
 //É possível passar argumentos para a função glutInit provenientes da linha de execução, tais como informações sobre a geometria da tela
  glutInit(&argc, argv);

  //Informa à biblioteca GLUT o modo do display a ser utilizado quando a janela gráfica for criada.
  // O flag GLUT_SINGLE força o uso de uma janela com buffer simples, significando que todos os desenhos serão feitos diretamente nesta janela.
  // O flag GLUT_RGB determina que o modelo de cor utilizado será o modelo RGB.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

  //Define o tamanho inicial da janela, 256x256 pixels, e a posição inicial do seu canto superior esquerdo na tela, (x, y)=(100, 100).
  glutInitWindowSize (400, 300);
  glutInitWindowPosition (200, 200);

  // Cria uma janela e define seu título
  glutCreateWindow ("Primeiro OpenGL");

  //Nesta função é definido o estado inicial do OpenGL. Ajustes podem ser feitos para o usuário nessa função.
  init();

  // Define display() como a função de desenho (display callback) para a janela corrente.
  // Quando GLUT determina que esta janela deve ser redesenhada, a função de desenho é chamada.
  glutDisplayFunc(display);

  // Indica que sempre que uma tecla for pressionada no teclado, GLUT deverá chama a função keyboard() para tratar eventos de teclado (keyboard callback).
  // A função de teclado deve possuir o seguinte protótipo:
  glutKeyboardFunc(keyboard);


  //glutMouseFunc(mouse);

  //Inicia o loop de processamento de desenhos com GLUT.
  // Esta rotina deve ser chamada pelo menos uma vez em um programa que utilize a biblioteca GLUT.
  glutMainLoop();

  return 0;

}
