#pragma once
#ifndef gameplay
#define gameplay

#define GORE 0
#define DESNO 1
#define DOLE 2
#define LEVO 3
#define SPORO 100
#define SREDNJE 50
#define BRZO 25

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <SDL_ttf.h>
#include "grafika.h"

typedef struct ko {
	int i, j;
}koord;
typedef struct zm {
	koord rep, glava, telo[1000];
	int duzina;
	short smer, ziva, igrac, tezina, redni;
}zmija;
typedef struct StOsoba {
	char *ime, *prezime;
	float rezultat;
}osoba;


zmija kill(zmija z, int mapa[][100]);

zmija nextMove(zmija z, int mapa[][100], int n, SDL_Window *window, SDL_Renderer *renderer, int *killed);

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window* window, SDL_Renderer* renderer);

void setdefault(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int *n, int *brzina);

void podesimapu(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n);

void checkHighscore(float vreme);

char *crypt(char *str);
char *decrypt(char *str);

#endif