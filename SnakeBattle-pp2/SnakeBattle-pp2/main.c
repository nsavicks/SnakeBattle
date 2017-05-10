#include <SDL.h>
#include "grafika.h"
#include "gameplay.h"

int main() {
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;
	int menu_option = 1, n = 40, mapa[100][100] = { 0 }, brzina;
	zmija zm1, zm2, zm3, zm4;

	window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	setdefault(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina);

	while (1) {

		drawmenu(window, rend, &menu_option);

		switch (menu_option) {
		case 1:
			play(zm1, zm2, zm3, zm4, mapa, n, brzina, window, rend);
			break;
		case 2:
			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend);
			break;
		case 3:
			// o igri
			break;
		case 4:
			//highscore
			break;
		case 5:
			//autori
			break;
		case 6:
			izlaz(window, rend);
		}
	}
	return 0;
}