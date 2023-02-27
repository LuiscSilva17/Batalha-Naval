#pragma once
#include "Jogador.h"
#include <iostream>


class Bot : public Jogador
{
private:

	int Bax, Bay,Bao,Bao2;
	char Bayl;

public:

	Bot();
	~Bot();

	
	void Set_Bax(int b_ax) { Bax = b_ax; } //define a cordenada x
	void Set_Bay(int b_ay) { Bay = b_ay; } // define a y
	void Set_Bayl(int b_ayl) { Bayl = b_ayl; }
	void Set_Bao(int b_ao) { Bao = b_ao; }
	void Set_Bao2(int b_ao2) { Bao2 = b_ao2; }
	int Get_Bax() { return Bax; } // devolve x
	int Get_Bay() { return Bay; } // devolve y
	char Get_Bayl() { return Bayl; } // devolve y em valor letra
	int Get_Bao() { return Bao; }
	int Get_Bao2() { return Bao2; }
	void Gen_Cords();
};

