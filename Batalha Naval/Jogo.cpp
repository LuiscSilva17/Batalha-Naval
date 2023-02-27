#include "Jogo.h"
#include "PontoNaval.h"
#include <iostream>
#include<windows.h>


using namespace std;

void gotoxy(short x, short y); // define posiçao no tabuleiro

void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Jogo::Jogo()
{
	Aux = 0;
}

Jogo::Jogo(int a_x)
{
	Set_Adv(a_x);
}

Jogo::~Jogo()
{

}

void Jogo::Set_Adv(int a_x) {
	Aux = a_x;
}

void Jogo::Set_Turn(int b_x) {
	Turn = b_x;
}

void Jogo::Gen_Turn() {
	srand(time(0));
	int tx;
	tx = rand() % 2 + 1;
	Set_Turn(tx);
}
void Jogo::Cln() {

	system("CLS");
	cout << endl << endl;
	T1.Draw_Tabuleiro1();
	gotoxy(65, 2);
	T2.Draw_Tabuleiro2();
	if(Get_Adv()==1){ cout << endl << "			  " << J1.Get_Name() << "							 " << B1.Get_Name() << endl << endl; }
	else{ cout << endl << "			  " << J1.Get_Name() << "							  " << J2.Get_Name() << endl << endl; }
}

void Jogo::Chose_Adv(){

	int ax = 0;
	bool bad = false;
	do {
		cout << endl << '\t';
		cout << "Tipo de Jogo:" << endl << endl << '\t' << "1 - Jogador contra bot" << endl << '\t' << "2 - Jogador contra jogador" << endl << '\t' << "0 - Regressar ao menu" << endl;
		cout << endl << '\t' << "Escolha:";
		cin >>ax;

		bad = cin.fail();
		if (bad) {
			cout << "Valor errado..." << endl;
			cin.clear();
			cin.ignore(10, '\n');
			system("Cls");
		}
		else if (ax < 0 || ax>2) {
			cout << '\t' << "Insira um valor correto..." << endl;
			Sleep(1000);
			cin.clear();
			cin.ignore(10, '\n');
			bad = true;
			system("Cls");
		}
	} while (bad);
	Set_Adv(ax);
}

void Jogo::Main_Game() {
	int i;
	cout << "Escolhendo quem joga primeiro..." << endl;
	Sleep(1000);
	Gen_Turn();
	if (Get_Turn() == 1) { cout << "Vez do " << J1.Get_Name() << endl; }
	else { cout << "Vez do " << B1.Get_Name() << endl; }
	system("pause");
	Cln();

	if (Get_Turn() == 1) {
		Set_Rtm1();
		do {
			if (Rtm == 1) { Jog1_Atk(); }
			if (Rtm == 2) { Bot_Atk(); }
		} while (Rtm != 0);
	}
	else{
		Set_Rtm2();
		do {
		if (Rtm == 2) { Bot_Atk(); }
		if (Rtm == 1) { Jog1_Atk(); }
	} while (Rtm != 0);}
}
void Jogo::Main_2Game() {
	int i;
	cout << "Escolhendo quem joga primeiro..." << endl;
	Sleep(1000);
	Gen_Turn();
	if (Get_Turn() == 1) { cout << "Vez do " << J1.Get_Name() << endl; }
	else { cout << "Vez do " << J2.Get_Name() << endl; }
	system("pause");
	Cln();

	if (Get_Turn() == 1) {
		Set_Rtm1();
		do {
			if (Rtm == 1) { Jog1_Atk(); }
			if (Rtm == 2) { Jog2_Atk(); }
		} while (Rtm!=0);
	}
	else {
		Set_Rtm2();
		do {
			if (Rtm == 2) { Jog2_Atk(); }
			if (Rtm == 1) { Jog1_Atk(); }
		} while (Rtm!=0);
	}

}

void Jogo::NewGame_Name() {

string nax, naxbot="Computador";
	system("Cls");
	cout << endl << '\t' << "Insira o seu nome:";
	cin >> nax;
	J1.Set_Name(nax);
	B1.Set_Name(naxbot);

	J1.Set_aux();

}

void Jogo::NewGame_2Name() {

	string nax1, nax2;
	system("Cls");
	cout << endl << '\t' << "Insira o nome do jogador 1:";
	cin >> nax1;
	J1.Set_Name(nax1);
	cout << endl << '\t' << "Insira o nome do jogador 2:";
	cin >> nax2;
	J2.Set_Name(nax2);

}

void Jogo::NewGame()
{			
	J1.Reset_Shots(); // define os tiros do jogador como 0
	J2.Reset_Shots();
	Cln();

}

void Jogo::Place_Boats() // coloca os barcos nas posiçoes indicadas
{
	int i, ax = 0, ay = 0, z = 0, cx = 0, cy = 0, o_aux = 0, bo_aux = 0;
	bool cxy = true;
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus submarinos:(4x vezes)" << endl;
	for (i = 0; i < 4; z++) {
		B.Draw_Subs(); // pede e desenha os barcos
		ax = B.Get_BX(); // recebe a posiçao x do barco
		ay = B.Get_BY(); // recebe a posiçao y do barco
		cxy = true;

		for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
			for (cy = 0; cy < 3; cy++) {
				if (((ax - cx > -1) & (ay - cy > -1)) && ((ax - cx < 10) & (ay - cy < 10))) {
					if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
						cxy = false;
					}
				}
			}
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; } // se o espaço estiver ocupado pede outra vez para inserir um espaço
	}//////////////////////////////////////////////////////////////////////////////// 2 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Contratorpedeiros(3x vezes, 2 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 3; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 2 < 0) || (o_aux == 2 & ay - 2 < 0) || (o_aux == 3 & ax > 9) || (o_aux == 4 & ay > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -1; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}/////////////////////////////////////////////////////////////////////////////////////////////////7 3 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Cruzadores(2x vezes, 3 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 2; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 3 < 0) || (o_aux == 2 & ay - 3 < 0) || (o_aux == 3 & ax + 1 > 9) || (o_aux == 4 & ay + 1 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}///////////////////////////////////////////////////////////////////////////////////////////4 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao do seu Couracado (4 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 4 < 0) || (o_aux == 2 & ay - 4 < 0) || (o_aux == 3 & ax + 2 > 9) || (o_aux == 4 & ay + 2 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 6; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 6; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -3; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -3; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); T1.Set_Square(ax - 4, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); T1.Set_Square(ax - 1, ay - 4, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); T1.Set_Square(ax + 2, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); T1.Set_Square(ax - 1, ay + 2, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}//////////////////////////////////////////////////////////////////////////////////////////////////// seta 
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao do seu Porta avioes (Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & (ax - 3 < 0 | ay - 2 < 0 | ay > 11)) || (o_aux == 2 & (ay - 2 < 0 | ax - 2 < 0 | ax > 11)) || (o_aux == 3 & (ax > 9 | ay - 2 < 0 | ay > 11)) || (o_aux == 4 & (ay > 9 | ax - 2 < 0 | ax > 11))) { cxy = false; }
		switch (o_aux) {
		case 1:
			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax, ay - 1, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax, ay - 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////bot_bot,porta aviaos
	cout << "Turno do Computador..." << endl;
	system("pause");
	Cln();
	cout << "Turno de posicionamento:" << endl;
	cout << "Posicionado porta avioes..." << endl;
	Sleep(500);
	for (i = 0; i < 1; z++) {

		B1.Gen_Cords();
		ax = B1.Get_Bax();
		ay = B1.Get_Bay();
		bo_aux = B1.Get_Bao();
		cxy = true;
		if ((bo_aux == 1 & (ax - 3 < 0 | ay - 2 < 0 | ay > 11)) || (bo_aux == 2 & (ay - 2 < 0 | ax - 1 < 0 | ax > 11)) || (bo_aux == 3 & (ax > 9 | ay - 2 < 0 | ay > 11)) || (bo_aux == 4 & (ay > 9 | ax - 2 < 0 | ax > 11))) { cxy = false; }
			switch (bo_aux) {
			case 1:
				for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}
				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = -1; cy < 4; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}
				break;
			case 2:
				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 5; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}
				for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
			case 3:

				for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}
				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = -1; cy < 4; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}

				}break;
			case 4:

				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = -2; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}
				for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
			}
			if (cxy == true) {
				T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
				switch (bo_aux) {
				case 1:T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax - 3, ay - 1, 'O'); T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay, 'O'); break;
				case 2:T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay - 3, 'O'); T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax, ay - 1, 'O'); break;
				case 3:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay, 'O'); break;
				case 4:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax, ay - 1, 'O'); break;
				}
				i++;
			}
	}////////////////////////////////////////////////////////////////////////////////////////////////4canos
		Cln();
		cout << "Turno de posicionamento:" << endl;
		cout << "Posicionando Couracado..." << endl;
		Sleep(500);
		for (i = 0; i < 1; z++) {
			B1.Gen_Cords();
			ax = B1.Get_Bax();
			ay = B1.Get_Bay();
			bo_aux = B1.Get_Bao2();
			cxy = true;
			if ((bo_aux == 1 & ax + 2 > 9) || (bo_aux == 2 & ay + 2 > 9)) { cxy = false; }
			switch (bo_aux) {
			case 1:

				for (cx = -3; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
			case 2:

				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 6; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
				
			}
			if (cxy == true) {
				T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
				switch (o_aux) {
				case 1:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); T2.Set_Square(ax + 2, ay - 1, 'O'); break;
				case 2:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); T2.Set_Square(ax - 1, ay + 2, 'O'); break;
				}
				i++;
			}
		}///////////////////////////////////////////////////////////////////////////////////////////3 canos
			Cln();
			cout << "Turno de posicionamento:" << endl;
			cout << "Posicionando Cruzadores..." << endl;
			Sleep(500);
			for (i = 0; i < 2; z++) {
				B1.Gen_Cords();
				ax = B1.Get_Bax();
				ay = B1.Get_Bay();
				bo_aux = B1.Get_Bao2();
				cxy = true;
				if ((bo_aux == 1 & ax + 1 > 9) || (bo_aux == 2 & ay + 1 > 9)) { cxy = false; }
				switch (bo_aux) {
				case 1:

					for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
						for (cy = 0; cy < 3; cy++) {
							if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
								if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
									cxy = false;
								}
							}
						}
					}break;
				case 2:

					for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
						for (cy = -2; cy < 3; cy++) {
							if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
								if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
									cxy = false;
								}
							}
						}
					}break;
				}
				if (cxy == true) {
					T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
					switch (bo_aux) {
					case 1:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); break;
					case 2:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); break;
					}
					i++;
					Cln();
					cout << "Posicionando Cruzadores..." << endl;
				}
		}///////////////////////////////////////////////////////////////////////////////////////////////////////2canos
		Cln();
		cout << "Turno de posicionamento:" << endl;
		cout << "Posicionando Contratorpedeiro..." << endl;
		Sleep(500);
		for (i = 0; i < 3; z++) {
			B1.Gen_Cords();
			ax = B1.Get_Bax();
			ay = B1.Get_Bay();
			bo_aux = B1.Get_Bao2();
			cxy = true;
			if ((bo_aux == 1 & ax > 9) || (bo_aux == 2 & ay > 9)) { cxy = false; }
			switch (bo_aux) {
			case 1:

				for (cx = -1; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = 0; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
			case 2:

				for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
					for (cy = -1; cy < 3; cy++) {
						if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
							if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
								cxy = false;
							}
						}
					}
				}break;
			}
			if (cxy == true) {
				T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
				switch (bo_aux) {
				case 1:T2.Set_Square(ax, ay - 1, 'O'); break;
				case 2:T2.Set_Square(ax - 1, ay, 'O'); break;
				}
				i++;
				Cln();
				cout << "Posicionando Contratorpedeiro..." << endl;
			}
		}///////////////////////////////////////////////////////////////////////////////////////////1 canos
		Cln();
		cout << "Turno de posicionamento:" << endl;
		cout << "Posicionado Submarinos..." << endl;
		Sleep(500);
		for (i = 0; i < 4; z++) {
			B1.Gen_Cords(); // gera uma posiçao para o bot
			ax = B1.Get_Bax();	// recebe a posiçao x do barco
			ay = B1.Get_Bay();	// recebe a posiçao y do barco
			cxy = true;

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if (T2.Get_Square(ax - cx, ay - cy) == 'O') {// verifica se o espaço esta ocupado
						cxy = false;
					}
				}
			}

			if (cxy == true) {
				T2.Set_Square(ax - 1, ay - 1, 'O'); // atribui o espaço e desenha no tabuleiro
				//cout << ax << ay; Sleep(1000); // funçao de teste para verificar as posiçoes do bot 

				i++;
				Cln();
				cout << "Posicionado Submarinos..." << endl;
			}

		} // se nao atribuir volta a gerar uma posiçao
		Cln();
	
}

void Jogo::Place_2Boats() // coloca os barcos nas posiçoes indicadas
{
	int i, ax = 0, ay = 0, z = 0, cx = 0, cy = 0, o_aux = 0, bo_aux = 0;
	bool cxy = true;
	cout << "Turno de posicionamento:" << endl;
	cout << "Vez do Jogador:" << J1.Get_Name() << endl;
	cout << "Defina a posicao dos seus submarinos(4x vezes):" << endl;
	for (i = 0; i < 4; z++) {
		B.Draw_Subs(); // pede e desenha os barcos
		ax = B.Get_BX(); // recebe a posiçao x do barco
		ay = B.Get_BY(); // recebe a posiçao y do barco
		cxy = true;

		for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
			for (cy = 0; cy < 3; cy++) {
				if (((ax - cx > -1) & (ay - cy > -1)) && ((ax - cx < 10) & (ay - cy < 10))) {
					if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
						cxy = false;
					}
				}
			}
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; } // se o espaço estiver ocupado pede outra vez para inserir um espaço
	}//////////////////////////////////////////////////////////////////////////////// 2 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Contratorpedeiros(3x vezes, 2 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 3; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 2 < 0) || (o_aux == 2 & ay - 2 < 0) || (o_aux == 3 & ax > 9) || (o_aux == 4 & ay > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -1; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}/////////////////////////////////////////////////////////////////////////////////////////////////7 3 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Cruzadores(2x vezes, 3 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 2; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 3 < 0) || (o_aux == 2 & ay - 3 < 0) || (o_aux == 3 & ax + 1 > 9) || (o_aux == 4 & ay + 1 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}///////////////////////////////////////////////////////////////////////////////////////////4 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao do seu Couracado (4 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 4 < 0) || (o_aux == 2 & ay - 4 < 0) || (o_aux == 3 & ax + 2 > 9) || (o_aux == 4 & ay + 2 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 6; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 6; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -3; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -3; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); T1.Set_Square(ax - 4, ay - 1, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); T1.Set_Square(ax - 1, ay - 4, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); T1.Set_Square(ax + 2, ay - 1, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); T1.Set_Square(ax - 1, ay + 2, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}//////////////////////////////////////////////////////////////////////////////////////////////////// seta 
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao do seu Porta avioes (Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & (ax - 3 < 0 | ay - 2 < 0 | ay > 11)) || (o_aux == 2 & (ay - 2 < 0 | ax - 2 < 0 | ax > 11)) || (o_aux == 3 & (ax > 9 | ay - 2 < 0 | ay > 11)) || (o_aux == 4 & (ay > 9 | ax - 2 < 0 | ax > 11))) { cxy = false; }
		switch (o_aux) {
		case 1:
			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T1.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T1.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax - 3, ay - 1, 'O'); T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay, 'O'); break;
			case 2:T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay - 3, 'O'); T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax, ay - 1, 'O'); break;
			case 3:T1.Set_Square(ax, ay - 1, 'O'); T1.Set_Square(ax + 1, ay - 1, 'O'); T1.Set_Square(ax - 1, ay - 2, 'O'); T1.Set_Square(ax - 1, ay, 'O'); break;
			case 4:T1.Set_Square(ax - 1, ay, 'O'); T1.Set_Square(ax - 1, ay + 1, 'O'); T1.Set_Square(ax - 2, ay - 1, 'O'); T1.Set_Square(ax, ay - 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////mudança de turno
	cout << "Mudança de turno:" << endl << "Vez do " << J2.Get_Name();
	Sleep(2000);
	Cln();
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus submarinos(4x vezes):" << endl;
	for (i = 0; i < 4; z++) {
		B.Draw_Subs(); // pede e desenha os barcos
		ax = B.Get_BX(); // recebe a posiçao x do barco
		ay = B.Get_BY(); // recebe a posiçao y do barco
		cxy = true;

		for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
			for (cy = 0; cy < 3; cy++) {
				if (((ax - cx > -1) & (ay - cy > -1)) && ((ax - cx < 10) & (ay - cy < 10))) {
					if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
						cxy = false;
					}
				}
			}
		}
		if (cxy == true) {
			T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; } // se o espaço estiver ocupado pede outra vez para inserir um espaço
	}//////////////////////////////////////////////////////////////////////////////// 2 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Contratorpedeiros(2 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 3; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 2 < 0) || (o_aux == 2 & ay - 2 < 0) || (o_aux == 3 & ax > 9) || (o_aux == 4 & ay > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -1; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T2.Set_Square(ax - 2, ay - 1, 'O'); break;
			case 2:T2.Set_Square(ax - 1, ay - 2, 'O'); break;
			case 3:T2.Set_Square(ax, ay - 1, 'O'); break;
			case 4:T2.Set_Square(ax - 1, ay, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}/////////////////////////////////////////////////////////////////////////////////////////////////7 3 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Cruzadores(3 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 2; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 3 < 0) || (o_aux == 2 & ay - 3 < 0) || (o_aux == 3 & ax + 1 > 9) || (o_aux == 4 & ay + 1 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax - 3, ay - 1, 'O'); break;
			case 2:T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay - 3, 'O'); break;
			case 3:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); break;
			case 4:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}///////////////////////////////////////////////////////////////////////////////////////////4 canos
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Couracado (4 quadrados, Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & ax - 4 < 0) || (o_aux == 2 & ay - 4 < 0) || (o_aux == 3 & ax + 2 > 9) || (o_aux == 4 & ay + 2 > 9)) { cxy = false; }
		switch (o_aux) {
		case 1:

			for (cx = 0; cx < 6; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 6; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -3; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -3; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax - 3, ay - 1, 'O'); T2.Set_Square(ax - 4, ay - 1, 'O'); break;
			case 2:T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay - 3, 'O'); T2.Set_Square(ax - 1, ay - 4, 'O'); break;
			case 3:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); T2.Set_Square(ax + 2, ay - 1, 'O'); break;
			case 4:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); T2.Set_Square(ax - 1, ay + 2, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}//////////////////////////////////////////////////////////////////////////////////////////////////// seta 
	cout << "Turno de posicionamento:" << endl;
	cout << "Defina a posicao dos seus Porta avioes (Ex:f5 w):" << endl;
	for (i = 0; i < 1; z++) {
		N.Draw_mc();
		ax = N.Get_BX();
		ay = N.Get_BY();
		o_aux = N.Get_Saux();
		cxy = true;
		if ((o_aux == 1 & (ax - 3 < 0 | ay - 2 < 0 | ay > 11)) || (o_aux == 2 & (ay - 2 < 0 | ax - 2 < 0 | ax > 11)) || (o_aux == 3 & (ax > 9 | ay - 2 < 0 | ay > 11)) || (o_aux == 4 & (ay > 9 | ax - 2 < 0 | ax > 11))) { cxy = false; }
		switch (o_aux) {
		case 1:
			for (cx = 0; cx < 5; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 2:
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 5; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 3:

			for (cx = -2; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -1; cy < 4; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		case 4:

			for (cx = 0; cx < 3; cx++) { // Verifica posiçoes adjacentes 
				for (cy = -2; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}
			for (cx = -1; cx < 4; cx++) { // Verifica posiçoes adjacentes 
				for (cy = 0; cy < 3; cy++) {
					if ((ax - cx > -1 & ay - cy > -1) && (ax - cx < 10 & ay - cy < 10)) {
						if (T2.Get_Square(ax - cx, ay - cy) == 'O') {
							cxy = false;
						}
					}
				}
			}break;
		}
		if (cxy == true) {
			T2.Set_Square(ax - 1, ay - 1, 'O'); //atribui o espaço e desenha os tabuleiros com o espaço ja atribuido
			switch (o_aux) {
			case 1:T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax - 3, ay - 1, 'O'); T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay, 'O'); break;
			case 2:T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay - 3, 'O'); T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax, ay - 1, 'O'); break;
			case 3:T2.Set_Square(ax, ay - 1, 'O'); T2.Set_Square(ax + 1, ay - 1, 'O'); T2.Set_Square(ax - 1, ay - 2, 'O'); T2.Set_Square(ax - 1, ay, 'O'); break;
			case 4:T2.Set_Square(ax - 1, ay, 'O'); T2.Set_Square(ax - 1, ay + 1, 'O'); T2.Set_Square(ax - 2, ay - 1, 'O'); T2.Set_Square(ax, ay - 1, 'O'); break;
			}
			i++;
			Cln();
		}
		else { cout << "Posicao ja ocupada ou indisponível, insira novamente" << endl; }
	}
}


int Jogo::Jog1_Atk() {
	int i, z = 0, ax = 0, ay = 0, end = 1;
	Set_Rtm2();
	for (i = 0; i < 3; z++) {
		cout << "Turno de ataque:" << endl;
		cout << "Vez do Jogador: "<< J1.Get_Name() << endl; // executa o turno do jogador com 3 tiros
		P.Ask2Set(); // pede as cordenadas e verifica as coordenadas 
		ax = P.Get_X();
		ay = P.Get_Y_N();

		if (T2.Get_Square(ax - 1, ay - 1) != 'T' && T2.Get_Square(ax - 1, ay - 1) != 'A') { // se a localiçao n tiver sido atingida avança para o processo do acerto , 
			J1.P_shots();
			if (T2.Get_Square(ax - 1, ay - 1) == 'O') { // se for um barco , desenha o tiro 
				i++; // apenas se o tiro for aceite e que conta como jogada
				cout << "-Barco atingido";
				Sleep(750);
				T2.Set_Square(ax - 1, ay - 1, 'T'); // define o espaço como tiro
				Cln();
				J1.P_hits();
				if (J1.Get_Hits() >= 25) { cout << endl << '\t' << "GAME OVER!"; Sleep(2000); End_2Game(end); return 0; } // finaliza o jogo e volta ao menu
			}
			else if (T2.Get_Square(ax - 1, ay - 1) == '.') { // se for um espaço vazio, escreve agua 
				i++; // apenas se o tiro for aceite e que conta como jogada
				cout << "-Agua!!";
				Sleep(750);
				T2.Set_Square(ax - 1, ay - 1, 'A'); // define o espaço como agua
				Cln();
			}
		}
		else { cout << "Coordenada ja atinjida, tente outra vez..." << endl; Sleep(500); }

	}
}

int Jogo::Jog2_Atk() {
	int i, z = 0, ax, ay, end = 2;
	Set_Rtm1();
	for (i = 0; i < 3; z++) {
		cout << "Turno de ataque:" << endl;
		cout << "Vez do Jogador: "<< J2.Get_Name() << endl; // executa o turno do jogador com 3 tiros
		P.Ask2Set(); // pede as cordenadas e verifica as coordenadas 
		ax = P.Get_X();
		ay = P.Get_Y_N();

		if (T1.Get_Square(ax - 1, ay - 1) != 'T' && T1.Get_Square(ax - 1, ay - 1) != 'A') { // se a localiçao n tiver sido atingida avança para o processo do acerto , 
			J2.P_shots();
			if (T1.Get_Square(ax - 1, ay - 1) == 'O') { // se for um barco , desenha o tiro 
				i++; // apenas se o tiro for aceite e que conta como jogada
				cout << "-Barco atingido";
				Sleep(750);
				T1.Set_Square(ax - 1, ay - 1, 'T'); // define o espaço como tiro
				Cln();
				J2.P_hits();
				if (J2.Get_Hits() >= 25) { cout << endl << '\t' << "GAME OVER!"; Sleep(2000); End_2Game(end); return 0; } // finaliza o jogo e volta ao menu
			}
			else if (T1.Get_Square(ax - 1, ay - 1) == '.') { // se for um espaço vazio, escreve agua 
				i++; // apenas se o tiro for aceite e que conta como jogada
				cout << "-Agua!!";
				Sleep(750);
				T1.Set_Square(ax - 1, ay - 1, 'A'); // define o espaço como agua
				Cln();
			}
		}
		else { cout << "Coordenada ja atinjida, tente outra vez..." << endl; Sleep(500); }

	}
}

int Jogo::Bot_Atk() {
	srand(time(0));
	int i, z = 0, abx, aby, tp = 0;
	char abyl;
	int tba = 0, tb = 0;
	int end = 2;
	Set_Rtm1();
		for (i = 0; i < 3; z++) { // jogadas do bot
		B1.Gen_Cords();
		abx = B1.Get_Bax(); 
		aby = B1.Get_Bay();
		abyl = B1.Get_Bayl();
			if (T1.Get_Square(abx - 1, aby - 1) != 'T' && T1.Get_Square(abx - 1, aby - 1) != 'A') { // verifica o espaço se é permitido
				B1.P_shots();
				cout << "Turno de ataque:" << endl;
				cout << "Vez do computador:";
				Sleep(500);
				i++;
				tb++;
				cout << " " << abyl << abx << endl;
				if (T1.Get_Square(abx - 1, aby - 1) == 'O') { // verifica se é barco
					B1.P_hits();
					cout << "-Barco atingido";
					Sleep(1500);
					T1.Set_Square(abx - 1, aby - 1, 'T'); // define o espaço como tiro
					Cln();
					tba++;
					if (tba >= 25) { cout << endl << '\t' << "GAME OVER!"; Sleep(2000);  End_Game(end); return 0; } // finaliza o jogo e volta ao menu
				}
				else if (T1.Get_Square(abx - 1, aby - 1) == '.') { // verifica se é agua
					cout << "-Agua!!";
					Sleep(1500);
					T1.Set_Square(abx - 1, aby - 1, 'A'); // define o espaço como agua
					Cln();
				}
			}
		}
}

void Jogo::End_Game(int x)
{
	double aux, ta=0;
	aux = x;
	J1.Set_aux_end();
	J2.Set_aux_end();

	cout << endl;
	if (aux == 1) { // verifica quem ganhou
		ta = ((J1.Get_Hits() / (J1.Get_Shots())* 100));
		Cln();
		cout << J1.Get_Name() << " foi o vencedor!" << endl << "Tiros:" << J1.Get_Shots() << endl << "Acertos:" << J1.Get_Hits() << endl << "Taxa de acerto:" << setprecision(3) << ta << "%" << endl;
		system("pause");
	}
	if (aux == 2) {
		ta = ((B1.Get_Hits() / (B1.Get_Shots()) * 100));
		Cln();
		cout << "Computador foi o vencedor!" << endl << "Tiros:" << B1.Get_Shots() << endl << "Acertos:" << B1.Get_Hits() << endl << "Taxa de acerto:" << setprecision(3) << ta << "%" << endl;
		system("pause");
	}
	Set_Rtm0();
}

void Jogo::End_2Game(int x)
{
	double aux, ta=0;
	aux = x;
	J1.Set_aux_end();
	J2.Set_aux_end();
	cout << endl;
	if (aux == 1) { // verifica quem ganhou
		ta = ((J1.Get_Hits() / (J1.Get_Shots()) * 100));
		Cln();
		cout << "Jogador "<< J1.Get_Name() << " foi o vencedor!" << endl << "Tiros:" << J1.Get_Shots() << endl << "Acertos:" << J1.Get_Hits() << endl << "Taxa de acerto:" << setprecision(3) << ta << "%" << endl;
		system("pause");
	}
	if (aux == 2) {
		ta = ((J2.Get_Hits() / (J2.Get_Shots()) * 100));
		Cln();
		cout << "Jogador "<< J2.Get_Name() << " foi o vencedor!" << endl << "Tiros:" << J2.Get_Shots() << endl << "Acertos:" << J2.Get_Hits() << endl << "Taxa de acerto:" << setprecision(3) << ta << "%" << endl;
		system("pause");
	}
	Set_Rtm0();
}

void Jogo::Save_Game() // faz save game, vai guardar o nome , tiros e coordenadas dos tabuleiros
{
	Set_Turn(1);
	J1.Set_Shots(0);J1.Set_Hits(0);
	J2.Set_Name("a");J2.Set_Shots(0);J2.Set_Hits(0);
	B1.Set_Name("Bot");B1.Set_Shots(0);B1.Set_Hits(0);
	int i, j;
	string name_;
	system("CLS");
	cout << endl << '\t' << "|Save Game|" << endl << endl << '\t' << " Player Name:";
	cin >> name_;
	J1.Set_Name(name_);
	ofstream gsave("Dados de Jogador");
	gsave << Get_Turn() << "," << J1.Get_Name() << "," << J1.Get_Hits() << "," << J1.Get_Shots() << ",";

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			gsave << int(T1.Get_Square(i, j)) << ",";
		}
	}
	if (Get_Turn() == 1) { gsave << B1.Get_Name() << "," << B1.Get_Hits() << "," << B1.Get_Shots() << ","; }
	else { gsave << J2.Get_Name() << "," << J2.Get_Hits() << "," << J2.Get_Shots() << ","; }
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			gsave << int(T2.Get_Square(i, j)) << ",";
		}
	}
	gsave.close();
	cout << endl << '\t' << "Game Saved..." << endl;
	cout << endl << "Press Enter to return to Main Menu." << endl;
	system("pause");
}

void Jogo::Load_Game() // carrega o nome tiros e coordenadas dos tabuleiros
{
	int i, j;
	char aux[30];
	ifstream save("Dados de Jogador");

	if (save) {
		save.getline(aux, 30, ',');
		Set_Turn(atof(aux));
		save.getline(aux, 30, ',');
		J1.Set_Name(aux);
		save.getline(aux, 10, ',');
		J1.Set_Hits(atof(aux));
		save.getline(aux, 10, ',');
		J1.Set_Shots(atof(aux));
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				save.getline(aux, 10, ',');
				T1.Set_Square(i,j ,(atof(aux)));}}
		if (Get_Turn() == 1) {
			save.getline(aux, 30, ',');
			J2.Set_Name(aux);
			save.getline(aux, 10, ',');
			J2.Set_Hits(atof(aux));
			save.getline(aux, 10, ',');
			J2.Set_Shots(atof(aux));
		}
		else {
			save.getline(aux, 30, ',');
			B1.Set_Name(aux);
			save.getline(aux, 10, ',');
			B1.Set_Hits(atof(aux));
			save.getline(aux, 10, ',');
			B1.Set_Shots(atof(aux));

		}
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				save.getline(aux, 10, ',');
				T2.Set_Square(i, j, (atof(aux)));}}
	}
	else { "ERRO: Ficheiro não existente..."; }
	if (Get_Turn() == 1) { cout << "Loading: " << J1.Get_Name() << " vs Bot"; }
	else{cout << "Loading: " << J1.Get_Name() << J2.Get_Name(); } 
	Sleep(1500);
	system("CLS");
}
