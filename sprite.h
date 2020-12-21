#ifndef SPRITE_H
#define SPRITE_H
#include<math.h>
typedef struct Sprite{

	float x;
	float y;
	float comprimento;
	float largura;

}Sprite;
typedef struct Bolinha{

	int x,y,z,vertices;
	double raio;
	double t;

}Bolinha;

#endif
