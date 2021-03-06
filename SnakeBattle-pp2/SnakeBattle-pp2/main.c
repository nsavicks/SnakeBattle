#include "grafika.h"
#include "gameplay.h"

int main() {
	srand(time(NULL));
	SDL_Window *window = NULL;
	SDL_Renderer *rend = NULL;
	SDL_Texture *image = NULL;
	int opcija, n, brzina, i, j, mapa[100][100] = { 0 }, muzika,kraj;
	zmija zm1, zm2, zm3, zm4;
	TTF_Init();
 

	window = SDL_CreateWindow("SnakeBattle v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



	setdefault(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, &muzika);

	while (1) {

		opcija = prikaziMeni(window, rend);

		switch (opcija) {
		case 1:
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);

			window = SDL_CreateWindow("SnakeBattle v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			kraj = 0;

			while (!kraj) {
				podesimapu(&zm1, &zm2, &zm3, &zm4, mapa, n);
				kraj=play(zm1, zm2, zm3, zm4, mapa, n, brzina, window, rend, muzika);
			}

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(rend);

			window = SDL_CreateWindow("SnakeBattle v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
			rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			break;
		case 2:
			opcije(&zm1, &zm2, &zm3, &zm4, mapa, &n, &brzina, window, rend, &muzika);
			break;
		case 3:
			prikaziHighscore(window, rend);
			break;
		case 4:

			oIgri(window, rend);
			break;
		case 5:

			Autori(window, rend);
			break;
		case 6:
			izlaz(window, rend);
			break;
		}
	}
	return 0;
}