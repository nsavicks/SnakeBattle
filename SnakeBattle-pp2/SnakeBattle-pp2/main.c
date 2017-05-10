#include <SDL.h>
#include "grafika.h"
#include "gameplay.h"

int main() {
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;
	int menu_option = 1, n = 40, mapa[100][100] = { 0 }, brzina = SPORO;
	SCREEN_WIDTH = 600;
	SCREEN_HEIGHT = 600;
	zmija zm1, zm2, zm3, zm4;
	zm2.ziva = zm3.ziva = zm4.ziva = 0;
	VEL = 40;
	zm1.duzina = 1;
	zm1.glava.i = zm1.glava.j = zm1.rep.i = zm1.rep.j = 5;
	zm1.redni = 1;
	zm1.smer = GORE;
	zm1.telo[0] = zm1.glava;
	zm1.ziva = 1;
	mapa[5][5] = 1;

	while (1) {
		drawmenu(window, rend, &menu_option);
		if (menu_option == 1) {
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);

			window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			play(zm1, zm2, zm3, zm4, mapa, n, brzina, window, rend);

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);
		}
		else if (menu_option == 2) {
			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend);
		}
	}
	return 0;
}