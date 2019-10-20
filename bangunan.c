/* ADT Bangunan */
/*  */

#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"

boolean isJenisBangunanValid(JenisBangunan X) {
	return (X == 'C' || X == 'T' || X == 'F' || X == 'V');
}

boolean isEQBangunan(Bangunan X1, Bangunan X2) {
	return Jenis(X1) == Jenis(X2) && Kepemilikan(X1) == Kepemilikan(X2) && JumlahPasukan(X1) == JumlahPasukan(X2) && Level(X1) == Level(X2) && A(X1) == A(X2) && M(X1) == M(X2) && P(X1) == P(X2) && U(X1) == U(X2);
}

void InitUndef(Bangunan *X) {
	Jenis(*X) = JenisUndef;
	Kepemilikan(*X) = ValIntUndef;
	JumlahPasukan(*X) = ValIntUndef;
	Level(*X) = ValIntUndef;
	A(*X) = ValIntUndef;
	M(*X) = ValIntUndef;
	P(*X) = false;
}

void InitCastle(Bangunan *X) {
	Jenis(*X) = 'C';
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 40;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 40;
	P(*X) = false;
}

void InitTower(Bangunan *X) {
	Jenis(*X) = 'T';
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 30;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = true;
}

void InitFort(Bangunan *X) {
	Jenis(*X) = 'F';
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 80;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 20;
	P(*X) = false;
}

void InitVillage(Bangunan *X) {
	Jenis(*X) = 'V';
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 20;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = false;
}

void InitBangunan(Bangunan *X, char jenisBangunan) {
	if (jenisBangunan == 'C') {
		InitCastle(X);
	} else if (jenisBangunan == 'T') {
		InitTower(X);
	} else if (jenisBangunan == 'F') {
		InitFort(X);
	} else if (jenisBangunan == 'V') {
		InitVillage(X);
	} else {
		InitUndef(X);
	}
}

void UpdateBangunan(Bangunan *X) {
	if (JumlahPasukan(*X) < M(*X)) {
		JumlahPasukan(*X) += A(*X);
	}
}

void SerangBangunan(Bangunan *X, int N) {
	if (P(*X)) {
		JumlahPasukan(*X) -= (3*N)/4;
	} else {
		JumlahPasukan(*X) -= N;
	}
}

void LevelUpBangunan(Bangunan *X) {
	JumlahPasukan(*X) -= M(*X)/2;
}