#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>


#pragma once
#ifndef grafika
#define grafika

typedef struct zm zmija;

// PROMENLJIVE

int SCREEN_WIDTH, SCREEN_HEIGHT, VEL;

// DEFINICIJA FUNKCIJA //Crazy_snake.c za telo funkcija

int fja(zmija z);

void logSDLerror(char typeerror[]);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

SDL_Texture *loadTexture(char destination[], SDL_Renderer *ren);

void izlaz(SDL_Window *window, SDL_Renderer *renderer);



#endif // !grafika