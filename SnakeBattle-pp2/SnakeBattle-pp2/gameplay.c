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

zmija nextMove(zmija z, int mapa[][100], int n, SDL_Window *window, SDL_Renderer *renderer, int *killed) {

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
	return z;
}

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window *window, SDL_Renderer *renderer) {
	int zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva, i, j, p = 1, killed,sekunde,decimale;
	SDL_Event e;
	SDL_Texture *image;
	clock_t end, before;

	ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
	SDL_Delay(3000);
	before = clock();
	while (zivih >= 1 && p) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN:
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
				case SDLK_BACKSPACE:
					p = 0;
					break;
				case SDLK_p:
					while (1) {
						SDL_WaitEvent(&e);
						if (e.type == SDL_KEYDOWN)
							if (e.key.keysym.sym == SDLK_p)
								break;
					}
					break;
				default:
					break;
				}
			} // END FIRST SWITCH

		}
		if (zm1.ziva) {
			killed = 0;
			zm1 = nextMove(zm1, mapa, n, window, renderer, &killed);
			if (killed) {
				ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
			}
			else
				update_screen(zm1, mapa, n, window, renderer);
		}
		if (zm2.ziva) {
			killed = 0;
			zm2 = nextMove(zm2, mapa, n, window, renderer, &killed);	
			if (killed)
				ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
			else
				update_screen(zm2, mapa, n, window, renderer);
		}
		if (zm3.ziva) {
			killed = 0;
			zm3 = nextMove(zm3, mapa, n, window, renderer, &killed);
			if (killed)
				ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
			else
				update_screen(zm3, mapa, n, window, renderer);
		}
		if (zm4.ziva) {
			killed = 0;
			zm4 = nextMove(zm4, mapa, n, window, renderer, &killed);
			if (killed)
				ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
			else
				update_screen(zm4, mapa, n, window, renderer);
		}
		zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva;
		SDL_Delay(brzina);
	}
	end = clock() - before;
	sekunde = end / 1000;
	decimale = end % 1000;
	printf("%d-%d", sekunde, decimale);
	zm1 = kill(zm1, mapa);
	zm2 = kill(zm2, mapa);
	zm3 = kill(zm3, mapa);
	zm4 = kill(zm4, mapa);
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
	VEL = 600 / (*n);
}

void podesimapu(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n) {
	srand(time(NULL));
	int igraca = zm1->ziva + zm2->ziva + zm3->ziva + zm4->ziva;
	int rednibroj = 1;
	int i, j;

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			mapa[i][j] = 0;
	

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