#include "gameplay.h"
#include "grafika.h"



zmija kill(zmija z, int mapa[][100]) {

	int i;
	
	for (i = 0; i < z.duzina; i++) {
		mapa[z.telo[i].i][z.telo[i].j] = 0;
	}
	z.glava.i = z.glava.j = z.rep.i = z.rep.j = -1;
	z.ziva = 0;
	return z;
}

zmija nextMove(zmija z,int mapa[][100],int n) {

	int komanda = z.smer;

	switch (komanda) {
	case GORE: 
		if ((z.glava.i == 0) || (mapa[z.glava.i - 1][z.glava.j])) {
			z = kill(z,mapa);
		}
		else {
			mapa[z.glava.i - 1][z.glava.j] = z.redni;
			z.duzina++;
			z.telo[z.duzina - 1] = z.glava;
			z.glava.i--;
		}
		break;
	case DESNO:
		if ((z.glava.j == n-1) || (mapa[z.glava.i][z.glava.j+1])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i][z.glava.j+1] = z.redni;
			z.duzina++;
			z.telo[z.duzina - 1] = z.glava;
			z.glava.j++;
		}
		break;
	case DOLE:
		if ((z.glava.i == n-1) || (mapa[z.glava.i + 1][z.glava.j])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i + 1][z.glava.j] = z.redni;
			z.duzina++;
			z.telo[z.duzina - 1] = z.glava;
			z.glava.i++;
		}
		break;
	case LEVO:
		if ((z.glava.j == 0) || (mapa[z.glava.i][z.glava.j - 1])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i][z.glava.j - 1] = z.redni;
			z.duzina++;
			z.telo[z.duzina - 1] = z.glava;
			z.glava.j--;
		}
		break;

	default: break;
	}

	return z;
}
void pokreniSve(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4,int mapa[][100],int n) {

	if (zm1->ziva) *zm1 = nextMove(*zm1, mapa, n);
	if (zm2->ziva) *zm2 = nextMove(*zm2, mapa, n);
	if (zm3->ziva) *zm3 = nextMove(*zm3, mapa, n);
	if (zm4->ziva) *zm4 = nextMove(*zm4, mapa, n);
	
}

void play(zmija zm1, zmija zm2, zmija zm3, zmija zm4,int mapa[][100],int n,int brzina, SDL_Window *window, SDL_Renderer *renderer) {
	
	
	int zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva;
	SDL_Event e;

		while (zivih>0) {
			SDL_Delay(brzina);
			printf("%d\n", zm1.smer);
			while (SDL_PollEvent(&e))
				switch (e.type) {
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym) {
					case SDLK_UP:
						zm1.smer = GORE;
						break;
					case SDLK_DOWN:
						zm1.smer = DOLE;
						break;
					case SDLK_LEFT:
						zm1.smer = LEVO;
						break;
					case SDLK_RIGHT:
						zm1.smer = DESNO;
						break;
					case SDLK_w:
						zm2.smer = GORE;
						break;
					case SDLK_s:
						zm2.smer = DOLE;
						break;
					case SDLK_a:
						zm2.smer = LEVO;
						break;
					case SDLK_d:
						zm2.smer = DESNO;
						break;
					default:

						break;
					}
					break;
				} // END FIRST SWITCH

			if (zm1.ziva) zm1 = nextMove(zm1, mapa, n);
			if (zm2.ziva) zm2 = nextMove(zm2, mapa, n);
			if (zm3.ziva) zm3 = nextMove(zm3, mapa, n);
			if (zm4.ziva) zm4 = nextMove(zm4, mapa, n);
			
			ispis(window, renderer, zm1, zm2, zm3, zm4, mapa, n);
		}

}


