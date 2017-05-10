#include "gameplay.h"
#include "grafika.h"

void logSDLerror(char typeerror[]) {
	printf("%s Sdl error: %s\n", typeerror, SDL_GetError());
}

SDL_Texture *loadTexture(char s[], SDL_Renderer *ren) {
	SDL_Texture *texture = IMG_LoadTexture(ren, s);
	if (texture == NULL)
		logSDLerror("IMG Load texture");
	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h) {
	SDL_Rect dist;
	dist.x = x; dist.y = y; dist.w = w; dist.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dist);
}

void izlaz(SDL_Window *window, SDL_Renderer *renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	exit(1);
}


void ispis(SDL_Window *window, SDL_Renderer *renderer, zmija z1, zmija z2, zmija z3, zmija z4, int mapa[][100], int n) {
	SDL_Texture *image = NULL;
	int i, j;
	image = loadTexture("img/gp_background.png", renderer);
	renderTexture(image, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_DestroyTexture(image);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			switch (mapa[i][j]) {
			case 1:
				if (z1.glava.i == i && z1.glava.j == j) {
					switch (z1.smer) {
					case DOLE:
						image = loadTexture("img/z1_down.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case GORE:
						image = loadTexture("img/z1_up.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case DESNO:
						image = loadTexture("img/z1_right.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z1_left.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z1_body.png", renderer);
					renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 2:
				if (z2.glava.i == i && z2.glava.j == j) {
					switch (z2.smer) {
					case DOLE:
						image = loadTexture("img/z2_down.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case GORE:
						image = loadTexture("img/z2_up.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case DESNO:
						image = loadTexture("img/z2_right.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z2_left.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z2_body.png", renderer);
					renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 3:
				if (z3.glava.i == i && z3.glava.j == j) {
					switch (z3.smer) {
					case DOLE:
						image = loadTexture("img/z3_down.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case GORE:
						image = loadTexture("img/z3_up.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case DESNO:
						image = loadTexture("img/z3_right.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z3_left.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z3_body.png", renderer);
					renderTexture(image, renderer, i * VEL, j *VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 4:
				if (z4.glava.i == i && z4.glava.j == j) {
					switch (z4.smer) {
					case DOLE:
						image = loadTexture("img/z4_down.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case GORE:
						image = loadTexture("img/z4_up.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case DESNO:
						image = loadTexture("img/z4_right.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z4_left.png", renderer);
						renderTexture(image, renderer, i * VEL, j * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z4_body.png", renderer);
					renderTexture(image, renderer, i * VEL, j *VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 0:
				break;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
}


void drawmenu(SDL_Window *window, SDL_Renderer *renderer, int *menu) {

	window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int chosen = 0;
	while (!chosen) {
		int  x, y;
		int i, j, p;
		SDL_Event e;
		SDL_Texture *image;

		image = loadTexture("img/menu/background.jpg", renderer);
		renderTexture(image, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/logo.png", renderer);
		renderTexture(image, renderer, 200, 10, 200, 200);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/novaigra.png", renderer);
		renderTexture(image, renderer, 200, 200, 200, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/opcije.png", renderer);
		renderTexture(image, renderer, 200, 260, 200, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/oigri.png", renderer);
		renderTexture(image, renderer, 200, 320, 200, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/highscore.png", renderer);
		renderTexture(image, renderer, 200, 380, 200, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/autori.png", renderer);
		renderTexture(image, renderer, 200, 440, 200, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/menu/izlazak.png", renderer);
		renderTexture(image, renderer, 200, 500, 200, 50);
		SDL_DestroyTexture(image);

		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEMOTION:
				i = e.motion.x; j = e.motion.y;

				if (i >= 200 && i <= 400 && j >= 200 && j <= 250)
					*menu = 1;
				else if (i >= 200 && i <= 400 && j >= 260 && j <= 310)
					*menu = 2;
				else if (i >= 200 && i <= 400 && j >= 320 && j <= 370)
					*menu = 3;
				else if (i >= 200 && i <= 400 && j >= 380 && j <= 430)
					*menu = 4;
				else if (i >= 200 && i <= 400 && j >= 440 && j <= 490)
					*menu = 5;
				else if (i >= 200 && i <= 400 && j >= 500 && j <= 550)
					*menu = 6;
				else
					*menu = 0;		
				break;
			case SDL_MOUSEBUTTONDOWN:
				i = e.motion.x; j = e.motion.y;

				if (i >= 200 && i <= 400 && j >= 200 && j <= 250) {
					chosen = 1;
					*menu = 1;
				}
				else if (i >= 200 && i <= 400 && j >= 260 && j <= 310) {
					*menu = 2;
					chosen = 1;
				}
				if (i >= 200 && i <= 400 && j >= 500 && j <= 550) {
					izlaz(window, renderer);
					chosen = 1;
				}
			default:	
				break;
			}
		}

		if (*menu > 0) {
			image = loadTexture("img/menu/strelica.png", renderer);
			renderTexture(image, renderer, 205, 210 + (*menu - 1) * 60, 30, 30);
			SDL_DestroyTexture(image);
		}

		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
}

void opcije(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], int *n, int *brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int nazad = 0, i, j;
	SDL_Texture *image;
	SDL_Event e;

	while (!nazad) {
		int chosen = 0;
		image = loadTexture("img/menu/background.jpg", renderer);
		renderTexture(image, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_DestroyTexture(image);

		image = loadTexture("img/opcije/nazad.png", renderer);
		renderTexture(image, renderer, 0, 0, 50, 50);
		SDL_DestroyTexture(image);

		if (SCREEN_WIDTH == 600 && SCREEN_HEIGHT == 600) {
			image = loadTexture("img/opcije/600x600.png", renderer);
			renderTexture(image, renderer, 200, 100, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (SCREEN_WIDTH == 800 && SCREEN_HEIGHT == 800) {
			image = loadTexture("img/opcije/800x800.png", renderer);
			renderTexture(image, renderer, 200, 100, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (SCREEN_WIDTH == 1000 && SCREEN_HEIGHT == 1000) {
			image = loadTexture("img/opcije/600x600.png", renderer);
			renderTexture(image, renderer, 200, 100, 200, 80);
			SDL_DestroyTexture(image);
		}

		if (*n == MALA) {
			image = loadTexture("img/opcije/malamapa.png", renderer);
			renderTexture(image, renderer, 200, 200, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (*n == SREDNJA) {
			image = loadTexture("img/opcije/srednjamapa.png", renderer);
			renderTexture(image, renderer, 200, 200, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (*n == VELIKA) {
			image = loadTexture("img/opcije/velikamapa.png", renderer);
			renderTexture(image, renderer, 200, 200, 200, 80);
			SDL_DestroyTexture(image);
		}

		if (*brzina == SPORO) {
			image = loadTexture("img/opcije/sporo.png", renderer);
			renderTexture(image, renderer, 200, 300, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (*brzina == SREDNJE) {
			image = loadTexture("img/opcije/srednje.png", renderer);
			renderTexture(image, renderer, 200, 300, 200, 80);
			SDL_DestroyTexture(image);
		}
		else if (*brzina == BRZO) {
			image = loadTexture("img/opcije/brzo.png", renderer);
			renderTexture(image, renderer, 200, 300, 200, 80);
			SDL_DestroyTexture(image);
		}

		SDL_RenderPresent(renderer);

		image = loadTexture("img/opcije/igraci.png", renderer);
		renderTexture(image, renderer, 200, 400, 200, 80);
		SDL_DestroyTexture(image);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEMOTION:
				if (i > 0 && i < 50 && j > 0 && j < 30) {
					image = loadTexture("img/menu/strelica.png", renderer);
					renderTexture(image, renderer, 0, 25, 20, 20);
					SDL_DestroyTexture(image);
					chosen = 0;
				}
				if (i > 200 && i < 250 && j > 100 && j < 180) {
					image = loadTexture("img/opcije/svetli_left", renderer);
					renderTexture(image, renderer, 200, 100, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 350 && i < 400 && j > 100 && j < 180) {
					//rezolucija vise
					image = loadTexture("img/opcije/svetli_right", renderer);
					renderTexture(image, renderer, 350, 100, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 200 && i < 250 && j > 200 && j < 280) {
					// mapa manje
					image = loadTexture("img/opcije/svetli_left", renderer);
					renderTexture(image, renderer, 200, 200, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 350 && i < 400 && j > 200 && j < 280) {
					//mapa vise
					image = loadTexture("img/opcije/svetli_right", renderer);
					renderTexture(image, renderer, 350, 200, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 200 && i < 250 && j > 300 && j < 380) {
					//brzina manje
					image = loadTexture("img/opcije/svetli_left", renderer);
					renderTexture(image, renderer, 200, 300, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 350 && i < 400 && j > 300 && j < 380) {
					//brzina vise
					image = loadTexture("img/opcije/svetli_right", renderer);
					renderTexture(image, renderer, 350, 300, 50, 80);
					SDL_DestroyTexture(image);
				}
				if (i > 200 && i < 400 && j > 400 && j < 480) {
					//  opcije igraca
					image = loadTexture("img/menu/strelica.png", renderer);
					renderTexture(image, renderer, 200, 420, 40, 40);
					SDL_DestroyTexture(image);
					chosen = 0; 
				}
				break;
			default: break;
			}
		} // mousemotion

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&e)) {
			i = e.motion.x; j = e.motion.y;
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				if (i > 0 && i < 50 && j > 0 && j < 30) {
					nazad = 1;
				}
				else if (i > 200 && i < 250 && j > 100 && j < 180) {
					if (SCREEN_WIDTH == 600)
						SCREEN_WIDTH = SCREEN_HEIGHT = 1000;
					else if (SCREEN_WIDTH == 800)
						SCREEN_WIDTH = SCREEN_HEIGHT = 600;
					else if (SCREEN_WIDTH == 1000)
						SCREEN_WIDTH = SCREEN_HEIGHT = 800;
				}
				else if (i > 350 && i < 400 && j > 100 && j < 180) {
					//rezolucija vise
					if (SCREEN_WIDTH == 600)
						SCREEN_WIDTH = SCREEN_HEIGHT = 800;
					else if (SCREEN_WIDTH == 800)
						SCREEN_WIDTH = SCREEN_HEIGHT = 1000;
					else if (SCREEN_WIDTH == 1000)
						SCREEN_WIDTH = SCREEN_HEIGHT = 600;
				}
				else if (i > 200 && i < 250 && j > 200 && j < 280) {
					//mapa manje
					if (*n == MALA)
						*n = VELIKA;
					else if (*n == SREDNJA)
						*n = MALA;
					else if (*n == VELIKA)
						*n = SREDNJA;
				}
				else if (i > 350 && i < 400 && j > 200 && j < 280) {
					//mapa vise
					if (*n == MALA)
						*n = SREDNJA;
					else if (*n == SREDNJA)
						*n = VELIKA;
					else if (*n == VELIKA)
						*n = MALA;
				}
				else if (i > 200 && i < 250 && j > 300 && j < 380) {
					//tezina manje
					if (*brzina == SPORO)
						*brzina = BRZO;
					else if (*brzina == SREDNJE)
						*brzina = SPORO;
					else if (*brzina == BRZO)
						*brzina = SREDNJE;
				}
				else if (i > 350 && i < 400 && j > 300 && j < 380) {
					//tezina vise
					if (*brzina == SPORO)
						*brzina = SREDNJE;
					else if (*brzina == SREDNJE)
						*brzina = BRZO;
					else if (*brzina == BRZO)
						*brzina = SPORO;
				}
				else if (i > 200 && i < 400 && j > 400 && j < 480) {
					// opcije igraca
					players(zm1, zm2, zm3, zm4, mapa, window, renderer);
				}
				break;
			default: break;
			}
		} // mouse button down

		SDL_RenderClear(renderer);
	}
}

void players(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], SDL_Window *window, SDL_Renderer *renderer) {


}