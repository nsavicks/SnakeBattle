#include <SDL.h>
#include "grafika.h"
#include "gameplay.h"

int main() {
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;
	int menu_option = 1, n, brzina, i, j, mapa[100][100] = { 0 };
	zmija zm1, zm2, zm3, zm4;

	
	setdefault(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina);
	VEL = 30;

	while (1) {


		window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
		rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		drawmenu(window, rend, &menu_option);

		switch (menu_option) {
		case 1:
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);
			window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			podesimapu(&zm1, &zm2, &zm3, &zm4, mapa, n);
			play(zm1, zm2, zm3, zm4, mapa, n, brzina, window, rend);

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);
			break;
		case 2:
			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend);
			VEL = 600 / n;
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