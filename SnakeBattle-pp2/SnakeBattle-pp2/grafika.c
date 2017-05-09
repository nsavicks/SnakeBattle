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


int handle(int *menu) {
	
}
void drawmenu(SDL_Window *window, SDL_Renderer *renderer, int *menu) {
	int  x, y;
	int i, j,p;
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

	SDL_RenderPresent(renderer);
	
	p = 1;
	while (p) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEMOTION:
				i = e.motion.x; j = e.motion.y;
				//printf("%d %d\n", i, j);
				if (i >= 200 && i <= 400 && j >= 200 && j <= 250) {
					*menu = 1;
				}
				else
					if (i >= 200 && i <= 400 && j >= 260 && j <= 310) {
						*menu = 2;
					}
					else
						if (i >= 200 && i <= 400 && j >= 320 && j <= 370) {
							*menu = 3;
						}
						else
							if (i >= 200 && i <= 400 && j >= 380 && j <= 430) {
								*menu = 4;
							}
							else
								if (i >= 200 && i <= 400 && j >= 440 && j <= 490) {
									*menu = 5;
								}
								else
									if (i >= 200 && i <= 400 && j >= 500 && j <= 550) {
										*menu = 6;
									}
									else
									{
										*menu = 0;
									}
				if (*menu > 0) {
					image = loadTexture("img/menu/strelica.png", renderer);
					renderTexture(image, renderer, 205, 210 + (*menu - 1) * 60, 30, 30);
					SDL_DestroyTexture(image);
					SDL_RenderPresent(renderer);

				}
				else {
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

					SDL_RenderPresent(renderer);
				}
				break;
			default:	break;
			}
		}

	}
	
}
