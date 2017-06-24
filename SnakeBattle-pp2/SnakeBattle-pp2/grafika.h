#pragma once
#ifndef grafika
#define grafika

#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "gameplay.h"

#define MALA 20
#define SREDNJA 30
#define VELIKA 40

typedef struct zm zmija;

// PROMENLJIVE

int VEL;

// DEFINICIJA FUNKCIJA //Crazy_snake.c za telo funkcija
int prikaziMeni(SDL_Window *window, SDL_Renderer *renderer);

void logSDLerror(char typeerror[]);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

SDL_Texture *loadTexture(char destination[], SDL_Renderer *ren);

void izlaz(SDL_Window *window, SDL_Renderer *renderer);

void ispis(SDL_Window *window, SDL_Renderer *renderer, int mapa[][100], int n, zmija zm1, zmija zm2, zmija zm3, zmija zm4);

void opcije(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], int *n,int *brzina, SDL_Window *window, SDL_Renderer *renderer, int *muzika);

void update_screen(zmija zm, int mapa[][100], int n, SDL_Window *window, SDL_Renderer *renderer);

char *ucitaj(SDL_Window *window, SDL_Renderer *renderer, float vreme, int pobednik);

void prikaziHighscore(SDL_Window *window, SDL_Renderer *renderer);

void ispisHighscore(SDL_Window *window, SDL_Renderer *renderer, char *datoteka, int vel_mape);

void krajIgre(SDL_Window *window, SDL_Renderer *renderer, float vreme, int pobednik);

int pregame(SDL_Window *window, SDL_Renderer *renderer);

void oIgri(SDL_Window *window, SDL_Renderer *renderer);

void Autori(SDL_Window *window, SDL_Renderer *renderer);

#endif // !grafika/