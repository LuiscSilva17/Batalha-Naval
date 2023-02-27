#include "Navio.h"

Navio::Navio()
{
}

Navio::~Navio()
{
}

void Navio::Draw_mc()
{
	int ax, ay, saux;
	char o;
	bool bad = false;
	do {
		Draw_Subs();
		ax = Get_BX();
		ay = Get_BY();
		cin >> o;
		bad = cin.fail();

		if (bad) {
			cout << "Valor da Coordenada errado" << endl;
			Sleep(1000);
			cin.clear();
			cin.ignore(10, '\n');
		}
		else if (o != 'w' && o != 'a' && o != 's' && o != 'd' && o != 'A' && o != 'W' && o != 'S' && o != 'D') {
			cout << "Valor da Coordenada errado" << endl;
			Sleep(1000);
			cin.clear();
			cin.ignore(10, '\n');
			bad = true;
		}
	} while (bad);

	Set_Bx(ax);
	Set_By(ay);

	if (o == 'w' | o == 'W') { saux = 1; }
	if (o == 'a' | o == 'A') { saux = 2; }
	if (o == 's' | o == 'S') { saux = 3; }
	if (o == 'd' | o == 'D') { saux = 4; }
	Set_Saux(saux);
}