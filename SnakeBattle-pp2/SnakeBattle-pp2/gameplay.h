#pragma once
#ifndef gameplay
#define gameplay

#define GORE 0
#define DESNO 1
#define DOLE 2
#define LEVO 3
#include <stdio.h>
#include <stdlib.h>
#include "grafika.h"

typedef struct ko {
	int i, j;
}koord;
typedef struct zm {
	koord rep, glava, telo[100];
	int duzina;
	short smer, mrtva, igrac, tezina, redni;
}zmija;






#endif 