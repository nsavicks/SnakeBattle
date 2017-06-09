#pragma once
#ifndef gameplay
#define gameplay

#define GORE 0
#define DESNO 1
#define DOLE 2
#define LEVO 3
#define SPORO 100
#define SREDNJE 75
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
	char *username;
	float rezultat;
}osoba;

typedef struct {
	koord x[10000];
	int front, rear;
} queue;

int q_empty(queue q);

queue q_init();

koord q_delete(queue *q);

void q_insert(queue *q, koord a);

int bfs(int si, int sj, int n, int mapa[][100]);

zmija kill(zmija z, int mapa[][100]);

zmija nextMove(zmija z, int mapa[][100], int n, SDL_Window *window, SDL_Renderer *renderer, int *killed);

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window* window, SDL_Renderer* renderer);

void setdefault(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int *n, int *brzina);

void podesimapu(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n);

void checkHighscore(float vreme, int vel_mape, SDL_Window *window, SDL_Renderer *renderer, int pobednik);

char *ucitaj(SDL_Window *window, SDL_Renderer *renderer,float vreme,int pobednik);

char *crypt(char *str);

char *decrypt(char *str);

void AiEasy(zmija *z, int mapa[][100], int n);

void AiHard(zmija *z, int mapa[][100], int n);

#endif