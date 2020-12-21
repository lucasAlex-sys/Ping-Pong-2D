/*arquivo auxiliar que contem os objetos criados*/
#ifndef OBJETO_H
#define OBJETO_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "sprite.h"
#include "inicializa.h"
#include<math.h>
#include<stdbool.h> 
#include"SOIL.h"
#include "textura.h"


//constroi uma bolinha
void constroiBolinha(){
 
	int i=0;
 	glColor3f(0.0, 0.0, 0.0);
   	glVertex3f(posicaoAtualX + bola.x,posicaoAtualY+bola.y,bola.z );
	glBegin(GL_TRIANGLE_FAN);
	    
	 for(i=0;i<=bola.vertices;i++){
	 	bola.t = 2*M_PI*i/ bola.vertices;
		
		glVertex3f(posicaoAtualX + bola.x + cos(bola.t)*bola.raio,
		posicaoAtualY+bola.y+sin(bola.t)*bola.raio, bola.z );
		
	}

	 glEnd();

	
}
//controi a barra do player1
void constroiPlayer1(){

   	//glColor3f(0.0,0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
   	    
		glVertex3f(player1.x ,player1.y + MOVIMENTAPLAYER1 , 0.0);
		glVertex3f(player1.x + player1.largura   ,  player1.y + MOVIMENTAPLAYER1, 0.0);
		glVertex3f(player1.x + player1.largura   ,  player1.y + player1.comprimento + MOVIMENTAPLAYER1, 0.0);
		glVertex3f(player1.x   , player1.y + player1.comprimento + MOVIMENTAPLAYER1, 0.0);
	glEnd();

}
//controi  a barra do player2
void constroiPlayer2(){

   	glColor3f(0.0,0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
   	    
		glVertex3f(player2.x ,player2.y + MOVIMENTAPLAYER2 , 0.0);
		glVertex3f(player2.x + player2.largura   ,  player2.y + MOVIMENTAPLAYER2, 0.0);
		glVertex3f(player2.x + player2.largura   ,  player2.y + player2.comprimento + MOVIMENTAPLAYER2 , 0.0);
		glVertex3f(player2.x   , player2.y + player2.comprimento + MOVIMENTAPLAYER2, 0.0);
		
	glEnd();

}


#endif
