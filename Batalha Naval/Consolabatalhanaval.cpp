#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include "Jogo.h"
#include "Jogador.h"
#include "Tabuleiro.h"
#include "Help.h"

void Main_Menu();

using namespace std;

int main(void) {
	Help H1;
	H1.Intro();
	Main_Menu(); 
}

void Main_Menu() {

	Jogo Start;
	Jogador J1;
	Tabuleiro T;
	Help H;

	int x, aux = 0, cax = 0;
	bool bad = false;
	
	do {
		system("CLS"); // escreve o menu
		cout << endl << endl;
		cout << "	" << "Menu:" << endl << endl;
		cout << "	" << "1-New Game" << endl;
		cout << "	" << "2-Load Game" << endl;
		cout << "	" << "3-Save Game" << endl;
		cout << "	" << "4-How to Play" << endl;
		cout << "	" << "5-Leave Game" << endl;
		cout << endl << "	" << "Opcao:";// menu
		cin >> cax;

		bad = cin.fail();
		if (bad) {
			cout << '\t' << "Insira um valor correto..." << endl;
			Sleep(1000);
			cin.clear();
			cin.ignore(10, '\n');
		}
		else
			if (cax < 1 || cax>5) {
				cout << '\t' << "Insira um valor correto..." << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(10, '\n');
				bad = true;
			}
	} while (bad);


	if (0 < cax < 6)
		aux = cax;
	switch (aux) {
	case 5: // sai de jogo
	exit(0);
	break;
	case 4:
		H.Htp();
		Main_Menu();
		break;
	case 3: // faz save ao jogo e volta ao menu 
		Start.Save_Game();
		Main_Menu();
		break;
	case 2:
		system("CLS");
		Start.Load_Game(); // faz load do jogo
		Start.NewGame();
		if (Start.Get_Adv() == 1) {
			Start.Main_Game();
		}
		if (Start.Get_Adv() == 2) {
			Start.Main_2Game();
		}
		break;
	case 1:
		system("CLS"); // inicia um novo jogo
		T.Reset_Tabuleiro();
		Start.Chose_Adv();
		if (Start.Get_Adv() == 1) {
			Start.NewGame_Name();
			Start.NewGame();
			Start.Place_Boats();
			Start.Main_Game();
			Main_Menu();
		}
		if (Start.Get_Adv() == 2) {
			Start.NewGame_2Name();
			Start.NewGame();
			Start.Place_2Boats();
			Start.Main_2Game();
			Main_Menu();
		}
		if (Start.Get_Adv() == 0) {
			Main_Menu();
		}
		break;
	}
}

