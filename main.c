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
#include "graph.h"
#include "stack.h"

int main() {
	/* Kamus */
	int i;
	MATRIKS Peta;
	MATRIKS_INT Hubungan;
	Player p1, p2;
	Stack Status;

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
		HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
		GenerateHubunganBangunan(&GHubungan, Hubungan);
		CREATEPLAYER(&p1, &p2);
		GetIUpgrade (&p1);
		GetIUpgrade (&p2);
		GetIReinforcement(i,&p1,&p2);
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, Peta, &p1, &p2);
			}
			UpdateListBangunan(i, p1, p2);
			//Tambahin shield Duration
			i = (i % 2 + 3) - 2;
			if (extraTurn > 0){
				i = (i % 2 + 3) - 2; 
			} else {
				extraTurn -=1;
			}

			EndTurn = false;
		}
	}
}