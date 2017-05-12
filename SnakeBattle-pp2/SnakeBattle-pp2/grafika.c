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
	image = loadTexture("img/gp_background.jpg", renderer);
	renderTexture(image, renderer, 0, 0, 600, 600);
	SDL_DestroyTexture(image);
	image = loadTexture("img/gp_side.jpg", renderer);
	renderTexture(image, renderer, 600, 0, 200, 600);
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
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z3_left.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z3_body.png", renderer);
					renderTexture(image, renderer, j * VEL, i *VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 4:
				if (z4.glava.i == i && z4.glava.j == j) {
					switch (z4.smer) {
					case DOLE:
						image = loadTexture("img/z4_down.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case GORE:
						image = loadTexture("img/z4_up.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case DESNO:
						image = loadTexture("img/z4_right.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					case LEVO:
						image = loadTexture("img/z4_left.png", renderer);
						renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
						SDL_DestroyTexture(image);
						break;
					}
				}
				else {
					image = loadTexture("img/z4_body.png", renderer);
					renderTexture(image, renderer, j * VEL, i *VEL, VEL, VEL);
					SDL_DestroyTexture(image);
				}
				break;
			case 0:
				break;
			}
		}
		SDL_RenderPresent(renderer);
		//SDL_RenderClear(renderer);
		
}

void drawmenu(SDL_Window *window, SDL_Renderer *renderer, int *menu) {

	int chosen = 0;
	while (!chosen) {
		int  x, y;
		int i, j, p;
		SDL_Event e;
		SDL_Texture *image;

		image = loadTexture("img/menu/background.jpg", renderer);
		renderTexture(image, renderer, 0, 0, 600, 600);
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

		

		if (SDL_WaitEvent(&e)!=0){
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
				break;
			case SDL_QUIT:
				izlaz(window, renderer);
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
	}
	SDL_RenderClear(renderer);
}

void opcije(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], int *n, int *brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int nazad = 0, i, j, k = 0;
	SDL_Texture *image;
	SDL_Event e;
	while (!nazad) {
		image = loadTexture("img/menu/background.jpg", renderer);
		renderTexture(image, renderer, 0, 0, 600, 600);
		SDL_DestroyTexture(image);

		image = loadTexture("img/opcije/nazad.jpg", renderer);
		renderTexture(image, renderer, 0, 0, 50, 50);
		SDL_DestroyTexture(image);

		if (*n == MALA) {
			image = loadTexture("img/opcije/velicinamala.png", renderer);
			renderTexture(image, renderer, 150, 50, 300, 80);
			SDL_DestroyTexture(image);
		}
		else if (*n == SREDNJA) {
			image = loadTexture("img/opcije/velicinasrednja.png", renderer);
			renderTexture(image, renderer, 150, 50, 300, 80);
			SDL_DestroyTexture(image);
		}
		else if (*n == VELIKA) {
			image = loadTexture("img/opcije/velicinavelika.png", renderer);
			renderTexture(image, renderer, 150, 50, 300, 80);
			SDL_DestroyTexture(image);
		}

		if (*brzina == SPORO) {
			image = loadTexture("img/opcije/brzinasporo.png", renderer);
			renderTexture(image, renderer, 150, 150, 300, 80);
			SDL_DestroyTexture(image);
		}
		else if (*brzina == SREDNJE) {
			image = loadTexture("img/opcije/brzinasrednje.png", renderer);
			renderTexture(image, renderer, 150, 150, 300, 80);
			SDL_DestroyTexture(image);
		}
		else if (*brzina == BRZO) {
			image = loadTexture("img/opcije/brzinabrzo.png", renderer);
			renderTexture(image, renderer, 150, 150, 300, 80);
			SDL_DestroyTexture(image);
		}

		image = loadTexture("img/opcije/p1.png", renderer);
		renderTexture(image, renderer, 10, 300, 50, 50);
		SDL_DestroyTexture(image);
		if (zm1->ziva == 1) {
			if (zm1->igrac == 0) {
				image = loadTexture("img/opcije/ai.png", renderer);
				renderTexture(image, renderer, 110, 300, 100, 50);
				SDL_DestroyTexture(image);
			}
			else {
				image = loadTexture("img/opcije/cpu1.png", renderer);
				renderTexture(image, renderer, 110, 300, 100, 50);
				SDL_DestroyTexture(image);
			}
		}
		else {
			image = loadTexture("img/opcije/off.png", renderer);
			renderTexture(image, renderer, 110, 300, 100, 50);
			SDL_DestroyTexture(image);
		}
		if (zm1->ziva) {
			if (zm1->igrac == 0) {
				if (zm1->tezina == 1) {
					image = loadTexture("img/opcije/easy.png", renderer);
					renderTexture(image, renderer, 270, 300, 100, 50);
					SDL_DestroyTexture(image);
				}
				else {
					image = loadTexture("img/opcije/hard.png", renderer);
					renderTexture(image, renderer, 270, 300, 100, 50);
					SDL_DestroyTexture(image);
				}
			}
		}
		image = loadTexture("img/z1_body.png", renderer);
		renderTexture(image, renderer, 450, 300, 100, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/opcije/p2.png", renderer);
		renderTexture(image, renderer, 10, 375, 50, 50);
		SDL_DestroyTexture(image);
		if (zm2->ziva == 1) {
			if (zm2->igrac == 0) {
				image = loadTexture("img/opcije/ai.png", renderer);
				renderTexture(image, renderer, 110, 375, 100, 50);
				SDL_DestroyTexture(image);
			}
			else {
				image = loadTexture("img/opcije/cpu2.png", renderer);
				renderTexture(image, renderer, 110, 375, 100, 50);
				SDL_DestroyTexture(image);
			}
		}
		else {
			image = loadTexture("img/opcije/off.png", renderer);
			renderTexture(image, renderer, 110, 375, 100, 50);
			SDL_DestroyTexture(image);
		}
		if (zm2->ziva) {
			if (zm2->igrac == 0) {
				if (zm2->tezina == 1) {
					image = loadTexture("img/opcije/easy.png", renderer);
					renderTexture(image, renderer, 270, 375, 100, 50);
					SDL_DestroyTexture(image);
				}
				else {
					image = loadTexture("img/opcije/hard.png", renderer);
					renderTexture(image, renderer, 270, 375, 100, 50);
					SDL_DestroyTexture(image);
				}
			}
		}
		image = loadTexture("img/z2_body.png", renderer);
		renderTexture(image, renderer, 450, 375, 100, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/opcije/p3.png", renderer);
		renderTexture(image, renderer, 10, 450, 50, 50);
		SDL_DestroyTexture(image);
		if (zm3->ziva == 1) {
			image = loadTexture("img/opcije/ai.png", renderer);
			renderTexture(image, renderer, 110 , 450, 100, 50);
			SDL_DestroyTexture(image);
		}
		else {
			image = loadTexture("img/opcije/off.png", renderer);
			renderTexture(image, renderer, 110, 450, 100, 50);
			SDL_DestroyTexture(image);
		}
		if (zm3->ziva) {
			if (zm3->tezina == 1) {
				image = loadTexture("img/opcije/easy.png", renderer);
				renderTexture(image, renderer, 270, 450, 100, 50);
				SDL_DestroyTexture(image);
			}
			else {
				image = loadTexture("img/opcije/hard.png", renderer);
				renderTexture(image, renderer, 270, 450, 100, 50);
				SDL_DestroyTexture(image);
			}
		}
		image = loadTexture("img/z3_body.png", renderer);
		renderTexture(image, renderer, 450, 450, 100, 50);
		SDL_DestroyTexture(image);

		image = loadTexture("img/opcije/p4.png", renderer);
		renderTexture(image, renderer, 10, 525, 50, 50);
		SDL_DestroyTexture(image);
		if (zm4->ziva == 1) {
			image = loadTexture("img/opcije/ai.png", renderer);
			renderTexture(image, renderer, 110, 525, 100, 50);
			SDL_DestroyTexture(image);
		}
		else {
			image = loadTexture("img/opcije/off.png", renderer);
			renderTexture(image, renderer, 110, 525, 100, 50);
			SDL_DestroyTexture(image);
		}
		if (zm4->ziva) {
			if (zm4->tezina == 1) {
				image = loadTexture("img/opcije/easy.png", renderer);
				renderTexture(image, renderer, 270, 525, 100, 50);
				SDL_DestroyTexture(image);
			}
			else {
				image = loadTexture("img/opcije/hard.png", renderer);
				renderTexture(image, renderer, 270, 525, 100, 50);
				SDL_DestroyTexture(image);
			}
		}
		image = loadTexture("img/z4_body.png", renderer);
		renderTexture(image, renderer, 450, 525, 100, 50);
		SDL_DestroyTexture(image);

		if (SDL_WaitEvent(&e)!=0) {
			i = e.motion.x; j = e.motion.y;
			switch (e.type) {
			case SDL_MOUSEMOTION:
				if (i > 150 && i < 200 && j > 50 && j < 130) 
					k = 1;
				else if (i > 400 && i < 450 && j > 50 && j < 130) 
					k = 2;
				else if (i > 150 && i < 200 && j > 150 && j < 230) 
					k = 3;
				else if (i > 400 && i < 450 && j > 150 && j < 230)
					k = 4;
				else
					k = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (i > 0 && i < 50 && j > 0 && j < 50) {
					nazad = 1;
					SDL_DestroyRenderer(renderer);
					SDL_DestroyWindow(window);
					continue;
				}
				if (i > 150 && i < 200 && j > 50 && j < 130) {
					if (*n == MALA)
						*n = VELIKA;
					else if (*n == SREDNJA)
						*n = MALA;
					else if (*n == VELIKA)
						*n = SREDNJA;
				}
				else if (i > 400 && i < 450 && j > 50 && j < 130) {
					if (*n == MALA)
						*n = SREDNJA;
					else if (*n == SREDNJA)
						*n = VELIKA;
					else if (*n == VELIKA)
						*n = MALA;
				}
				else if (i > 150 && i < 200 && j > 150 && j < 230) {
					if (*brzina == SPORO)
						*brzina = BRZO;
					else if (*brzina == SREDNJE)
						*brzina = SPORO;
					else if (*brzina == BRZO)
						*brzina = SREDNJE;
				}
				else if (i > 400 && i < 450 && j > 150 && j < 230) {
					if (*brzina == SPORO)
						*brzina = SREDNJE;
					else if (*brzina == SREDNJE)
						*brzina = BRZO;
					else if (*brzina == BRZO)
						*brzina = SPORO;
				}
				else if (i > 110 && i < 210 && j > 300 && j < 350) {
					//p1
					if (zm1->ziva == 0) {
						zm1->ziva = 1;
						zm1->igrac = 1;
					}
					else if (zm1->ziva && zm1->igrac) {
						zm1->igrac = 0;
						zm1->tezina = 1;
					}
					else if (zm1->ziva && (zm1->igrac == 0)) {
						zm1->ziva = 0;
					}
						
				}
				else if (i > 270 && i < 370 && j > 300 && j < 350) {
					//p1
					if (zm1->ziva && !zm1->igrac) {
						if (zm1->tezina == 1)
							zm1->tezina = 2;
						else
							zm1->tezina = 1;
					}
				}
				else if (i > 110 && i < 210 && j > 375 && j < 425) {
					//p2
					if (zm2->ziva == 0) {
						zm2->ziva = 1;
						zm2->igrac = 1;
					}
					else if (zm2->ziva && zm2->igrac) {
						zm2->igrac = 0;
						zm2->tezina = 1;
					}
					else if (zm2->ziva && (zm2->igrac == 0)) {
						zm2->ziva = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 375 && j < 425) {
					//p2
					if (zm2->ziva && !zm2->igrac) {
						if (zm2->tezina == 1)
							zm2->tezina = 2;
						else
							zm2->tezina = 1;
					}
				}
				else if (i > 110 && i < 210 && j > 450 && j < 500) {
					//p3
					if (zm3->ziva) {
						zm3->ziva = 0;
					}
					else {
						zm3->ziva = 1;
						zm3->tezina = 1;
						zm3->igrac = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 450 && j < 500) {
					//p3
					if (zm3->ziva) {
						if (zm3->tezina == 1)
							zm3->tezina = 2;
						else
							zm3->tezina = 1;
					}
				}
				else if (i > 110 && i < 210 && j > 525 && j < 575) {
					//p4
					if (zm4->ziva) {
						zm4->ziva = 0;
					}
					else {
						zm4->ziva = 1;
						zm4->tezina = 1;
						zm4->igrac = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 525 && j < 575) {
					//p4
					if (zm4->ziva) {
						if (zm4->tezina == 1)
							zm4->tezina = 2;
						else
							zm4->tezina = 1;
					}
				}
				break;
			case SDL_QUIT:
				izlaz(window, renderer);
			default: break;
			}
		}
		switch (k) {
		case 1:
			image = loadTexture("img/opcije/strelicaL.png", renderer);
			renderTexture(image, renderer, 150, 50, 50, 80);
			SDL_DestroyTexture(image);
			break;
		case 2:
			image = loadTexture("img/opcije/strelicaD.png", renderer);
			renderTexture(image, renderer, 400, 50, 50, 80);
			SDL_DestroyTexture(image);
			break;
		case 3:
			image = loadTexture("img/opcije/strelicaL.png", renderer);
			renderTexture(image, renderer, 150, 150, 50, 80);
			SDL_DestroyTexture(image);
			break;
		case 4:
			image = loadTexture("img/opcije/strelicaD.png", renderer);
			renderTexture(image, renderer, 400, 150, 50, 80);
			SDL_DestroyTexture(image);
			break;
		default:
			break;
		}
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
}