#include "gameplay.h"
#include "grafika.h"



int q_empty(queue q) {  // Provera da li je red prazan
	if (q.front == q.rear)
		return 1;
	else
		return 0;
}

void q_insert(queue *q, koord a) { // Ubacivanje elementa u red
	q->x[q->rear++] = a;
}

koord q_delete(queue *q) { // Brisanje elementa iz reda
	return q->x[q->front++];
}

queue q_init() { // Inicijalizacija reda
	queue q;
	q.front = q.rear = 0;
	return q;
}

int bfs(int si, int sj, int n, int mapa[][100],int granica) { // BFS koji vraca broj dostiznih polja od neke date pozicije (si,sj)
	
	int visited[200][200] = { 0 }, resenje=0,i;
	queue Q;
	koord k,trenutni;
	Q = q_init();

	visited[si][sj] = 1;
	k.i = si;
	k.j = sj;
	q_insert(&Q, k);

	while (!q_empty(Q) && resenje<=granica) {
		trenutni = q_delete(&Q);
		
		
		
		if ((trenutni.i + 1 < n) && (!visited[trenutni.i + 1][trenutni.j]) && (!mapa[trenutni.i + 1][trenutni.j])) {
			k.i = trenutni.i + 1;
			k.j = trenutni.j; 
			visited[k.i][k.j] = 1;
			resenje++;
			q_insert(&Q, k); 
		}
		if ((trenutni.i-1>=0)&&(!visited[trenutni.i - 1][trenutni.j]) && (!mapa[trenutni.i - 1][trenutni.j])) { 
			k.i = trenutni.i - 1;
			k.j = trenutni.j; 
			visited[k.i][k.j] = 1; 
			resenje++;
			q_insert(&Q, k); 
		}
		if ((trenutni.j + 1<n) && (!visited[trenutni.i][trenutni.j + 1]) && (!mapa[trenutni.i][trenutni.j + 1])) {  
			k.i = trenutni.i; 
			k.j = trenutni.j + 1; 
			visited[k.i][k.j] = 1; 
			resenje++;
			q_insert(&Q, k); 
		}
		if ((trenutni.j - 1 >= 0) && (!visited[trenutni.i][trenutni.j - 1]) && (!mapa[trenutni.i][trenutni.j - 1])) {  
			k.i = trenutni.i; 
			k.j = trenutni.j - 1; 
			visited[k.i][k.j] = 1;  
			resenje++;
			q_insert(&Q, k); 
		}


	
	}
	

	return resenje;
}

void setdefault(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int *n, int *brzina, int *muzika) { // Pocetna inicijalizacija svih parametara igre
	zm1->ziva = zm2->ziva = 1;
	zm3->ziva = zm4->ziva = 0;
	zm1->igrac = 1; zm2->igrac = 0;
	zm2->tezina = 0;
	*n = MALA;
	*brzina = SPORO;
	*muzika = 1;
	zm1->redni = 1;
	zm2->redni = 2;
	zm3->redni = 3;
	zm4->redni = 4;
	VEL = 600 / (*n);
}

void podesimapu(zmija *zm1, zmija *zm2, zmija *zm3, zmija *zm4, int mapa[][100], int n) { // Vrsi rasporedjivanje pocetnih pozicija zmija na pocetku igre

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
	} // KRAJ 2 IGRACA  --- Prvog igraca smesta u gornji levi kvadrant a drugog u donji desni
	else if (igraca == 3) {
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
			else {
				i = 2 * n / 3 + rand() % (n / 3);
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
	} // KRAJ IGRACA 3 -- Prvog igraca smesta gore levo, drugog gore desno, a treceg dole po sredini
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
	} // KRAJ 4 ZMIJE  --- Svaka zmija u po jednom kvadrantu


}

zmija kill(zmija z, int mapa[][100]) { // Ubija zmiju, resetuje sve njene vrednosti i azurira mapu
	int i;

	for (i = 0; i < z.duzina; i++) {
		mapa[z.telo[i].i][z.telo[i].j] = 0;
	}
	z.glava.i = z.glava.j = z.rep.i = z.rep.j = -1;
	z.ziva = 0;
	return z;
}

zmija nextMove(zmija z, int mapa[][100], int n, SDL_Window *window, SDL_Renderer *renderer, int *killed) {

	// Proverava sta se desava sa zmijom u sledecem potezu, da li se ubija ili ne

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

int play(zmija zm1, zmija zm2, zmija zm3, zmija zm4, int mapa[][100], int n, int brzina, SDL_Window *window, SDL_Renderer *renderer, int muzika) {

	// Glavna funkcija koja pokrece igru
	int zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva, i, j, p = 1, killed, pobednik, pobednik_cpu, flag1, flag2, kraj;
	float vreme, pauzavreme = 0;
	SDL_Event e;
	SDL_Texture *image;
	Mix_Music *pesma = NULL;
	clock_t end, before, pauzabegin, pauzaend, pocetakIgre;

	if (zivih <= 1) return 1;

	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	pesma = Mix_LoadMUS("music/play.wav");

	

		ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4); // iscrtava mapu

		if (pregame(window, renderer)) {
			zm1 = kill(zm1, mapa);
			zm2 = kill(zm2, mapa);
			zm3 = kill(zm3, mapa);
			zm4 = kill(zm4, mapa);
			return 1;
		}

		if (muzika)
			Mix_PlayMusic(pesma, -1);

		ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);

		SDL_Delay(2000);

		before = clock();

		while (zivih > 1) {

			flag1 = 1;
			flag2 = 1;

			pocetakIgre = clock();

			while (SDL_PollEvent(&e)) {
				switch (e.type) {
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym) {
					case SDLK_UP:
						if (zm1.smer != DOLE && zm1.igrac && flag1)
							zm1.smer = GORE;
						flag1 = 0;
						break;
					case SDLK_DOWN:
						if (zm1.smer != GORE && zm1.igrac && flag1)
							zm1.smer = DOLE;
						flag1 = 0;
						break;
					case SDLK_LEFT:
						if (zm1.smer != DESNO && zm1.igrac && flag1)
							zm1.smer = LEVO;
						flag1 = 0;
						break;
					case SDLK_RIGHT:
						if (zm1.smer != LEVO && zm1.igrac && flag1)
							zm1.smer = DESNO;
						flag1 = 0;
						break;
					case SDLK_w:
						if (zm2.smer != DOLE && zm2.igrac && flag2)
							zm2.smer = GORE;
						flag2 = 0;
						break;
					case SDLK_s:
						if (zm2.smer != GORE && zm2.igrac && flag2)
							zm2.smer = DOLE;
						flag2 = 0;
						break;
					case SDLK_a:
						if (zm2.smer != DESNO && zm2.igrac && flag2)
							zm2.smer = LEVO;
						flag2 = 0;
						break;
					case SDLK_d:
						if (zm2.smer != LEVO && zm2.igrac && flag2)
							zm2.smer = DESNO;
						flag2 = 0;
						break;
					case SDLK_BACKSPACE:

						zm1 = kill(zm1, mapa);
						zm2 = kill(zm2, mapa);
						zm3 = kill(zm3, mapa);
						zm4 = kill(zm4, mapa);
						Mix_HaltMusic();

						return 1;
						break;
					case SDLK_p:
						pauzabegin = clock();
						while (1) {
							SDL_WaitEvent(&e);
							if (e.type == SDL_KEYDOWN)
								if (e.key.keysym.sym == SDLK_p) {
									pauzaend = clock() - pauzabegin;
									pauzavreme += pauzaend;
									break;
								}
								else if (e.type == SDL_QUIT)
									izlaz(window, renderer);
						}
						break;
					default:
						break;
					}
					break;
				case SDL_QUIT:
					izlaz(window, renderer);
				default:
					break;
				} // END FIRST SWITCH

			}

			if (zm1.ziva) {
				killed = 0;
				if (!zm1.igrac)
					if (zm1.tezina == 1) AiHard(&zm1, mapa, n); else AiEasy(&zm1, mapa, n);
				zm1 = nextMove(zm1, mapa, n, window, renderer, &killed);

				if (killed) {
					ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
				}
				else
					update_screen(zm1, mapa, n, window, renderer);
			}
			if (zm2.ziva) {
				killed = 0;
				if (!zm2.igrac)
					if (zm2.tezina == 1) AiHard(&zm2, mapa, n); else AiEasy(&zm2, mapa, n);
				zm2 = nextMove(zm2, mapa, n, window, renderer, &killed);

				if (killed)
					ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
				else
					update_screen(zm2, mapa, n, window, renderer);
			}
			if (zm3.ziva) {
				killed = 0;
				if (!zm3.igrac)
					if (zm3.tezina == 1) AiHard(&zm3, mapa, n); else AiEasy(&zm3, mapa, n);
				zm3 = nextMove(zm3, mapa, n, window, renderer, &killed);

				if (killed)
					ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
				else
					update_screen(zm3, mapa, n, window, renderer);
			}
			if (zm4.ziva) {
				killed = 0;
				if (!zm4.igrac)
					if (zm4.tezina == 1) AiHard(&zm4, mapa, n); else AiEasy(&zm4, mapa, n);
				zm4 = nextMove(zm4, mapa, n, window, renderer, &killed);

				if (killed)
					ispis(window, renderer, mapa, n, zm1, zm2, zm3, zm4);
				else
					update_screen(zm4, mapa, n, window, renderer);
			}
			zivih = zm1.ziva + zm2.ziva + zm3.ziva + zm4.ziva;
			if ((brzina - (clock() - pocetakIgre)) > 0) {

				SDL_Delay(brzina - (clock() - pocetakIgre));
			}
		}


		vreme = clock() - before;
		vreme -= pauzavreme;
		vreme = (float)vreme / 1000;
		pobednik_cpu = 0;
		if (p) {
			pobednik = zm1.ziva*zm1.redni*zm1.igrac + zm2.ziva*zm2.redni*zm2.igrac;
			switch (pobednik) {
			case 1:
				pobednik_cpu = zm1.igrac;
				break;
			case 2:
				pobednik_cpu = zm2.igrac;
				break;

			}
		}


		if (p && pobednik_cpu)
			checkHighscore(vreme, n, window, renderer, zm1.ziva*zm1.redni + zm2.ziva*zm2.redni + zm3.ziva*zm3.redni + zm4.ziva*zm4.redni);

		kraj = krajIgre(window, renderer, vreme, zm1.ziva*zm1.redni + zm2.ziva*zm2.redni + zm3.ziva*zm3.redni + zm4.ziva*zm4.redni);

		zm1 = kill(zm1, mapa);
		zm2 = kill(zm2, mapa);
		zm3 = kill(zm3, mapa);
		zm4 = kill(zm4, mapa);

		Mix_HaltMusic();

		return kraj;

}

char *crypt(char *str) {
	char *resenje = malloc(2000);
	int i, j,k=0;
	for (i = 0; i < strlen(str); i++) {
		for (j = 1; j <= str[i]-' '; j++) {
			resenje[k] = ';';
			k++;
		}
		resenje[k++] = ',';
	}
	resenje[k++] = '.';
	resenje[k] = '\0';
	return resenje;
}

char *decrypt(char *str) {

	char *resenje = malloc(200);
	char karakter;
	int i = 0 , j,k=0;
	while (str[i] != '.') {
		j = 0;
		while (str[i] != ',') { 
			j++;
			i++; 
		}
		i++;
		resenje[k++] = j+' ';
		if (str[i] == '.') break;
		
	}
	resenje[k] = '\0';
	return resenje;
}

int validateHighscore(int vel_mape) {

	char *s;
	FILE *fp=NULL;
	int i;

	if ((s = malloc(20000)) == NULL) { exit(0); }

	switch (vel_mape) {
	case MALA:
		fp = fopen("malahighscore.txt", "r");
		break;
	case SREDNJA:
		fp = fopen("srednjahighscore.txt", "r");
		break;
	case VELIKA:
		fp = fopen("velikahighscore.txt", "r");
		break;
	}

	if (!fp) exit(0);

	fgets(s, 20000, fp);

	if (s[0] == EOF) {
		free(s);
		fclose(fp);
		return 1;
	}
	if (s[0] != ' ' || s[strlen(s)-1]!='.') {
		free(s);
		fclose(fp);
		return 0;
	}

	for (i = 0; i < strlen(s); i++) {
		if (s[i] != '.' && s[i] != ';' && s[i] != ',' && s[i] != ' ') {
			free(s);
			fclose(fp);
			return 0;
		}
		else {
			if (s[i] == '.') {
				if (s[i - 1] != ',') {
					free(s);
					fclose(fp);
					return 0;
				}
				if (s[i + 1] != ' ' && (i != strlen(s) - 1)) { 
					free(s);
					fclose(fp);
					return 0;
				}
			}
		}
	}

	free(s);
	fclose(fp);
	return 1;

}

void checkHighscore(float vreme, int vel_mape, SDL_Window *window, SDL_Renderer *renderer,int pobednik) {

	int n, i, p, j, k;
	osoba highscore[11], igrac;
	char ime[50], pom, *pomocni, *ime_pom;
	FILE *fp = NULL;

	igrac.username = malloc(50);
	if (!igrac.username) {
		printf("Neuspesna alokacija memorije.\n");
		system("pause");
		exit(5);
	}



	pomocni = malloc(200);
	if (!pomocni) {
		printf("Neuspesna alokacija memorije.\n");
		system("pause");
		exit(5);
	}

	ime_pom = malloc(200);
	if (!ime_pom) {
		printf("Neuspela alokacija memorije\n");
		system("pause");
		exit(3);
	}

	
	if (!validateHighscore(vel_mape)) {

		switch (vel_mape) {
		case MALA:
			fp = fopen("malahighscore.txt", "w");
			break;
		case SREDNJA:
			fp = fopen("srednjahighscore.txt", "w");
			break;
		case VELIKA:
			fp = fopen("velikahighscore.txt", "w");
			break;
		}
		fclose(fp);

	}
	
	switch (vel_mape) {
	case MALA:
		fp = fopen("malahighscore.txt", "r");
		break;
	case SREDNJA:
		fp = fopen("srednjahighscore.txt", "r");
		break;
	case VELIKA:
		fp = fopen("velikahighscore.txt", "r");
		break;
	}
	if (!fp) {
		printf("Neuspesno otvaranje datoteke.\n");
		system("pause");
		exit(3);
	}

	n = 0;

	while (pom=fgetc(fp)!=EOF) {
		highscore[n].username = malloc(2000);
		fscanf(fp, "%s", highscore[n].username);
		fscanf(fp, "%s", pomocni);
		pomocni = decrypt(pomocni);
		highscore[n].rezultat = atof(pomocni);
		n++;
	}

	p = 0;
	for (i = 0; i < n; i++) {
		if (highscore[i].rezultat > vreme) {
			if (n < 10)
				n++;
			for (j = n - 1; j > i; j--)
				highscore[j] = highscore[j - 1];

			ime_pom = ucitaj(window, renderer,vreme,pobednik);
			strcpy(igrac.username, ime_pom);
			igrac.username = crypt(igrac.username);
			igrac.rezultat = vreme;
			highscore[i] = igrac;
			p = 1;
			break;
		}
	}

	
	if (!p && n < 10) {
		
		ime_pom = ucitaj(window, renderer,vreme,pobednik);
		strcpy(igrac.username, ime_pom);
		igrac.username = crypt(igrac.username);
		igrac.rezultat = vreme;
		highscore[n] = igrac;
		n++;
	}


	fclose(fp);

	switch (vel_mape) {
	case MALA:
		fp = fopen("malahighscore.txt", "w");
		break;
	case SREDNJA:
		fp = fopen("srednjahighscore.txt", "w");
		break;
	case VELIKA:
		fp = fopen("velikahighscore.txt", "w");
		break;
	}
	if (!fp) {
		printf("Neuspesno otvaranje datoteke.\n");
		system("pause");
		exit(3);
	}
	
	for (i = 0; i < n; i++) {
		snprintf(pomocni, 10, "%f", highscore[i].rezultat);
		pomocni = crypt(pomocni);
		fprintf(fp, " %s %s", highscore[i].username, pomocni);
		free(highscore[i].username);
	}

	
	free(pomocni);
	fclose(fp);
}

void AiEasy(zmija *z, int mapa[][100], int n) {
	int mogucnosti[4], max, novismer, i;
	mogucnosti[0] = mogucnosti[1] = mogucnosti[2] = mogucnosti[3] = -1;

	if ((z->glava.i + 1 < n) && (!mapa[z->glava.i + 1][z->glava.j]) && (z->smer != GORE)) {
		mogucnosti[DOLE] = bfs(z->glava.i + 1, z->glava.j, n, mapa, 10);
	}
	if ((z->glava.i - 1 >= 0) && (!mapa[z->glava.i - 1][z->glava.j]) && (z->smer != DOLE)) {
		mogucnosti[GORE] = bfs(z->glava.i - 1, z->glava.j, n, mapa, 10);
	}
	if ((z->glava.j + 1 < n) && (!mapa[z->glava.i][z->glava.j + 1]) && (z->smer != LEVO)) {
		mogucnosti[DESNO] = bfs(z->glava.i, z->glava.j + 1, n, mapa, 10);
	}
	if ((z->glava.j - 1 >= 0) && (!mapa[z->glava.i][z->glava.j - 1]) && (z->smer != DESNO)) {
		mogucnosti[LEVO] = bfs(z->glava.i, z->glava.j - 1, n, mapa, 10);
	}
	max = -1; novismer = z->smer;
	for (i = 0; i < 4; i++) {
		//printf("%d ", mogucnosti[i]);
		if (mogucnosti[i] > max) { 
			max = mogucnosti[i]; 
			novismer = i; 
		}
		else if (mogucnosti[i] == max && (rand() % 3)) {
			max = mogucnosti[i];
			novismer = i;
		}
	}
	//printf("\n");
		z->smer = novismer;
	
}

void AiHard(zmija *z, int mapa[][100], int n) {

	int mogucnosti[4], max, novismer, i, zid[4] = { 1, 1, 1, 1 }, x, y;
	mogucnosti[0] = mogucnosti[1] = mogucnosti[2] = mogucnosti[3] = -1;

	if ((z->glava.i + 1 < n) && (!mapa[z->glava.i + 1][z->glava.j]) && (z->smer != GORE)) {
		mogucnosti[DOLE] = bfs(z->glava.i + 1, z->glava.j, n, mapa, 500);
		x = z->glava.i + 2;
		y = z->glava.j;
		if (x != n && mapa[x][y] == 0)
			zid[DOLE] = 0;
	}
	if ((z->glava.i - 1 >= 0) && (!mapa[z->glava.i - 1][z->glava.j]) && (z->smer != DOLE)) {
		mogucnosti[GORE] = bfs(z->glava.i - 1, z->glava.j, n, mapa, 500);
		x = z->glava.i - 2;
		y = z->glava.j;
		if (x != -1 && mapa[x][y] == 0)
			zid[GORE] = 0;
	}
	if ((z->glava.j + 1 < n) && (!mapa[z->glava.i][z->glava.j + 1]) && (z->smer != LEVO)) {
		mogucnosti[DESNO] = bfs(z->glava.i, z->glava.j + 1, n, mapa, 500);
		x = z->glava.i;
		y = z->glava.j + 2;
		if (y != n && mapa[x][y] == 0)
			zid[DESNO] = 0;
	}
	if ((z->glava.j - 1 >= 0) && (!mapa[z->glava.i][z->glava.j - 1]) && (z->smer != DESNO)) {
		mogucnosti[LEVO] = bfs(z->glava.i, z->glava.j - 1, n, mapa, 500);
		x = z->glava.i;
		y = z->glava.j - 2;
		if (y != -1 && mapa[x][y] == 0)
			zid[LEVO] = 0;
	}
	max = -1; novismer = z->smer;
	for (i = 0; i < 4; i++) {
		if (mogucnosti[i] > max) {
			max = mogucnosti[i];
			novismer = i;
		}
		else if (mogucnosti[i] == max) {
			if (zid[i] == 0) {
				if (zid[novismer] != 0) {
					max = mogucnosti[i];
					novismer = i;
				}
				else if (rand() % 3 == 0) {
					max = mogucnosti[i];
					novismer = i;
				}
			}
		}
	}
	if (mogucnosti[z->smer] != max)
		z->smer = novismer;
	else {
		if (zid[z->smer])
			z->smer = novismer;
		else if (rand() % 2)
			z->smer = novismer;
	}
}