#pragma once
#include "PontoNaval.h"
#include "Jogador.h"

class Tabuleiro
{
private:
	bool show = false, eshow = false;
	int ax;
	int Bx;
	int By;
	char M[10][10];
	Jogador J;

public:

	Tabuleiro();
	Tabuleiro(int tdx, int tdy);
	~Tabuleiro();

	void Set_Bx(int tdx) { Bx = tdx; }
	void Set_By(int tdy) { By = tdy; }
	int Get_Bx() { return Bx; } // devolve x
	int Get_By() { return By; } // devolve y
	void Draw_Tabuleiro1(); // desenha o tabuleiro
	void Draw_Tabuleiro2(); // desenha o tabuleiro

	void Reset_Tabuleiro(); // coloca os tabuleiros vazios
	
	void Set_Square(int lin, int col, char ax) { M[lin][col] = ax; }
	char Get_Square(int lin, int col) { return M[lin][col]; }



};
