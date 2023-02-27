#include "PontoNaval.h"
#include <iostream>
using namespace std;

PontoNaval::PontoNaval()
{
	x=1;
	y='A';
}

PontoNaval::PontoNaval(int t_x, char t_y)
{
	Set_X(t_x);
	Set_Y(t_y);
}

PontoNaval::PontoNaval(int t_x, int t_y)
{
	Set_X(t_x);
	Set_Y(t_y);
}

PontoNaval::~PontoNaval()
{
}

bool PontoNaval::Set_X(int t_x) // verifica se a cordenada x é permitida no tabuleiro
{
	if (t_x >= 1 && t_x <= 10) {
		x = t_x;
		return true;
	}
	return false;
}


bool PontoNaval::Set_Y(char t_y) // verifica se a cordenada y é permitida no tabuleiro
{
	if (t_y >= 'A' && t_y <= 'J') {
		y = t_y;
		return true;
	}
	else if (t_y >= 'a' && t_y <= 'j'){
		y = (t_y-32);
		return true;
}
	return false;
}


int PontoNaval::Get_Int_Y() // devolve y
{
	int ax;
	ax = int(y) - 16;
	return ax;

}

int PontoNaval::Get_Y_N() // devolve y numerico
{
	int b, bh;
	for (b = 1; b < 11; b++) {

		if ( y == char(64 + b)) {
			bh = b;
			return bh;
		}
	}
}

void PontoNaval::Ask2Set(void) // pede as cordenadas e verifica se é permitido no tabuleiro
{
	int ax_x = 0;
	char ax_y = 'A';
	bool bad = false;

		do {
			cout << "Insira as coordenadas: ";
			cin >> ax_y >> ax_x;
			bad = cin.fail();
			if (bad) {
				cout << "Valor da Coordenada errado" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10, '\n');
			}
			else if (!Set_X(ax_x) || !Set_Y(ax_y))
			{
				cout << "Valor da Coordenada errado" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10, '\n');
				bad = true;
			} 
		}while (bad);
}

void PontoNaval::Show(void) // mostra a coordenada
{
	cout << '(' << Get_X() << ',' << Get_Y() << ')' << endl;
}
