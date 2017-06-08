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
	exit(0);
}

int prikaziMeni(SDL_Window *window, SDL_Renderer *renderer) {
	SDL_Texture *image = NULL, *strelica=NULL;
	SDL_Event e;
	int i, j, k = 0;
	image = loadTexture("img/menipozadina.jpg", renderer);
	strelica = loadTexture("img/menu/strelica.png", renderer);
	while (1) {
		renderTexture(image, renderer, 0, 0, 600, 600);
		if (SDL_WaitEvent(&e)) {
			i = e.motion.x; j = e.motion.y;
			switch (e.type) {
			case SDL_MOUSEMOTION:
				if (i >= 200 && i <= 400 && j >= 170 && j <= 220) {
					k = 1;
				}
				else if (i >= 200 && i <= 400 && j >= 240 && j <= 290) {
					k = 2;
				}
				else if (i >= 200 && i <= 400 && j >= 310 && j <= 360) {
					k = 3;
				}
				else if (i >= 200 && i <= 400 && j >= 380 && j <= 430) {
					k = 4;
				}
				else if (i >= 200 && i <= 400 && j >= 450 && j <= 500) {
					k = 5;
				}
				else if (i >= 200 && i <= 400 && j >= 520 && j <= 570) {
					k = 6;
				}
				else
					k = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (i >= 200 && i <= 400 && j >= 170 && j <= 220) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 1;
				}
				if (i >= 200 && i <= 400 && j >= 240 && j <= 290) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 2;
				}
				if (i >= 200 && i <= 400 && j >= 310 && j <= 360) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 3;
				}
				if (i >= 200 && i <= 400 && j >= 380 && j <= 430) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 4;
				}
				if (i >= 200 && i <= 400 && j >= 450 && j <= 500) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 5;
				}
				if (i >= 200 && i <= 400 && j >= 520 && j <= 570) {
					SDL_DestroyTexture(strelica);
					SDL_DestroyTexture(image);
					return 6;
				}
				break;
			case SDL_QUIT:
				izlaz(window, renderer);
			default: 
				break;
			}
			switch (k) {
			case 1:
				renderTexture(strelica, renderer, 200, 180,30,30);
				break;
			case 2:
				renderTexture(strelica, renderer, 200, 250, 30,30);
				break;
			case 3:
				renderTexture(strelica, renderer, 200, 320, 30,30);
				break;
			case 4:
				renderTexture(strelica, renderer, 200, 390, 30,30);
				break;
			case 5:
				renderTexture(strelica, renderer, 200, 460, 30,30);
				break;
			case 6:
				renderTexture(strelica, renderer, 200, 530, 30,30);
				break;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
}

void ispis(SDL_Window *window, SDL_Renderer *renderer, int mapa[][100], int n, zmija zm1, zmija zm2, zmija zm3, zmija zm4) {
	int i, j;
	SDL_RenderClear(renderer);
	SDL_Texture *image[20] = { NULL };

	image[0] = loadTexture("img/z1_body.png", renderer);
	image[1] = loadTexture("img/z1_down.png", renderer);
	image[2] = loadTexture("img/z1_up.png", renderer);
	image[3] = loadTexture("img/z1_right.png", renderer);
	image[4] = loadTexture("img/z1_left.png", renderer);

	image[5] = loadTexture("img/z2_body.png", renderer);
	image[6] = loadTexture("img/z2_down.png", renderer);
	image[7] = loadTexture("img/z2_up.png", renderer);
	image[8] = loadTexture("img/z2_right.png", renderer);
	image[9] = loadTexture("img/z2_left.png", renderer);

	image[10] = loadTexture("img/z3_body.png", renderer);
	image[11] = loadTexture("img/z3_down.png", renderer);
	image[12] = loadTexture("img/z3_up.png", renderer);
	image[13] = loadTexture("img/z3_right.png", renderer);
	image[14] = loadTexture("img/z3_left.png", renderer);

	image[15] = loadTexture("img/z4_body.png", renderer);
	image[16] = loadTexture("img/z4_down.png", renderer);
	image[17] = loadTexture("img/z4_up.png", renderer);
	image[18] = loadTexture("img/z4_right.png", renderer);
	image[19] = loadTexture("img/z4_left.png", renderer);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			switch (mapa[i][j]) {
			case 1:
				if (zm1.glava.i != i || zm1.glava.j != j)
					renderTexture(image[0], renderer, j * VEL, i *VEL, VEL, VEL);
				else
					switch (zm1.smer) {
					case DOLE:
						renderTexture(image[1], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case GORE:
						renderTexture(image[2], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case DESNO:
						renderTexture(image[3], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case LEVO:
						renderTexture(image[4], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					}
				break;
			case 2:
				if (zm2.glava.i != i || zm2.glava.j != j)
					renderTexture(image[5], renderer, j * VEL, i *VEL, VEL, VEL);
				else
					switch (zm2.smer) {
					case DOLE:
						renderTexture(image[6], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case GORE:
						renderTexture(image[7], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case DESNO:
						renderTexture(image[8], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case LEVO:
						renderTexture(image[9], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					}
				break;
			case 3:
				if (zm3.glava.i != i || zm3.glava.j != j)
					renderTexture(image[10], renderer, j * VEL, i *VEL, VEL, VEL);
				else
					switch (zm3.smer) {
					case DOLE:
						renderTexture(image[11], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case GORE:
						renderTexture(image[12], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case DESNO:
						renderTexture(image[13], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case LEVO:
						renderTexture(image[14], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					}
				break;
			case 4:
				if (zm4.glava.i != i || zm4.glava.j != j)
					renderTexture(image[15], renderer, j * VEL, i *VEL, VEL, VEL);
				else
					switch (zm4.smer) {
					case DOLE:
						renderTexture(image[16], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case GORE:
						renderTexture(image[17], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case DESNO:
						renderTexture(image[18], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					case LEVO:
						renderTexture(image[19], renderer, j * VEL, i *VEL, VEL, VEL);
						break;
					}
				break;
			}
		}
	}
	SDL_RenderPresent(renderer);
	for (int i = 0; i < 20; i++)
		SDL_DestroyTexture(image[i]);
}

void opcije(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[100][100], int *n, int *brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int nazad = 0, i, j, k = 0;
	SDL_Texture *image[24];
	image[0] = loadTexture("img/menu/background.jpg", renderer);
	image[1] = loadTexture("img/opcije/nazad.jpg", renderer);
	image[2] = loadTexture("img/opcije/velicinamala.png", renderer);
	image[3] = loadTexture("img/opcije/velicinasrednja.png", renderer);
	image[4] = loadTexture("img/opcije/velicinavelika.png", renderer);
	image[5] = loadTexture("img/opcije/brzinasporo.png", renderer);
	image[6] = loadTexture("img/opcije/brzinasrednje.png", renderer);
	image[7] = loadTexture("img/opcije/brzinabrzo.png", renderer);
	image[8] = loadTexture("img/opcije/p1.png", renderer);
	image[9] = loadTexture("img/opcije/p2.png", renderer);
	image[10] = loadTexture("img/opcije/p3.png", renderer);
	image[11] = loadTexture("img/opcije/p4.png", renderer);
	image[12] = loadTexture("img/opcije/off.png", renderer);
	image[13] = loadTexture("img/opcije/ai.png", renderer);
	image[14] = loadTexture("img/opcije/cpu1.png", renderer);
	image[15] = loadTexture("img/opcije/cpu2.png", renderer);
	image[16] = loadTexture("img/opcije/easy.png", renderer);
	image[17] = loadTexture("img/opcije/hard.png", renderer);
	image[18] = loadTexture("img/z1_body.png", renderer);
	image[19] = loadTexture("img/z2_body.png", renderer);
	image[20] = loadTexture("img/z3_body.png", renderer);
	image[21] = loadTexture("img/z4_body.png", renderer);
	image[22] = loadTexture("img/opcije/strelicaL.png", renderer);
	image[23] = loadTexture("img/opcije/strelicaD.png", renderer);
	SDL_Event e;
	while (!nazad) {
		renderTexture(image[0], renderer, 0, 0, 600, 600);

		renderTexture(image[1], renderer, 0, 0, 50, 50);

		if (*n == MALA) {
			renderTexture(image[2], renderer, 150, 50, 300, 80);
		}
		else if (*n == SREDNJA) {
			renderTexture(image[3], renderer, 150, 50, 300, 80);
		}
		else if (*n == VELIKA) {
			renderTexture(image[4], renderer, 150, 50, 300, 80);
		}

		if (*brzina == SPORO) {
			renderTexture(image[5], renderer, 150, 150, 300, 80);
		}
		else if (*brzina == SREDNJE) {
			renderTexture(image[6], renderer, 150, 150, 300, 80);
		}
		else if (*brzina == BRZO) {
			renderTexture(image[7], renderer, 150, 150, 300, 80);
		}
		renderTexture(image[8], renderer, 10, 300, 50, 50);
		if (zm1->ziva == 1) {
			if (zm1->igrac == 0) {
				renderTexture(image[13], renderer, 110, 300, 100, 50);
			}
			else {
				renderTexture(image[14], renderer, 110, 300, 100, 50);
			}
		}
		else {
			renderTexture(image[12], renderer, 110, 300, 100, 50);
		}
		if (zm1->ziva) {
			if (zm1->igrac == 0) {
				if (zm1->tezina == 1) {
					renderTexture(image[17], renderer, 270, 300, 100, 50);
				}
				else {
					renderTexture(image[16], renderer, 270, 300, 100, 50);
				}
			}
		}
		renderTexture(image[18], renderer, 450, 300, 100, 50);
		
		renderTexture(image[9], renderer, 10, 375, 50, 50);
		if (zm2->ziva == 1) {
			if (zm2->igrac == 0) {
				renderTexture(image[13], renderer, 110, 375, 100, 50);
			}
			else {
				renderTexture(image[15], renderer, 110, 375, 100, 50);
			}
		}
		else {
			renderTexture(image[12], renderer, 110, 375, 100, 50);
		}
		if (zm2->ziva) {
			if (zm2->igrac == 0) {
				if (zm2->tezina == 1) {
					renderTexture(image[17], renderer, 270, 375, 100, 50);
				}
				else {
					renderTexture(image[16], renderer, 270, 375, 100, 50);
				}
			}
		}
		renderTexture(image[19], renderer, 450, 375, 100, 50);
		
		renderTexture(image[10], renderer, 10, 450, 50, 50);
		if (zm3->ziva == 1) {
			renderTexture(image[13], renderer, 110 , 450, 100, 50);
		}
		else {
			renderTexture(image[12], renderer, 110, 450, 100, 50);
		}
		if (zm3->ziva) {
			if (zm3->tezina == 1) {
				renderTexture(image[17], renderer, 270, 450, 100, 50);
			}
			else {
				renderTexture(image[16], renderer, 270, 450, 100, 50);
			}
		}
		renderTexture(image[20], renderer, 450, 450, 100, 50);
		
		renderTexture(image[11], renderer, 10, 525, 50, 50);
		if (zm4->ziva == 1) {
			renderTexture(image[13], renderer, 110, 525, 100, 50);
		}
		else {
			renderTexture(image[12], renderer, 110, 525, 100, 50);
		}
		if (zm4->ziva) {
			if (zm4->tezina == 1) {
				renderTexture(image[17], renderer, 270, 525, 100, 50);
			}
			else {
				renderTexture(image[16], renderer, 270, 525, 100, 50);
			}
		}
		renderTexture(image[21], renderer, 450, 525, 100, 50);
		
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
						zm1->tezina = 0;
					}
					else if (zm1->ziva && (zm1->igrac == 0)) {
						zm1->ziva = 0;
					}
						
				}
				else if (i > 270 && i < 370 && j > 300 && j < 350) {
					//p1
					if (zm1->ziva && !zm1->igrac) {
						if (zm1->tezina == 1)
							zm1->tezina = 0;
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
						zm2->tezina = 0;
					}
					else if (zm2->ziva && (zm2->igrac == 0)) {
						zm2->ziva = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 375 && j < 425) {
					//p2
					if (zm2->ziva && !zm2->igrac) {
						if (zm2->tezina == 1)
							zm2->tezina = 0;
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
						zm3->tezina = 0;
						zm3->igrac = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 450 && j < 500) {
					//p3
					if (zm3->ziva) {
						if (zm3->tezina == 1)
							zm3->tezina = 0;
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
						zm4->tezina = 0;
						zm4->igrac = 0;
					}
				}
				else if (i > 270 && i < 370 && j > 525 && j < 575) {
					//p4
					if (zm4->ziva) {
						if (zm4->tezina == 1)
							zm4->tezina = 0;
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
			renderTexture(image[22], renderer, 150, 50, 50, 80);
			break;
		case 2:
			renderTexture(image[23], renderer, 400, 50, 50, 80);
			break;
		case 3:
			renderTexture(image[22], renderer, 150, 150, 50, 80);
			break;
		case 4:
			renderTexture(image[23], renderer, 400, 150, 50, 80);
			break;
		default:
			break;
		}
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
	for (int i = 0; i < 24; i++)
		SDL_DestroyTexture(image[i]);
	VEL = 600 / (*n);
}

void update_screen(zmija zm, int mapa[][100],int n, SDL_Window *window, SDL_Renderer *renderer) {
	int i, j, i2, j2;
	SDL_Texture *image;
	if (zm.ziva) {
		i = zm.telo[zm.duzina - 2].i;
		j = zm.telo[zm.duzina - 2].j;
		i2 = zm.telo[zm.duzina - 1].i;
		j2 = zm.telo[zm.duzina - 1].j;
		switch (zm.redni) {
		case 1:
			image = loadTexture("img/z1_body.png", renderer);
			renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
			SDL_DestroyTexture(image);

			switch (zm.smer) {
			case DOLE:
				image = loadTexture("img/z1_down.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case GORE:
				image = loadTexture("img/z1_up.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case LEVO:
				image = loadTexture("img/z1_left.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case DESNO:
				image = loadTexture("img/z1_right.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			}
			break;
		case 2:
			image = loadTexture("img/z2_body.png", renderer);
			renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
			SDL_DestroyTexture(image);

			switch (zm.smer) {
			case DOLE:
				image = loadTexture("img/z2_down.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case GORE:
				image = loadTexture("img/z2_up.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case LEVO:
				image = loadTexture("img/z2_left.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case DESNO:
				image = loadTexture("img/z2_right.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			}
			break;
		case 3:
			image = loadTexture("img/z3_body.png", renderer);
			renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
			SDL_DestroyTexture(image);

			switch (zm.smer) {
			case DOLE:
				image = loadTexture("img/z3_down.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case GORE:
				image = loadTexture("img/z3_up.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case LEVO:
				image = loadTexture("img/z3_left.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case DESNO:
				image = loadTexture("img/z3_right.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			}
			break;
		case 4:
			image = loadTexture("img/z4_body.png", renderer);
			renderTexture(image, renderer, j * VEL, i * VEL, VEL, VEL);
			SDL_DestroyTexture(image);

			switch (zm.smer) {
			case DOLE:
				image = loadTexture("img/z4_down.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case GORE:
				image = loadTexture("img/z4_up.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case LEVO:
				image = loadTexture("img/z4_left.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			case DESNO:
				image = loadTexture("img/z4_right.png", renderer);
				renderTexture(image, renderer, j2 * VEL, i2 * VEL, VEL, VEL);
				SDL_DestroyTexture(image);
				break;
			}
			break;
		}
		SDL_RenderPresent(renderer);
	}
}

void prikaziHighscore(SDL_Window *window, SDL_Renderer *renderer) {

	SDL_Texture *odabir;
	int chosen = 0,i,j;
	SDL_Event e;
	char *datoteka;

	odabir = loadTexture("img/highscore/odabir.jpg", renderer);
	renderTexture(odabir, renderer, 0, 0, 600, 600);
	SDL_RenderPresent(renderer);
	datoteka = malloc(20);

	while (!chosen) {
		if (SDL_WaitEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				i = e.motion.x;
				j = e.motion.y;
				if (i >= 200 && i <= 400 && j >= 300 && j <= 350)
					chosen = MALA;
				else if (i >= 200 && i <= 400 && j >= 375 && j <= 425)
					chosen = SREDNJA;
				else if (i >= 200 && i <= 400 && j >= 450 && j <= 500)
					chosen = VELIKA;
				else if (j >= 0 && j <= 50 && i >= 0 && i <= 50) {
					SDL_DestroyTexture(odabir);
					SDL_RenderClear(renderer);
					return;
				}

			}
			else if (e.type == SDL_QUIT)
				izlaz(window, renderer);
		}
	}
	SDL_RenderClear(renderer);

	switch (chosen) {
	case MALA:
		datoteka="malahighscore.txt";
		break;
	case SREDNJA:
		datoteka = "srednjahighscore.txt";
		break;
	case VELIKA:
		datoteka="velikahighscore.txt";
		break;
	}
	
	SDL_DestroyTexture(odabir);
	ispisHighscore(window, renderer, datoteka);
}

void ispisHighscore(SDL_Window *window, SDL_Renderer *renderer,char *datoteka) {
	SDL_Texture *pozadina;
	int i, n, pomeraj, j;
	char rez[10],pom,*pomocni;
	osoba highscore[11];
	TTF_Font *Sans;
	SDL_Color Black = { 0,0,0 };
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
	SDL_Event e;
	FILE *fp;

	
	fp = fopen(datoteka, "r");
	pozadina = loadTexture("img/highscore/pozadina.jpg", renderer);
	renderTexture(pozadina, renderer, 0, 0, 600, 600);
	SDL_RenderPresent(renderer);

	pomocni = malloc(200);
	if (!pomocni) {
		printf("Neuspesna alokacija memorije\n");
		system("pause");
		exit(3);
	}

	n = 0;

	while (pom=fgetc(fp)!=EOF) { 
		highscore[n].ime = malloc(1000);
		if (!highscore[n].ime) {
			printf("Neuspela alokacija memorije\n");
			system("pause");
			exit(3);
		}
		fscanf(fp, "%s %s", highscore[n].ime,pomocni);
		pomocni = decrypt(pomocni);
		highscore[n].rezultat = atof(pomocni);
		highscore[n].ime = decrypt(highscore[n].ime);
		n++;
	}
	
	pomeraj = 0;
	for (i = 0; i< n; i++) {

		Sans = TTF_OpenFont("fonts/tajmer.ttf", 12); 
		surfaceMessage = TTF_RenderText_Solid(Sans, highscore[i].ime, Black); 
		Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); 

		Message_rect; 
		Message_rect.x = 120;  
		Message_rect.y = 160 + pomeraj; 
		Message_rect.w = 100; 
		Message_rect.h = 40; 

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
		
		snprintf(rez, 10, "%.2f", highscore[i].rezultat);

		surfaceMessage = TTF_RenderText_Solid(Sans, rez, Black); 

		Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); 

		Message_rect; 
		Message_rect.x = 385;  
		Message_rect.y = 160 + pomeraj; 
		Message_rect.w = 100; 
		Message_rect.h = 40; 

		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

		SDL_RenderPresent(renderer);
		pomeraj+=40;

		free(highscore[i].ime);
	}

	while (1) {
		SDL_WaitEvent(&e);
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			i = e.button.x; j = e.button.y;
			if (j >= 0 && j <= 50 && i >= 0 && i <= 50)
				break;
			else if (i >= 420 && i <= 570 && j >= 100 && j <= 140) {
				fp = fopen(datoteka, "w");
				break;
			}
		}
		else if (e.type == SDL_QUIT)
			izlaz(window, renderer);
	}

	free(pomocni);
	SDL_DestroyTexture(pozadina);
	fclose(fp);
}

void krajIgre(SDL_Window *window, SDL_Renderer *renderer,float vreme, int pobednik) {

	SDL_Texture *slika,*prva,*druga,*treca,*cetvrta;
	TTF_Font *Sans;
	SDL_Color Black = { 0,0,0};
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
	SDL_Event e;
	char rez[10];

	Sans = TTF_OpenFont("fonts/tajmer.ttf", 10);

	slika = loadTexture("img/krajigre.jpg", renderer);
	prva = loadTexture("img/z1_up.png", renderer);
	druga = loadTexture("img/z2_up.png", renderer);
	treca = loadTexture("img/z3_up.png", renderer);
	cetvrta = loadTexture("img/z4_up.png", renderer);
	renderTexture(slika, renderer, 100, 200, 400, 200);

	

	snprintf(rez, 10, "%.2f", vreme);

	surfaceMessage = TTF_RenderText_Solid(Sans, rez, Black);

	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	Message_rect;
	Message_rect.x = 410;
	Message_rect.y = 350;
	Message_rect.w = 80;
	Message_rect.h = 40;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	

	switch (pobednik) {

	case 1:
		renderTexture(prva, renderer, 420, 220, 50, 50);
		break;
	case 2:
		renderTexture(druga, renderer, 420, 220, 50, 50);
		break;
	case 3:
		renderTexture(treca, renderer, 420, 220, 50, 50);
		break;
	case 4:
		renderTexture(cetvrta, renderer, 420, 220, 50, 50);
		break;
	}

	SDL_RenderPresent(renderer);

	while (SDL_WaitEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN: return; break;
		}
	}
	

}