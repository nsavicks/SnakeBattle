#pragma once
#ifndef grafika
#define grafika
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "gameplay.h"

#define SPORO 400
#define SREDNJE 200
#define BRZO 50
#define MALA 20
#define SREDNJA 30
#define VELIKA 40

typedef struct zm zmija;

// PROMENLJIVE

int SCREEN_WIDTH, SCREEN_HEIGHT, VEL;

// DEFINICIJA FUNKCIJA //Crazy_snake.c za telo funkcija

void ispis(SDL_Window *window, SDL_Renderer *renderer, zmija z1, zmija z2, zmija z3, zmija z4, int mapa[][100], int n);

void logSDLerror(char typeerror[]);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

SDL_Texture *loadTexture(char destination[], SDL_Renderer *ren);

void izlaz(SDL_Window *window, SDL_Renderer *renderer);

void drawmenu(SDL_Window *window, SDL_Renderer *renderer, int *menu);

void opcije(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], int *n,int *brzina, SDL_Window *window, SDL_Renderer *renderer);

#endif // !grafika/