#pragma once
#ifndef grafika
#define grafika

#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>


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

int handle_key(int *menu);
#endif // !grafika/