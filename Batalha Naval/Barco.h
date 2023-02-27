#pragma once
#include "PontoNaval.h"

#include <iostream>

using namespace std;

class Barco
{
protected:

	
	PontoNaval P1, P2;


public:

	int BX, BY;
	Barco();
	Barco(int b_x, int b_y);
	~Barco();

	void Draw_Subs(); // desenha o barco
	void Set_Bx(int b_x) { BX = b_x; } //define a cordenada x
	void Set_By(int b_y) { BY = b_y; } // define a y
	int Get_BX() { return BX; } // devolve x
	int Get_BY() { return BY; } // devolve y

};
