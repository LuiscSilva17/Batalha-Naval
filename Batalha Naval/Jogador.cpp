#include "Jogador.h"
#include<windows.h>

using namespace std;



Jogador::Jogador()
{
	Name = ""; Shots = 0; Hits = 0;
}

Jogador::Jogador(string nn, int shts, int hts) {
	Name = nn;
	Shots = shts;
	Hits = hts;
}

Jogador::~Jogador()
{
}


string Jogador::Get_Name() //devolve nome
{
	return Name;
}

int Jogador::Get_Shots() // devolve tiros
{
	return Shots;
}

int Jogador::Get_Hits()
{
	return Hits;
}
void Jogador::Set_Name(string np) // define nome
{
	Name = np;
}

void Jogador::Set_Hits(int na) // define tiros
{
	Hits = na;
}

void Jogador::Set_Shots(int ns) // define tiros
{
	Shots = ns;
}

void Jogador::Reset_Shots() // definos tiros como 0
{
	Shots = 0;
	Hits = 0;
}

void Jogador::Set_aux()
{
	aux = true;
}

void Jogador::Set_aux_end()
{
	eaux = true;
}

int Jogador::Get_show()
{
	return aux;
}

int Jogador::Get_show_end()
{
	return eaux;
}




