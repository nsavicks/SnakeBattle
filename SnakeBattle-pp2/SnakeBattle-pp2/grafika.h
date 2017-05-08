#pragma once
#ifndef grafika
#define grafika

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

// PROMENLJIVE

// DEFINICIJA FUNKCIJA //Crazy_snake.c za telo funkcija

void logSDLerror(char typeerror[]);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

SDL_Texture *loadTexture(char destination[], SDL_Renderer *ren);

void izlaz(SDL_Window *window, SDL_Renderer *renderer);

#endif // !grafika