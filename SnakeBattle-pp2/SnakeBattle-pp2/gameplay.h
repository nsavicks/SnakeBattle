#pragma once
#ifndef gameplay
#define gameplay

#define GORE 0
#define DESNO 1
#define DOLE 2
#define LEVO 3
#include <stdio.h>
#include <stdlib.h>
#include "grafika.h"

typedef struct ko {
	int i, j;
}koord;
typedef struct zm {
	koord rep, glava, telo[100];
	int duzina;
	short smer, ziva, igrac, tezina, redni;
}zmija;


zmija kill(zmija z, int mapa[][100]);
zmija nextMove(zmija z, int mapa[][100], int n);
void pokreniSve(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n);
void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window* window, SDL_Renderer* renderer);


#endif 