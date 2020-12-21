/*arquivo auxiliar que contem os texturas criadoas e inicializadas*/
#ifndef TEXTURA_H
#define TEXTURA_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "objeto.h"
#include <stdio.h>
#include <stdlib.h>
#include "sprite.h"
#include "inicializa.h"
#include<math.h>
#include<stdbool.h> 
#include"SOIL.h"

GLuint Tpontuacao[12];
GLuint Tsim;
GLuint Tnao;
GLuint Tinicio;
GLuint TbatalhaFundo;
GLuint TbackgraundCampo;
GLuint TretonarMenu;
GLuint Thud1;
GLuint Thud2;
GLuint Tmenu1;
GLuint Tcomojogar;
GLuint Tsair;
GLuint Tjogar;
GLuint Tset1;
GLuint Tset2;
GLuint Tshuriken;
GLuint TtelaComoJogar1;
GLuint Tsetpts[3];
GLuint Tlogo;
GLuint Tbarra1;
GLuint Tbarra2;
GLuint Tresete;



//hud do jogo e atualizaçao das texturas de pontuação
void hud(){
	int i=0;
	int j=0;
	int k=0;
	int l=0;

	glColor3f(1.0,1.0,1.0);
	
	//textura do set do player1
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tset1);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 1); glVertex3f(bola.x - 300 , bola.y - 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x - 200 , bola.y - 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x - 200 , bola.y - 260,  0);
		    glTexCoord2f(0,0); glVertex3f(bola.x  - 300 , bola.y - 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);

	//textura do set do player2
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tset2);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(1 , 1); glVertex3f(bola.x + 300 , bola.y - 200,  0);
		    glTexCoord2f(0 , 1); glVertex3f(bola.x + 200 , bola.y - 200,  0);
		    glTexCoord2f(0 , 0); glVertex3f(bola.x + 200 , bola.y - 260,  0);
		    glTexCoord2f(1 , 0); glVertex3f(bola.x  + 300 , bola.y - 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//textura player1
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Thud1);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 0); glVertex3f(bola.x - 300 , bola.y + 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x - 200 , bola.y + 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x - 200 , bola.y + 260,  0);
		    glTexCoord2f(0,1); glVertex3f(bola.x  - 300 , bola.y + 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);

	//textura player2
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Thud2);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(1, 0); glVertex3f(bola.x + 300 , bola.y + 200,  0);
		    glTexCoord2f(0, 0); glVertex3f(bola.x  + 200, bola.y + 200,  0);
		    glTexCoord2f(0, 1); glVertex3f(bola.x  + 200, bola.y + 260,  0);
		    glTexCoord2f(1,1); glVertex3f(bola.x  + 300, bola.y + 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);
		
	glColor3f(1.0,1.0,1.0);
	//atualizacão da pontuação
	//player 1
	if(pontosPlayr1 == 0)
		i=pontosPlayr1;
	if(pontosPlayr1 == 1)
		i=pontosPlayr1;
	if(pontosPlayr1 == 2)
		i=pontosPlayr1;
	if(pontosPlayr1 == 3)
		i=pontosPlayr1;
	if(pontosPlayr1 == 4)
		i=pontosPlayr1;
	if(pontosPlayr1 == 5)
		i=pontosPlayr1;
	if(pontosPlayr1 == 6)
		i=pontosPlayr1;
	if(pontosPlayr1 == 7)
		i=pontosPlayr1;
	if(pontosPlayr1 == 8)
		i=pontosPlayr1;
	if(pontosPlayr1 == 9)
		i=pontosPlayr1;
	if(pontosPlayr1 == 10)
		i=pontosPlayr1;
	if(pontosPlayr1 == 11)
		i=pontosPlayr1;
		
	//player 2
	if(pontosPlayr2 == 0)
		j=pontosPlayr2;
	if(pontosPlayr2 == 1)
		j=pontosPlayr2;
	if(pontosPlayr2 == 2)
		j=pontosPlayr2;
	if(pontosPlayr2 == 3)
		j=pontosPlayr2;
	if(pontosPlayr2 == 4)
		j=pontosPlayr2;
	if(pontosPlayr2 == 5)
		j=pontosPlayr2;
	if(pontosPlayr2 == 6)
		j=pontosPlayr2;
	if(pontosPlayr2 == 7)
		j=pontosPlayr2;
	if(pontosPlayr2 == 8)
		j=pontosPlayr2;
	if(pontosPlayr2 == 9)
		j=pontosPlayr2;
	if(pontosPlayr2 == 10)
		j=pontosPlayr2;
	if(pontosPlayr2 == 11)
		j=pontosPlayr2;
	//atualizaçao dos sets e dos pontos
	//ao atingir os 11 pontos,eles sao zerados.
	//player1
	if(pontosPlayr1 > 10 ){
		setpts1+=1;
		pontosPlayr1=0;
		pontosPlayr2=0;

	}
	//player2		
	if(pontosPlayr2 > 10 ){
		setpts2+=1;
		pontosPlayr1=0;
		pontosPlayr2=0;

	}		
	//apos a vitoria a tela menu é ativada e os sets zerados
	if(setpts1==2 || setpts2==2){
	
	telaMenu+=1;
	setpts2=0;
	setpts1=0;
	}

	//textura pontuação player1
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tpontuacao[i]);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 0); glVertex3f(bola.x - 40 , bola.y + 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x  , bola.y + 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x  , bola.y + 260,  0);
		    glTexCoord2f(0,1); glVertex3f(bola.x  - 40 , bola.y + 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);

	//textura pontuação player2
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tpontuacao[j]);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 0); glVertex3f(bola.x + 40 , bola.y + 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x + 80 , bola.y + 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x + 80 , bola.y + 260,  0);
		    glTexCoord2f(0,1); glVertex3f(bola.x  + 40 , bola.y + 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//textura pontuação set player1
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tsetpts[setpts1]);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 1); glVertex3f(bola.x - 40 , bola.y - 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x  , bola.y - 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x  , bola.y - 260,  0);
		    glTexCoord2f(0, 0); glVertex3f(bola.x  - 40 , bola.y - 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);

	//textura pontuação player2
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Tsetpts[setpts2]);
		glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 1); glVertex3f(bola.x + 40 , bola.y - 200,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x + 80 , bola.y - 200,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x + 80 , bola.y - 260,  0);
		    glTexCoord2f(0, 0); glVertex3f(bola.x  + 40 , bola.y - 260 , 0);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	

}
//tela como jogar
void telacomojogar(){

	if(telaComoJogar%2!=0){
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, TtelaComoJogar1);
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0, 0); glVertex3f(0, 0,  0);
		glTexCoord2f(0, 1); glVertex3f( 0, 600,  0);
		glTexCoord2f(1, 1); glVertex3f( 1000, 600,  0);
		glTexCoord2f(1, 0); glVertex3f(1000,0,  0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);

	}
}
//tela menu
void menu(){
	if(telaMenu%2==0){
	glColor3f(1.0,1.0,1.0);
	//textura de fundo
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tmenu1);	
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(1, 0); glVertex3f(0, 0,  0);
		glTexCoord2f(1, 1); glVertex3f( 0, 600,  0);
		glTexCoord2f(0, 1); glVertex3f( 1000, 600,  0);
		glTexCoord2f(0, 0); glVertex3f(1000,0,  0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);
	//botao jogar
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tjogar);
	    glBegin(GL_TRIANGLE_FAN);
	       glTexCoord2f(0 , 1); glVertex3f(bola.x - 20  , bola.y + 100 ,  0);
               glTexCoord2f(1 , 1); glVertex3f(bola.x + 110 , bola.y + 100 ,  0);
	       glTexCoord2f(1 , 0); glVertex3f(bola.x + 110 , bola.y + 70  ,  0);
	       glTexCoord2f(0 , 0); glVertex3f(bola.x - 20  , bola.y + 70  ,  0);
	   glEnd();
	glDisable(GL_TEXTURE_2D);
	//botao como jogar
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tcomojogar);
            glBegin(GL_TRIANGLE_FAN);
	        glTexCoord2f(0, 1); glVertex3f(bola.x - 20  , bola.y + 50,  0);
	        glTexCoord2f(1, 1); glVertex3f(bola.x + 110 , bola.y + 50,  0);
		glTexCoord2f(1, 0); glVertex3f(bola.x + 110 , bola.y + 20,  0);
		glTexCoord2f(0,0); glVertex3f(bola.x  - 20  , bola.y + 20 , 0);
            glEnd();
	glDisable(GL_TEXTURE_2D);
	//botao sair
        glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tsair);
	    glBegin(GL_TRIANGLE_FAN);
	       glTexCoord2f(0, 1); glVertex3f(bola.x - 20  , bola.y      ,   0);
	       glTexCoord2f(1, 1); glVertex3f(bola.x + 110 , bola.y      ,  0);
	       glTexCoord2f(1, 0); glVertex3f(bola.x + 110 , bola.y - 30 ,  0);
	       glTexCoord2f(0,0); glVertex3f(bola.x  - 20  , bola.y - 30 ,  0);
	   glEnd();
       glDisable(GL_TEXTURE_2D);

	
  }

}
void players(){

	glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tbarra1);	
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0, 0);glVertex3f(player1.x ,player1.y + MOVIMENTAPLAYER1 , 0.0);
		glTexCoord2f(1, 0);glVertex3f(player1.x + player1.largura   ,  player1.y + MOVIMENTAPLAYER1, 0.0);
		glTexCoord2f(1, 1);glVertex3f(player1.x + player1.largura   ,  player1.y + player1.comprimento + MOVIMENTAPLAYER1, 0.0);
		glTexCoord2f(0, 1);glVertex3f(player1.x   , player1.y + player1.comprimento + MOVIMENTAPLAYER1, 0.0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, Tbarra2);	
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0, 0);glVertex3f(player2.x , player2.y + MOVIMENTAPLAYER2 , 0.0);
		glTexCoord2f(1, 0);glVertex3f(player2.x + player2.largura   ,  player2.y + MOVIMENTAPLAYER2, 0.0);
		glTexCoord2f(1, 1);glVertex3f(player2.x + player2.largura   ,  player2.y + player2.comprimento + MOVIMENTAPLAYER2, 0.0);
		glTexCoord2f(0, 1);glVertex3f(player2.x , player2.y + player2.comprimento + MOVIMENTAPLAYER2, 0.0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);



}
void retonarmenu(){
	glColor3f(1.0,1.0,1.0);
	//textura de confirmaçao para voltar ao menu
	if(ESCAPE%2!=0){
	      glEnable(GL_TEXTURE_2D);
		 glBindTexture(GL_TEXTURE_2D, TretonarMenu);
		 glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 0); glVertex3f(bola.x - 110, bola.y - 110,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x + 110, bola.y - 110,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x + 110, bola.y + 110,  0);
		    glTexCoord2f(0,1); glVertex3f(bola.x  - 110, bola.y + 110, 0);
		 glEnd();
	     glDisable(GL_TEXTURE_2D);
   	     glColor3f(0.0,0.0, 0.0);
	
    }

}
void reiniciar(){


	
	//glColor3f(1.0,1.0,1.0);
	//textura de confirmaçao se ira reiniciar
	if(resete%2!=0){
	      glEnable(GL_TEXTURE_2D);
		 glBindTexture(GL_TEXTURE_2D, Tresete);
		 glBegin(GL_TRIANGLE_FAN);
		    glTexCoord2f(0, 0); glVertex3f(bola.x - 110, bola.y - 110,  0);
		    glTexCoord2f(1, 0); glVertex3f(bola.x + 110, bola.y - 110,  0);
		    glTexCoord2f(1, 1); glVertex3f(bola.x + 110, bola.y + 110,  0);
		    glTexCoord2f(0,1); glVertex3f(bola.x  - 110, bola.y + 110, 0);
		 glEnd();
	     
	}




}
void inicio1(){
	//logo do criador/diretor do jogo
	if(rodando <=75){
		glEnable(GL_TEXTURE_2D);
	            glBindTexture(GL_TEXTURE_2D, Tlogo);
	            glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0, 0); glVertex3f(0, 0,  0);
			glTexCoord2f(0, 1); glVertex3f( 0, 600,  0);
			glTexCoord2f(1, 1); glVertex3f( 1000, 600,  0);
			glTexCoord2f(1, 0); glVertex3f(1000,0,  0);
	    	    glEnd();
	       glDisable(GL_TEXTURE_2D);
	}
	if(rodando >=75 && rodando <=130){
		glEnable(GL_TEXTURE_2D);
		    glBindTexture(GL_TEXTURE_2D, Tinicio);
		    glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0, 0); glVertex3f(0, 0,  0);
			glTexCoord2f(0, 1); glVertex3f( 0, 600,  0);
			glTexCoord2f(1, 1); glVertex3f( 1000, 600,  0);
			glTexCoord2f(1, 0); glVertex3f(1000,0,  0);
		    glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	rodando+=1;	 
	
}


void backgraundfundo(){
	//fundo do jogo
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, TbatalhaFundo);
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(1, 0); glVertex3f(0, 0,  0);
		glTexCoord2f(1, 1); glVertex3f( 0, 600,  0);
		glTexCoord2f(0, 1); glVertex3f( 1000, 600,  0);
		glTexCoord2f(0, 0); glVertex3f(1000,0,  0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);
}

void backgraundcampo(){
	
	glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, TbackgraundCampo);
	    glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(1, 0); glVertex3f(estadio.x , estadio.y,  0);
		glTexCoord2f(1, 1); glVertex3f(estadio.x + estadio.largura   ,  estadio.y ,  0);
		glTexCoord2f(0, 1); glVertex3f(estadio.x + estadio.largura   ,  estadio.y + estadio.comprimento  ,  0);
		glTexCoord2f(0, 0); glVertex3f(estadio.x , estadio.y + estadio.comprimento,  0);
	    glEnd();
	glDisable(GL_TEXTURE_2D);
	//linhas do campo
	glColor3f(0.0,0.0, 0.0);
	glBegin(GL_LINE_LOOP);
            glVertex3f(estadio.x , estadio.y  , 0.0);
            glVertex3f(estadio.x + estadio.largura   ,  estadio.y , 0.0);
            glVertex3f(estadio.x + estadio.largura   ,  estadio.y + estadio.comprimento , 0.0);
            glVertex3f(estadio.x , estadio.y + estadio.comprimento, 0.0);
        glEnd();




}

GLuint carregaImagem(char* imagem){

 GLuint endereco = SOIL_load_OGL_texture(imagem, SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

    if (endereco == 0) {
        printf("Erro carregando a textura: '%s'\n", SOIL_last_result());
    }

    return endereco;
}

void inicializaTextura(){

TbatalhaFundo = carregaImagem("imagem/backgraundCampo.jpg");
Tinicio = carregaImagem("imagem/inicial.jpg");
TretonarMenu = carregaImagem("imagem/backtomenu.png");
TbackgraundCampo = carregaImagem("imagem/campo.png");
Thud1 = carregaImagem("imagem/player1.png");
Thud2 = carregaImagem("imagem/player2.png");
Tpontuacao[0] = carregaImagem("imagem/zero.png");
Tpontuacao[1] = carregaImagem("imagem/um.png");
Tpontuacao[2] = carregaImagem("imagem/dois.png");
Tpontuacao[3] = carregaImagem("imagem/tres.png");
Tpontuacao[4] = carregaImagem("imagem/quatro.png");
Tpontuacao[5] = carregaImagem("imagem/cinco.png");
Tpontuacao[6] = carregaImagem("imagem/seis.png");
Tpontuacao[7] = carregaImagem("imagem/sete.png");
Tpontuacao[8] = carregaImagem("imagem/oito.png");
Tpontuacao[9] = carregaImagem("imagem/nove.png");
Tpontuacao[10] = carregaImagem("imagem/dez.png");
Tpontuacao[11] = carregaImagem("imagem/onze.png");
Tshuriken = carregaImagem("imagem/UIHere.png");
Tset1 = carregaImagem("imagem/set.png");
Tset2 = carregaImagem("imagem/set.png");
Tmenu1 = carregaImagem("imagem/menu1.png");//abrir pelo gimp e tranformar em png
Tjogar = carregaImagem("imagem/jogar.png");
Tcomojogar = carregaImagem("imagem/comojogar.png");
Tsair = carregaImagem("imagem/sair.png");
TtelaComoJogar1= carregaImagem("imagem/comojogarI.png");
Tsetpts[0] = carregaImagem("imagem/zero.png");
Tsetpts[1] = carregaImagem("imagem/um.png");
Tsetpts[2] = carregaImagem("imagem/dois.png");
Tlogo = carregaImagem("imagem/logo.png");
Tbarra1 = carregaImagem("imagem/barra1.png");
Tbarra2 = carregaImagem("imagem/barra2.png");
Tresete = carregaImagem("imagem/resete.png");
}




#endif
