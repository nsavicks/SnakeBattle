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
	VEL = 30;
	window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while (1) {
		opcija = prikaziMeni(window, rend);
		switch (opcija) {
		case 1:
			SDL_RenderClear(rend);
			SDL_RenderPresent(rend);
			SDL_Delay(5000);
			break;
		case 2:
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