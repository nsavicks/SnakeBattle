#pragma once
#ifndef gameplay
#define gameplay

#include <stdio.h>
#include <stdlib.h>
#include "grafika.h"

typedef struct{
	int i, j;
}koord;

typedef struct{
	koord rep,glava,telo[100];
	int duzina;
	short smer, mrtva, igrac,tezina;
}zmija;



#endif 