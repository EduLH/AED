#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int x_mouse=300;
int y_mouse=300;

int i = 0;
int controlador = 0;
float x1_coord =0;
float x2_coord =0;
float x3_coord =0;
float y1_coord =0;
float y2_coord =0;
float y3_coord =0;
char forma = 'r';

void init(){ //caracs do ponto
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.0);
}

void ponto_mouse(int x, int y){
    float x_tela = ((float)x/300)-1;  //coords X do mouse
    float y_tela = -(((float)y/300)-1); //coords Y do mouse
    glClear(GL_COLOR_BUFFER_BIT); //limpa a tela
    glBegin(GL_POINTS); //inicia a construcao do ponto
        glVertex2f(x_tela,y_tela);  //printa o ponto_mouse
    glEnd();  //finaliza
    glFlush();
}

void linha_mouse(int x, int y){
    float x_tela = ((float)x/300)-1;  //coords X do mouse
    float y_tela = -(((float)y/300)-1); //coords Y do mouse
    if(controlador < 1)
        controlador++;
    else{
        glClear(GL_COLOR_BUFFER_BIT); //limpa a tela
        controlador = 0;
    }
    glBegin(GL_LINES);
        if(i == 0){
            x1_coord = x_tela;
            y1_coord = y_tela;
            i = 1;
        }
        else{
            x2_coord = x_tela;
            y2_coord = y_tela;
            i = 0;
        }
        glVertex2f(x1_coord, y1_coord);
        glVertex2f(x2_coord, y2_coord);
    glEnd();
    glFlush();
}

void triangulo_mouse(int x, int y){
    float x_tela = ((float)x/300)-1;  //coords X do mouse
    float y_tela = -(((float)y/300)-1); //coords Y do mouse
    if(controlador < 2 )
        controlador++;
    else{
        controlador = 0;
        glClear(GL_COLOR_BUFFER_BIT); //limpa a tela
    }
    glBegin(GL_TRIANGLES);

        switch (i) {
          case (0):
              i=1;
              break;
          case (1):
              x1_coord = x_tela;
              y1_coord = y_tela;
              i=2;
              break;
          case (2):
              x2_coord = x_tela;
              y2_coord = y_tela;
              i=3;
              break;
          case (3):
              x3_coord = x_tela;
              y3_coord = y_tela;
              i=4;
              break;
          case (4):
              i = 0;

              break;
        }

        glVertex2f(x1_coord, y1_coord);
        glVertex2f(x2_coord, y2_coord);
        glVertex2f(x3_coord, y3_coord);
    glEnd();
    glFlush();

}

void Keyboard(unsigned char key, int x, int y){
    switch (key) {
      case '1':
          glColor3f(0.0, 0.0, 1.0);
          break;
      case '2':
          glColor3f(0.0, 1.0, 0.0);
          break;
      case '3':
          glColor3f(1.0, 0.0, 0.0);
          break;
      case '4':
          glColor3f(0.0, 0.5, 0.5);
          break;
      case '5':
          glColor3f(0.5, 0.1, 0.1);
          break;
      case '6':
          glColor3f(0.1, 0.4, 0.3);
          break;
      case '7':
          glColor3f(0.3, 0.1, 0.7);
          break;
      case '8':
          glColor3f(0.1, 0.2, 0.3);
          break;
      case '9':
          glColor3f(0.3, 0.2, 0.1);
          break;
      case 'r':
      case 'R':
          forma = 'R';
          printf("RRRRR\n");
          break;
      case 't':
      case 'T':
          forma = 'T';
          printf("ttttt\n");
          break;
    }
    glutPostRedisplay();
}

void MouseInt (int botao, int estado, int x, int y) {
    switch(botao) {
        case GLUT_LEFT_BUTTON: //caso tenha entrada do LEFT-Click
            if(estado == GLUT_DOWN){ //iteracao de click
                printf ("Botao esquerdo (%i,%i)\n", x, y);
                printf ("Localizacao Ponto: (%f,%f)\n %c\n", ((float)x/300)-1, -(((float)y/300)-1), forma);
                x_mouse = x;
                y_mouse = y;
            }
        break;
    }
    glutPostRedisplay();
}

void desenha(){
    switch (forma) {
        case 'r':
        case 'R':
            forma = 'R';
            printf("MUDOU ESSE DMONIO p RRRRR\n");
            linha_mouse(x_mouse, y_mouse);
            break;
        case 't':
        case 'T':
            forma = 'T';
            printf("MUDOU ESSE DMONIO P ttttt\n");;
            triangulo_mouse(x_mouse, y_mouse);
            break;
        case 'p':
        case 'P':
            forma = 'P';
            ponto_mouse(x_mouse,y_mouse);
    }
}

int main( int argc, char *argv[ ] ) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100); //locar de iniciar a janela
    glutInitWindowSize(600,600);    //tamanho da janela
    glutInit(&argc, argv);
    glutCreateWindow("Interacao Mouse - Ponto");  //cria a janela
    init();
    glutDisplayFunc(desenha); //funcao para ser executada na janela
    glutMouseFunc(MouseInt);  //para imprimir as coords
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();  //loop simples
    return 0;
}
