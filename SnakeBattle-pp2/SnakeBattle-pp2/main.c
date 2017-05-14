#include <SDL.h>
#include "grafika.h"
#include "gameplay.h"

int main() {
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;
	int opcija, n, brzina, i, j, mapa[100][100] = { 0 };
	zmija zm1, zm2, zm3, zm4;
	TTF_Init();

	setdefault(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina);
	VEL = 600 / n;

	while (1) {
		window = SDL_CreateWindow("Play", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
		rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		opcija = prikaziMeni(window, rend);

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(rend);

		switch (opcija) {
		case 1:
			window = SDL_CreateWindow("Play", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			podesimapu(&zm1, &zm2, &zm3, &zm4, mapa, n);

			play(zm1, zm2, zm3, zm4, mapa, n, 300, window, rend);
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);
			break;
		case 2:
			window = SDL_CreateWindow("Play", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend);
			VEL = 600 / n;

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			izlaz(window, rend);
			break;
		}
	}
	return 0;
}