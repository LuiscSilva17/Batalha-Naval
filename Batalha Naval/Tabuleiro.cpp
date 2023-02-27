#include "Tabuleiro.h"
#include <iostream>
#include <fstream>

using namespace std;

Tabuleiro::Tabuleiro()
{
	int l, c;
	Set_Bx(10); // define a dimensao do tabuleiro bx e by
	Set_By(10);

	for(c=0; c <= Get_Bx() ; c++)
		for (l = 0; l <= Get_By(); l++) {
			Set_Square(c,l,'.');
		}
}

Tabuleiro::Tabuleiro(int tdx, int tdy) // tdx dimensao 
{
	int l, c;
	PontoNaval P;
	Set_Bx(tdx);
	Set_By(tdy);

	for (c=0; c<= Get_Bx(); c++)
		for (l = 0; l <= Get_By(); l++) {	
			Set_Square(c,l,'.');
		}
}

Tabuleiro::~Tabuleiro()
{
}

void Tabuleiro::Draw_Tabuleiro1() // desenha o tabuleiro 
{

	show = J.Get_show();
	eshow = J.Get_show_end();

	cout << "	  A   B   C   D   E   F   G   H   I   J" << endl; // linha
	int i;
	//top
	cout << "	" << char(201);
	for (i = 0; i < 9; i++) {
		cout << char(205) << char(205) << char(205) << char(203);
	}
	cout << char(205) << char(205) << char(205) << char(187) << endl;
	//top
	int num, a;
	i = 0;
	a = 0;

	for (num = 0; num < 10; num++) {
		//mid
		a = 0;
		if (num < 9) {
			cout << "      " << char(49 + num) << " ";
		}
		else { cout << "     " << "10" << " "; }



		//
		if (show == true || eshow == true) {
			for (i = 0; i < 10; i++) {
				cout << char(186) << " " << Get_Square(num, i) << " ";;
			} // VERSAO de teste para confirmar as coordenadas
		}
		else {
			for (i = 0; i < 10; i++) {
				cout << char(186) << " ";
				if (Get_Square(num, i) == 'O') { cout << '.'; }
				else { cout << (Get_Square(num, i)); } // espaços
				cout << " ";
			}
			//


		}
			a++;
			cout << char(186) << endl;
			//mid


			//bot
			if (num < 9) {
				cout << "        " << char(204);
				for (i = 1; i < 10; i++) {
					cout << char(205) << char(205) << char(205) << char(206);
				}
				cout << char(205) << char(205) << char(205) << char(185) << endl;
			}
			else {
				cout << "        " << char(200);
				for (i = 0; i < 9; i++) {
					cout << char(205) << char(205) << char(205) << char(202);
				}
				cout << char(205) << char(205) << char(205) << char(188);
			}
			//bot
		
	}
}

void Tabuleiro::Draw_Tabuleiro2()
{
	show = J.Get_show();

	cout << " A   B   C   D   E   F   G   H   I   J" << endl; // linha
	int i;
	//top
	cout << "								" << char(201);
	for (i = 0; i < 9; i++) {
		cout << char(205) << char(205) << char(205) << char(203);
	}
	cout << char(205) << char(205) << char(205) << char(187) << endl;
	//top
	int num, a;
	i = 0;
	a = 0;

	for (num = 0; num < 10; num++) {
		//mid
		a = 0;
		if (num < 9) {
			cout << "							      " << char(49 + num) << " ";
		}
		else { cout << "							     " << "10" << " "; }
	

		//
		if (eshow == true) {
			for (i = 0; i < 10; i++) {
				cout << char(186) << " " << Get_Square(num, i) << " ";;
			} // VERSAO de teste para confirmar as coordenadas
		}
		else {
			for (i = 0; i < 10; i++) {
				cout << char(186) << " ";
				if (Get_Square(num, i) == 'O') { cout << '.'; }
				else { cout << (Get_Square(num, i)); } // espaços
				cout << " ";
			}
		}
		//
		a++;
		cout << char(186) << endl;
		//mid


	//bot
		if (num < 9) {
			cout << "								" << char(204);
			for (i = 0; i < 9; i++) {
				cout << char(205) << char(205) << char(205) << char(206);
			}
			cout << char(205) << char(205) << char(205) << char(185) << endl;
		}
		else {
			cout << "								" << char(200);
			for (i = 0; i < 9; i++) {
				cout << char(205) << char(205) << char(205) << char(202);
			}
			cout << char(205) << char(205) << char(205) << char(188);
		}
		//bot
	}
}


	void Tabuleiro::Reset_Tabuleiro() // define o tabueleiro para ser todo vazio 
	{
		int x, y;
		for (x = 0; x <= Get_Bx(); x++)
			for (y = 0; y <= Get_By(); y++) {
				Set_Square(x, y, '.');
			}
	}


