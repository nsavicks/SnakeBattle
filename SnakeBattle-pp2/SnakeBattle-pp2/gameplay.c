#include "gameplay.h"


struct ko {
	int i, j;
};
struct zm {
	koord rep, glava, telo[100];
	int duzina;
	short smer, mrtva, igrac, tezina;
};


zmija nextMove(zmija z, int komanda,int mapa[][100]) {

	switch (komanda) {
	case GORE: 
		if (mapa[z.glava.i - 1][z.glava.j]) { printf("NE"); }
		break;
	case DESNO:
		break;
	case DOLE:
		break;
	case LEVO:
		break;
	
	}

}
