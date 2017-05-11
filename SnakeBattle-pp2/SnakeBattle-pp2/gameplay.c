#include "gameplay.h"
#include "grafika.h"
#include <stdlib.h>
#include <time.h>

zmija kill(zmija z, int mapa[][100]) {
	int i;
	for (i = 0; i < z.duzina; i++) {
		mapa[z.telo[i].i][z.telo[i].j] = 0;
	}
	z.glava.i = z.glava.j = z.rep.i = z.rep.j = -1;
	z.ziva = 0;
	return z;
}

zmija nextMove(zmija z, int mapa[][100], int n) {

	int komanda = z.smer;

	switch (komanda) {
	case GORE:
		if ((z.glava.i == 0) || (mapa[z.glava.i - 1][z.glava.j])) {
			z = kill(z, mapa);
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
	return z;
}

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva, i, j;
	SDL_Event e;

	SDL_Texture *image;

	image = loadTexture("img/gp_background.png", renderer);
	renderTexture(image, renderer, 0, 0, 600, 600);
	SDL_DestroyTexture(image);

	ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
	
	image = loadTexture("img/z1_body.png", renderer);
	renderTexture(image, renderer, 40, 40, 30, 30);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	image = loadTexture("img/z2_body.png", renderer);
	renderTexture(image, renderer, 40, 40, 30, 30);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	image = loadTexture("img/z2_up.png", renderer);
	renderTexture(image, renderer, 40, 40, 30, 30);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);

	SDL_RenderClear(renderer);

	while (zivih > 1) {
		
		ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		SDL_RenderClear(renderer);
		SDL_Delay(brzina);

		while (SDL_PollEvent(&e))
			switch (e.type) {
			case SDL_KEYDOWN:
				printf("DETECTED\n");
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					if (zm1.smer != DOLE)
						zm1.smer = GORE;
					break;
				case SDLK_DOWN:
					if (zm1.smer != GORE)
						zm1.smer = DOLE;
					break;
				case SDLK_LEFT:
					if (zm1.smer != DESNO)
						zm1.smer = LEVO;
					break;
				case SDLK_RIGHT:
					if (zm1.smer != LEVO)
						zm1.smer = DESNO;
					break;
				case SDLK_w:
					if (zm2.smer != DOLE)
						zm2.smer = GORE;
					break;
				case SDLK_s:
					if (zm2.smer != GORE)
						zm2.smer = DOLE;
					break;
				case SDLK_a:
					if (zm2.smer != DESNO)
						zm2.smer = LEVO;
					break;
				case SDLK_d:
					if (zm2.smer != LEVO)
						zm2.smer = DESNO;
					break;
				default:
					break;
				}
			} // END FIRST SWITCH
		if (zm1.ziva) zm1 = nextMove(zm1, mapa, n);
		if (zm2.ziva) zm2 = nextMove(zm2, mapa, n);
		if (zm3.ziva) zm3 = nextMove(zm3, mapa, n);
		if (zm4.ziva) zm4 = nextMove(zm4, mapa, n);
		zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva;
	}
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

	}
	else if (igraca == 4) {

	}
	else {


	}

	
}