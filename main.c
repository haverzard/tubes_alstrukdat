/* Program Utama */

/* List Lib */
#include <stdio.h>

/* List ADT */
#include "boolean.h"
#include "mainmenu.h"
#include "matriks.h"
#include "matriksint.h"
#include "player.h"
#include "point.h"
#include "listlinier.h"

int main() {
	/* Kamus */
	int i;
	MATRIKS Peta;
	MATRIKS_INT Hubungan; 
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	
	/* Algoritma */
	STARTGAME();
	if (!EndGame) {
		printf("HEHE");
		INFOPETA(&Peta);
		INFOBANGUNAN(&TB);
		for (i = 1; i <= MaxElArr(TB); i++) {
			LOKASIBANGUNAN(&Peta, &TB, i);
		}
		HUBUNGANBANGUNAN(&Hubungan, pita);
		CREATEPLAYER(&p1, &p2);
		KeepSkill(&p1,'U');
		CREATEPLAYER(&p1, &p2);
		KeepSkill(&p1,'U');
		KeepSkill(&p2,'U');
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, Peta, &p1, &p2);
			}
			UpdateListBangunan(i, p1, p2);
			i = (i % 2 + 3) - 2;
			EndTurn = false;
		}
	}
}