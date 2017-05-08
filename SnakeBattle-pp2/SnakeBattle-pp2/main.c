#include <SDL.h>
#include "grafika.h"
#include "gameplay.h"


int main() {

	
	SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	zmija zm1,zm2,zm3,zm4;
	zm3.ziva = zm4.ziva = 0;
	VEL = 40;
	int n = 20;
	int mapa[100][100] = { 0 };
	zm1.duzina = 1;
	zm1.glava.i = zm1.glava.j = zm1.rep.i = zm1.rep.j = 5;
	zm1.redni = 1;
	zm1.smer = GORE;
	zm1.telo[0] = zm1.glava;
	zm1.ziva = 1;
	mapa[5][5] = 1;

	zm2.duzina = 1;
	zm2.glava.i = zm2.glava.j = zm2.rep.i = zm2.rep.j = 10;
	zm2.redni = 2;
	zm2.smer = LEVO;
	zm2.telo[0] = zm2.glava;
	zm2.ziva = 1;
	mapa[10][10] = 2;
	int brzina = 1000;

	play(zm1, zm2, zm3, zm4, mapa, n, brzina, window, rend);


	return 0;
}