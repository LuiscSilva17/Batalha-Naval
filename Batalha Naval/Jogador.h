#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Jogador
{
private:
	bool aux ,eaux;
	string Name;
	int Shots;
	int Hits;
public:

	
	Jogador();
	Jogador(string nn, int shts, int hts);
	~Jogador();


	string Get_Name(); //devolve nome
	int Get_Shots(); // devolve tiros
	int Get_Hits();
	void Set_Name(string np); // define nome
	void Set_Shots(int ns ); // define tiros
	void Set_Hits(int na);
	void Reset_Shots(); // definos tiros como 0
	
	void P_shots() { Shots++; }
	void P_hits() { Hits++; }

	void Set_aux();
	void Set_aux_end();
	int Get_show();
	int Get_show_end();
};
