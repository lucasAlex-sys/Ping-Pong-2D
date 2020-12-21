#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "objeto.h"
#include <stdbool.h> 
#include "SOIL.h"
#include "textura.h"

bool esq1 = false;
bool dir1 = false;
bool esq2= false;
bool dir2 = false;
	

//colisao verificando se a distancia do raio se encontra dentro dos pontos
//y1 e y2 da parte da frente e tras da barra 
//x1 e x2 da parte inferior e superior da barra
bool colisaoPlayer2Linha(float posx,float posy,float mov2){
	
	 if((bola.y + posy) +  bola.raio >= (player2.y + mov2)&& 
	    (bola.y + posy) -  bola.raio <= (player2.y + mov2) + player1.comprimento &&
	    (bola.x + posx) +  bola.raio >=  player2.x &&
	    (bola.x + posx) -  bola.raio <=  player2.x + player1.largura ||
	    (bola.x + posx) +  bola.raio >=  player2.x  && 
	    (bola.x + posx) -  bola.raio <=  player2.x +  player2.largura &&
	    (bola.y + posy) +  bola.raio >= (player2.y + mov2) &&
	    (bola.y + posy) -  bola.raio <= (player2.y + mov2) + player2.comprimento)
	
			return true;
		else 	
			
			return false; 					

}
bool colisaoPlayer1Linha(float posx,float posy,float mov1){

	if((bola.y + posy) + bola.raio >= (player1.y + mov1) && 
	   (bola.y + posy) - bola.raio <= (player1.y  + mov1) + player2.comprimento &&
	   (bola.x + posx) + bola.raio >=  player1.x &&
	   (bola.x + posx) - bola.raio <=  player1.x + player2.largura ||
	   (bola.x + posx) + bola.raio >=  player1.x  && 
	   (bola.x + posx) - bola.raio <=  player1.x +  player1.largura &&
	   (bola.y + posy) + bola.raio >= (player1.y + mov1) &&
	   (bola.y + posy) - bola.raio <= (player1.y + mov1) + player1.comprimento)
			return true;
		else 
			return false; 					
}



//colisao da bola com as superficies 
//quando a distancia do raio da bola mais seus movimento atingir o limite que podera ir ela
//mudara de direçao
//o limite que podera ir sera dentro do estadio
//dentro dos limites do  comprimento e largura
//esta indentada de maneira hierárquica para sua animaçao ocorrer
//dentro da  funcao,tambem ocoorre a atualização dos pontos
void anima(){
	if(rodando >= 85){
		if(telaMenu%2!=0){
			if(ESCAPE%2==0){
				if(resete%2==0){
					if(PAUSE%2==0){
						posicaoAtualY+=velocidadeY;
						posicaoAtualX+=velocidadeX;		
						
						if(posicaoAtualX + 300 <= 0 ){
							pontosPlayr2 +=1;
							posicaoAtualY=0;
							posicaoAtualX=0;
							
							velocidadeX = -velocidadeX;		
						}
						if(posicaoAtualX + 300 >= 600){
							pontosPlayr1 +=1;
							posicaoAtualY=0;
							posicaoAtualX=0;				
							velocidadeX = +velocidadeX;
						}		
						if(posicaoAtualY+150>=300-bola.raio){
						
							velocidadeY = -velocidadeY;
						}		
						if(posicaoAtualY + 150 <= 0 + bola.raio){
							
							velocidadeY = - velocidadeY;
						}
						if(colisaoPlayer2Linha(posicaoAtualX,posicaoAtualY,MOVIMENTAPLAYER2)) {
							velocidadeX = -velocidadeX;
							
						}
						if(colisaoPlayer1Linha(posicaoAtualX,posicaoAtualY,MOVIMENTAPLAYER1)){
							velocidadeX = -velocidadeX;
						
						}
						
				}	 }
			}
		}	
	}		

		glutPostRedisplay();
		glutTimerFunc(33, anima,0);
		
}

//layout da tela jogo
void jogo(){
		
	backgraundfundo();
	backgraundcampo();
	constroiPlayer1();
	constroiPlayer2();
	players();
	constroiBolinha();

	hud();
	
}
void desenhaMinhaCena()
{
	
    glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0,1.0,1.0);
	jogo();
	retonarmenu();
	reiniciar();
	menu();
	telacomojogar();
	inicio1();
	
	
	
    glutSwapBuffers();
}



// Inicia algumas variáveis de estado do OpenGL
void setup()
{
    // define qual é a cor do fundo
    glClearColor(1.0, 1.0, 1.0, 0.0); // branco
	
}


void redimensionada(int width, int height)
{
   // left, bottom, right, top
   glViewport(0, 0,1000, 600);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1000.0, 0.0, 600.0, -5, 5);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
//renicia as pontuaçoes e suas respectivas posiçoes
void reseta(){

	MOVIMENTAPLAYER1 = 0;
	MOVIMENTAPLAYER2 = 0;
	posicaoAtualY = 0;
	posicaoAtualX = 0;
	velocidadeX = 11;
	velocidadeY = 11;
	pontosPlayr1 = 0;
	pontosPlayr2 = 0;
	setpts2=0;
	setpts1=0;
}
//atualização dos movimentos dos players
//quando a tecla de movimento é pressionada,assume a condição de verdadeiro
//e realiza a movimentaçao
//quando solta a tecla, asume a condição de falsa
//e a movimentacao não é realizada
void movimenta(){
	
	if(rodando>=85){				
		if(esq1 == true && MOVIMENTAPLAYER1!=120 && MOVIMENTAPLAYER1 <= 120){
		 		MOVIMENTAPLAYER1+=6;
		 }		
				
		if(esq2 == true && MOVIMENTAPLAYER2!=120 && MOVIMENTAPLAYER2<= 120){
		 		MOVIMENTAPLAYER2+=6;		 		
		}
		if(dir1 == true && MOVIMENTAPLAYER1!=-120 && MOVIMENTAPLAYER1 >=-120){
				MOVIMENTAPLAYER1-=6;
		}
		if(dir2 == true && MOVIMENTAPLAYER2!=-120 && MOVIMENTAPLAYER2>=-120 ){
					MOVIMENTAPLAYER2-=6;
		}
	}
		
		glutPostRedisplay();
		glutTimerFunc(33, movimenta,0);

}
//eventos de clique
//uso como direção o local do ponto do x e y da bola,que se encontra no centro do estadio
void clique(int button,int state,int x,int y){

	switch(button){
		case GLUT_LEFT_BUTTON:
			//tela menu
			if(telaMenu%2==0 && telaComoJogar%2== 0){
				//botao jogar
				//o menu é desativado
				if(x >= bola.x - 20 && 
				   x <= bola.x + 110 && 
				   y <= bola.y - 70 && 
				   y >= bola.y - 100 )
					telaMenu+=1;
				//botao como jogar
				// a tela como jogar sobrepoe a tela menu
				if(x >= bola.x - 20 && 
			           x <= bola.x + 110 && 
			           y <= bola.y - 20 && 
			           y >= bola.y - 50 )
					telaComoJogar+=1;
				//botao sair
				//sai da aplicação
				if (x >= bola.x - 20 && 
			     	    x <= bola.x + 110 && 
			            y <= bola.y + 30 && 
			            y >= bola.y  )
					exit(0);
			}
			//tela do jogo
			if(ESCAPE%2!=0 && telaMenu%2!=0){
				//botao sim
				//menu sobrepoe o jogo				
				if(x >= bola.x - 110 && 
				   x <= bola.x + 5 && 
				   y <= bola.y + 110 && 
				   y >= bola.y + 85 ){
					telaMenu+=1;
					ESCAPE+=1;
					PAUSE=0;
					reseta();			
	
				 }
				 //botao não
				 //o jogo continua normalmente
				 if(x >= bola.x  && 
				    x <= bola.x +105 && 
				    y <= bola.y + 110 && 
				    y >= bola.y + 85 )
					ESCAPE+=1;
					
			}
			if(resete%2!=0 && telaMenu%2!=0 && ESCAPE%2==0){
				//botao sim
				//jogo é reinciado				
				if(x >= bola.x - 110 && 
				   x <= bola.x + 5 && 
				   y <= bola.y + 110 && 
				   y >= bola.y + 85 ){
					
					reseta();
					resete+=1;			
	
				 }
				 //botao não
				 //o jogo continua normalmente
				 if(x >= bola.x  && 
				    x <= bola.x +105 && 
				    y <= bola.y + 110 && 
				    y >= bola.y + 85 )
					resete+=1;
					
			}
				break;	
			default:
				break;
	 }
}
//eventos de tecla pressionada
void teclaPressionada(unsigned char key, int x, int y){

//enquanto a logo nao terminar de passar os eventos nao sao liberados
if(rodando>=140){
	if(telaMenu%2==0 && telaComoJogar != 0){
		switch(key){
			//desativa a tela como jogar
			case 'M':			
			case 'm':
				telaComoJogar+=1;
				break;
		 	default:
				break;
		}
	}
	if(telaMenu%2!=0 ){
		switch(key){
			//as atualizaçoes para de ocorrer
			//parace supostamente pausado
			//ativa o retonarmenu
			case 27:
				ESCAPE+=1;
				break;
			//modo fullscreen
		
		 	default:
				break;
		}			
	if(ESCAPE%2==0 ){
		switch(key){
			
			//volta a tela a froma original
			case 'K':
			case 'k':
				glutReshapeWindow(1000, 600);
				break;
			//reinicia os pontos e seus movimentos
			case 'R':
			case 'r':
				resete+=1;
				break;
			//pause o game(as atualizaçoes não ocorrem)
			case 'P':
			case 'p':
				PAUSE+=1;
				break;
			default:
				break;
		
		}
		if(PAUSE%2==0){
			//quando pressionados assume a condiçao de verdadeiro
			//realizando a atualizaçao do movimentos
			switch(key){
				case 'W':					
			 	case 'w':
					esq1= true;
					break;
				case 'S':
				case 's':
					dir1=true;			
					
					break;
				case 49:
					esq2 = true;
					 break;	
				case 50:
					dir2 = true;
					break;	
					
				
				default:
					break;
			}
		}
	}
	}

   }	   
}
//evento de teclas soltas
void teclaSolta(unsigned char k, int x, int y){
	//assumem falsa quando pressionadas
	switch( k){
	case 'W':
	case 'w':
		esq1 = false;
		break;
	case 'S':
	case 's':
		dir1 = false;
		break;
	case  49:
		esq2 = false;
		break;
	case 50: 
		dir2 = false;
		break;
	default:
		break;

	}
}
		
// Função principal
int main(int argc, char** argv)
{
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(1000, 600);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Lucas Alexsanderson da Fonseca");

   // Registra callbacks para eventos
	
   glutDisplayFunc(desenhaMinhaCena);
   glutTimerFunc(33, anima, 1);
   glutTimerFunc(33, movimenta, 1);	
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);
   glutKeyboardUpFunc(teclaSolta);	
   glutMouseFunc(clique);
   // Configura valor inicial de algumas
   // variáveis de estado do OpenGL
   setup();
	//inicializa as texturas uma unica vez
	inicializaTextura();
	inicializa();
   glutMainLoop();
   return 0;
}
