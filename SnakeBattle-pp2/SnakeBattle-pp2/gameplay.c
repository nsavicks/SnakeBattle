#include "gameplay.h"
#include "grafika.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

zmija kill(zmija z, int mapa[][100]) {
	int i;
	for (i = 0; i < z.duzina; i++) {
		mapa[z.telo[i].i][z.telo[i].j] = 0;
	}
	z.glava.i = z.glava.j = z.rep.i = z.rep.j = -1;
	z.ziva = 0;
	return z;
}

zmija nextMove(zmija z, int mapa[][100], int n, int *killed, SDL_Window *window, SDL_Renderer *renderer) {

	int komanda = z.smer;
	switch (komanda) {
	case GORE:
		if ((z.glava.i == 0) || (mapa[z.glava.i - 1][z.glava.j])) {
			z = kill(z, mapa);
			*killed = 1;
		}
		else {
			mapa[z.glava.i - 1][z.glava.j] = z.redni;
			z.duzina++;
			z.glava.i--;
			z.telo[z.duzina - 1] = z.glava;
		}
		break;
	case DESNO:
		if ((z.glava.j == n - 1) || (mapa[z.glava.i][z.glava.j + 1])) {
			z = kill(z, mapa);
			*killed = 1;
		}
		else {
			mapa[z.glava.i][z.glava.j + 1] = z.redni;
			z.duzina++;

			z.glava.j++;
			z.telo[z.duzina - 1] = z.glava;
		}
		break;
	case DOLE:
		if ((z.glava.i == n - 1) || (mapa[z.glava.i + 1][z.glava.j])) {
			z = kill(z, mapa);
			*killed = 1;
		}
		else {
			mapa[z.glava.i + 1][z.glava.j] = z.redni;
			z.duzina++;
			z.glava.i++;
			z.telo[z.duzina - 1] = z.glava;
		}
		break;
	case LEVO:
		if ((z.glava.j == 0) || (mapa[z.glava.i][z.glava.j - 1])) {
			z = kill(z, mapa);
			*killed = 1;
		}
		else {
			mapa[z.glava.i][z.glava.j - 1] = z.redni;
			z.duzina++;
			z.glava.j--;
			z.telo[z.duzina - 1] = z.glava;
		}
		break;
	default: break;
	}
	if (!(*killed))
		update_screen(z, mapa, n, window, renderer);
	return z;
}

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva, i, j, killed = 0, first = 1, x = 0, second = 1;
	SDL_Event e;
	SDL_Texture *image;
	clock_t end, before, startFrame, endFrame;

	image = loadTexture("img/gp_background.png", renderer);
	renderTexture(image, renderer, 0, 0, 600, 600);
	SDL_DestroyTexture(image);

	ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);

	image = loadTexture("img/tri.png", renderer);
	renderTexture(image, renderer, 100, 100, 400, 400);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	image = loadTexture("img/gp_background.png", renderer);
	renderTexture(image, renderer, 0, 0, 600, 600);
	SDL_DestroyTexture(image);

	ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);

	image = loadTexture("img/dva.png", renderer);
	renderTexture(image, renderer, 100, 100, 400, 400);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	image = loadTexture("img/gp_background.png", renderer);
	renderTexture(image, renderer, 0, 0, 600, 600);
	SDL_DestroyTexture(image);

	ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);


	image = loadTexture("img/jedan.png", renderer);
	renderTexture(image, renderer, 100, 100, 400, 400);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
	before = clock();
	while (zivih > 1) {
		first = second = 1;
		SDL_Delay(brzina);
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					if (zm1.smer != DOLE && first)
						zm1.smer = GORE;
					first = 0;
					break;
				case SDLK_DOWN:
					if (zm1.smer != GORE && first)
						zm1.smer = DOLE;
					first = 0;
					break;
				case SDLK_LEFT:
					if (zm1.smer != DESNO && first)
						zm1.smer = LEVO;
					first = 0;
					break;
				case SDLK_RIGHT:
					if (zm1.smer != LEVO)
						zm1.smer = DESNO;
					first = 0;
					break;
				case SDLK_w:
					if (zm2.smer != DOLE && second)
						zm2.smer = GORE;
					second = 0;
					break;
				case SDLK_s:
					if (zm2.smer != GORE && second)
						zm2.smer = DOLE;
					second = 0;
					break;
				case SDLK_a:
					if (zm2.smer != DESNO && second)
						zm2.smer = LEVO;
					second = 0;
					break;
				case SDLK_d:
					if (zm2.smer != LEVO && second)
						zm2.smer = DESNO;
					second = 0;
					break;
				default:
					break;
				}
			} // END FIRST SWITCH
			SDL_Delay(10);
		}
		if (zm1.ziva) {
			killed = 0;
			zm1 = nextMove(zm1, mapa, n, &killed, window, renderer);
			if (killed)
				ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		}
		if (zm2.ziva) {
			killed = 0;
			zm2 = nextMove(zm2, mapa, n, &killed, window, renderer);
			if (killed)
				ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		}
		if (zm3.ziva) {
			killed = 0;
			zm3 = nextMove(zm3, mapa, n, &killed, window, renderer);
			if (killed)
				ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		}
		if (zm4.ziva) {
			killed = 0;
			zm4 = nextMove(zm4, mapa, n, &killed, window, renderer);
			if (killed)
				ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		}
		zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva;
		SDL_RenderPresent(renderer);
	}
	end = clock() - before;
	zm1 = kill(zm1, mapa);
	zm2 = kill(zm2, mapa);
	zm3 = kill(zm3, mapa);
	zm4 = kill(zm4, mapa);
	SDL_RenderClear(renderer);
}

void setdefault(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int *n, int *brzina) {
	zm1->ziva = zm2->ziva = 1;
	zm3->ziva = zm4->ziva = 0;
	zm1->igrac = 1; zm2->igrac = 0;
	zm2->tezina = 1;
	*n = MALA;
	*brzina = SPORO;
	zm1->redni = 1;
	zm2->redni = 2;
	zm3->redni = 3;
	zm4->redni = 4;
}

void podesimapu(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n) {
	srand(time(NULL));
	int igraca = zm1->ziva + zm2->ziva + zm3->ziva + zm4->ziva;
	int rednibroj = 1;
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++, mapa[i][j] = 0);
	

	if (igraca == 2) {
		if (zm1->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm1->smer = DOLE;
			}
			else {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm1->smer = GORE;
			}
			zm1->duzina = 1;
			zm1->glava.i = i;
			zm1->glava.j = j;
			zm1->telo[0].i = i;
			zm1->telo[0].j = j;
			mapa[i][j] = zm1->redni;
			rednibroj++;
		} // KRAJ ZM1
		if (zm2->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm2->smer = DOLE;
			}
			else {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm2->smer = GORE;
			}
			zm2->duzina = 1;
			zm2->glava.i = i;
			zm2->glava.j = j;
			zm2->telo[0].i = i;
			zm2->telo[0].j = j;
			mapa[i][j] = zm2->redni;
			rednibroj++;
		} // KRAJ ZM2
		if (zm3->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm3->smer = DOLE;
			}
			else {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm3->smer = GORE;
			}
			zm3->duzina = 1;
			zm3->glava.i = i;
			zm3->glava.j = j;
			zm3->telo[0].i = i;
			zm3->telo[0].j = j;
			mapa[i][j] = zm3->redni;
			rednibroj++;
		} // KRAJ ZM3
		if (zm4->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm4->smer = DOLE;
			}
			else {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm4->smer = GORE;
			}
			zm4->duzina = 1;
			zm4->glava.i = i;
			zm4->glava.j = j;
			zm4->telo[0].i = i;
			zm4->telo[0].j = j;
			mapa[i][j] = zm4->redni;
			rednibroj++;
		} // KRAJ ZM4
	} // KRAJ 2 IGRACA
	else if (igraca == 3) {
		if (zm1->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm1->smer = DOLE;
			}
			else if (rednibroj==2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2); 
				zm1->smer = LEVO;
			}
			else {
				i = 2* n / 3 + rand() % (n / 3);
				j = n / 4 + rand() % (n / 2);
				zm1->smer = DESNO;
			}

			zm1->duzina = 1;
			zm1->glava.i = i;
			zm1->glava.j = j;
			zm1->telo[0].i = i;
			zm1->telo[0].j = j;
			mapa[i][j] = zm1->redni;
			rednibroj++;

		} // KRAJ ZM1
		if (zm2->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm2->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm2->smer = LEVO;
			}
			else {
				i = 2 * n / 3 + rand() % (n / 3);
				j = n / 4 + rand() % (n / 2);
				zm2->smer = DESNO;
			}

			zm2->duzina = 1;
			zm2->glava.i = i;
			zm2->glava.j = j;
			zm2->telo[0].i = i;
			zm2->telo[0].j = j;
			mapa[i][j] = zm2->redni;
			rednibroj++;

		} // KRAJ ZM2
		if (zm3->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm3->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm3->smer = LEVO;
			}
			else {
				i = 2 * n / 3 + rand() % (n / 3);
				j = n / 4 + rand() % (n / 2);
				zm3->smer = DESNO;
			}

			zm3->duzina = 1;
			zm3->glava.i = i;
			zm3->glava.j = j;
			zm3->telo[0].i = i;
			zm3->telo[0].j = j;
			mapa[i][j] = zm3->redni;
			rednibroj++;

		} // KRAJ ZM3
		if (zm4->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm4->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm4->smer = LEVO;
			}
			else {
				i = 2 * n / 3 + rand() % (n / 3);
				j = n / 4 + rand() % (n / 2);
				zm4->smer = DESNO;
			}

			zm4->duzina = 1;
			zm4->glava.i = i;
			zm4->glava.j = j;
			zm4->telo[0].i = i;
			zm4->telo[0].j = j;
			mapa[i][j] = zm4->redni;
			rednibroj++;

		} // KRAJ ZM4
	} // KRAJ IGRACA 3
	else if (igraca == 4) {
		if (zm1->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm1->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm1->smer = LEVO;
			}
			else if (rednibroj == 3) {
				i = n / 2 + rand() % (n / 2);
				j = rand() % (n / 2);
				zm1->smer = DESNO;
			}
			else if (rednibroj == 4) {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm1->smer = GORE;
			}
			zm1->duzina = 1;
			zm1->glava.i = i;
			zm1->glava.j = j;
			zm1->telo[0].i = i;
			zm1->telo[0].j = j;
			mapa[i][j] = zm1->redni;
			rednibroj++;
		} // KRAJ ZM1
		if (zm2->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm2->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm2->smer = LEVO;
			}
			else if (rednibroj == 3) {
				i = n / 2 + rand() % (n / 2);
				j = rand() % (n / 2);
				zm2->smer = DESNO;
			}
			else if (rednibroj == 4) {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm2->smer = GORE;
			}
			zm2->duzina = 1;
			zm2->glava.i = i;
			zm2->glava.j = j;
			zm2->telo[0].i = i;
			zm2->telo[0].j = j;
			mapa[i][j] = zm2->redni;
			rednibroj++;
		} // KRAJ ZM2
		if (zm3->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm3->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm3->smer = LEVO;
			}
			else if (rednibroj == 3) {
				i = n / 2 + rand() % (n / 2);
				j = rand() % (n / 2);
				zm3->smer = DESNO;
			}
			else if (rednibroj == 4) {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm3->smer = GORE;
			}
			zm3->duzina = 1;
			zm3->glava.i = i;
			zm3->glava.j = j;
			zm3->telo[0].i = i;
			zm3->telo[0].j = j;
			mapa[i][j] = zm3->redni;
			rednibroj++;
		} // KRAJ ZM3
		if (zm4->ziva) {
			if (rednibroj == 1) {
				i = rand() % (n / 2);
				j = rand() % (n / 2);
				zm4->smer = DOLE;
			}
			else if (rednibroj == 2) {
				i = rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm4->smer = LEVO;
			}
			else if (rednibroj == 3) {
				i = n / 2 + rand() % (n / 2);
				j = rand() % (n / 2);
				zm4->smer = DESNO;
			}
			else if (rednibroj == 4) {
				i = n / 2 + rand() % (n / 2);
				j = n / 2 + rand() % (n / 2);
				zm4->smer = GORE;
			}
			zm4->duzina = 1;
			zm4->glava.i = i;
			zm4->glava.j = j;
			zm4->telo[0].i = i;
			zm4->telo[0].j = j;
			mapa[i][j] = zm4->redni;
			rednibroj++;
		} // KRAJ ZM4
	} // KRAJ 4 ZMIJE
	else {


	}

	
}