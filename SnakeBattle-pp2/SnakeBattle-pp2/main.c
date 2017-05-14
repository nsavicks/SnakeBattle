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
			n = 30;
			podesimapu(&zm1, &zm2, &zm3, &zm4, mapa, n);
			/*for (i = 0; i < n; i++, printf("\n"))
				for (j = 0; j < n; j++, printf("%d ", mapa[i][j]));
			SDL_Delay(10000);*/
			SDL_DestroyWindow(window);
			window = SDL_CreateWindow("Play", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			play(zm1, zm2, zm3, zm4, mapa, n, 300, window, rend);
			break;
		case 2:
			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend);
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