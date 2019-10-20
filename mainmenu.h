/* ADT Menu Utama */
/* Mengatur segala output dan input user dan memprosesnya */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "boolean.h"
#include "mesindata.h"
#include "matriks.h"

extern int choice;
extern boolean EndGame;
extern boolean EndTurn;

void STARTGAME();
/* 	I.S. Menampilkan menu awal dan menerima masukan user 
	F.S. Choice terisi dan game akan mulai di-load jika choice sesuai.
		 Jika choice tidak sesuai, balik lagi ke menu utama.
*/
void LOADGAME();
/*	I.S.
	F.S.
*/

void TURN(int NoPemain, MATRIKS Peta);

#endif