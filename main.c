/* Program Utama */

/* List Lib */
#include <stdio.h>

/* List ADT */
#include "boolean.h"
#include "mainmenu.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "listlinier.h"

int main() {
	/* Kamus */
	int i;
	MATRIKS Peta;
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	
	/* Algoritma */
	STARTGAME();
	if (!EndGame) {
		INFOPETA(&Peta);
		INFOBANGUNAN(&TB);
		for (i = 1; i <= MaxElArr(TB); i++) {
			LOKASIBANGUNAN(&Peta, &TB, i);
		}
		CREATEPLAYER(&p1, &p2);
		KeepSkill(&p1,'U');
		KeepSkill(&p2,'U');
		i = 1;
		while (!EndGame) {
			UpdateListBangunan(i, p1, p2);
			while (!EndTurn) {
				TURN(i, Peta, &p1, &p2);
			}
			i = (i % 2 + 3) - 2;
			EndTurn = false;
		}
	}
}