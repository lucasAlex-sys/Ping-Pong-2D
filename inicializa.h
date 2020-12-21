#ifndef INICIALIZA_H
#define INICIALIZA_H
#include "sprite.h"
#include<math.h>
float MOVIMENTAPLAYER1 = 0;//responsavel por movimentar o player1
float MOVIMENTAPLAYER2 = 0;//responsavel por movimentar o player2
float posicaoAtualY = 0;//responsavel por moivimentar a bola no eixo y
float posicaoAtualX = 0;//responsavel por moivimentar a bola no eixo x
float velocidadeX =11;
float velocidadeY = 11;
int pontosPlayr1=0;//guarda a pontuacao do player1
int pontosPlayr2=0;//guarda a pontuacao do player2
int ESCAPE = 2;//esc
float rodando =0;
int PAUSE = 0 ;
int telaMenu = 0 ;
int telaComoJogar = 0;
int setpts2=0;
int setpts1=0;
int resete=0;
Bolinha bola;
Sprite player1;
Sprite player2;
Sprite estadio;

//valores inicias dos vertices
void inicializa(){
	
	
	//dados do player 1
	player1.x = 150;
	player1.y = 270;
	player1.comprimento = 60;
	player1.largura = 20;
	//dados player 2
	player2.x = 730;
	player2.y = 270;
	player2.comprimento = 60;
	player2.largura = 20;
	//dados estadio
	estadio.x = 150;
	estadio.y = 150;
	estadio.comprimento = 300;
	estadio.largura = 600;
	//dados bolinha
	bola.x = 450 ;
	bola.y = 300;
	bola.z = 0;
	bola.raio = 12 ;
	bola.vertices = 60;
	bola.t = 0;
	//imagem do fundo
	
	 

}
#endif
