#pragma once
#include "Jogador.h"
#include "Barco.h"
#include "Tabuleiro.h"
#include <iostream>
#include<windows.h>
#include <string>
#include "Bot.h"
#include "Navio.h"



class Jogo
{
private:

	Tabuleiro T1,T2;
	PontoNaval P;
	Barco B;
	Jogador J1, J2;
	Bot B1;
	Navio N;

	int Aux; // define jogador ou bot
	int Turn = 1; // define o turno
	int Rtm = 1;
	public:
	Jogo();
	Jogo(int a_x);

	~Jogo();
	
	void Set_Adv(int a_x); // define se é 2 jogadores ou vs bot
	void Set_Turn(int b_x);
	void Set_PTurn() { Turn++; }
	void Set_MTurn() { Turn--; }
	void Gen_Turn();

	int Get_Adv() { return Aux; } // recebe esse valor
	int Get_Turn() { return Turn; }
	void Cln();
	
	void Chose_Adv(); // define se 2 jogadores ou jogador vs bot
	void Set_Rtm0() { Rtm = 0; }
	void Set_Rtm1() { Rtm = 1; }
	void Set_Rtm2() { Rtm = 2; }
	void Main_Game(); // começa o jogo 
	void Main_2Game();
	void NewGame_Name(); // define o nome do jogador
	void NewGame_2Name();
	void NewGame(); // cria os tabuleiros 
	void Place_Boats(); // coloca os barcos
	void Place_2Boats(); 
	int Jog1_Atk();
	int Jog2_Atk();
	int Bot_Atk();
	void End_Game(int x);
	void End_2Game(int x);
	

	void Save_Game(); // salva o jogo
	void Load_Game(); // carrega o jogo
	
};