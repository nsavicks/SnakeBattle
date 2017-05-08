#include "gameplay.h"



zmija kill(zmija z, int mapa[][100]) {

	int i;
	for (i = 0; i < z.duzina; i++) {
		mapa[z.telo[i].i][z.telo[i].j] = 0;
	}
	z.glava.i = z.glava.j = z.rep.i = z.rep.j = -1;
	z.mrtva = 1;
	return z;
}

zmija nextMove(zmija z, int komanda,int mapa[][100],int n) {

	switch (komanda) {
	case GORE: 
		if ((z.glava.i == 0) || (mapa[z.glava.i - 1][z.glava.j])) {
			z = kill(z,mapa);
		}
		else {
			mapa[z.glava.i - 1][z.glava.j] = z.redni;
			z.glava.i--;
		}
		break;
	case DESNO:
		if ((z.glava.j == n-1) || (mapa[z.glava.i][z.glava.j+1])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i][z.glava.j+1] = z.redni;
			z.glava.j++;
		}
		break;
	case DOLE:
		if ((z.glava.i == n-1) || (mapa[z.glava.i + 1][z.glava.j])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i + 1][z.glava.j] = z.redni;
			z.glava.i++;
		}
		break;
	case LEVO:
		if ((z.glava.j == 0) || (mapa[z.glava.i][z.glava.j - 1])) {
			z = kill(z, mapa);
		}
		else {
			mapa[z.glava.i][z.glava.j - 1] = z.redni;
			z.glava.j--;
		}
		break;

	default: break;
	}

	return z;
}
