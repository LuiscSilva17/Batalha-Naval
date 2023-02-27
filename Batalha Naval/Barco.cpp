#include "Barco.h"
#include "Jogo.h"
#include "PontoNaval.h"

#include <iostream>

using namespace std;

Barco::Barco() {

	BX = 0;
	BY = 0;
}

Barco::Barco(int b_x, int b_y)
{
	Set_Bx(b_x);
	Set_By(b_y);
}

Barco::~Barco() {

}

void Barco::Draw_Subs() // verifica a cordenada e guarda as coordenadas
{
	int a_x = 0, a_y = 0;

	P1.Ask2Set();
	a_x = P1.Get_X();
	a_y = P1.Get_Y_N();
	Set_Bx(a_x);
	Set_By(a_y);
}
