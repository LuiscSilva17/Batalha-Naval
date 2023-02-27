#include "Bot.h"


Bot::Bot()
{
	Bax = 0;
	Bay = 0;
	Bao = 0;
}

Bot::~Bot()
{
}

void Bot::Gen_Cords()
{	
	int x=0, y=0,aux=0;//o 1=w 2=a 3=s 4=d
	int aux2 = 0;
	char yl;
	srand(time(0));

	aux = rand() % 4 + 1;
	x = rand() % 10 + 1; // gera as coordenadas
	y = rand() % 10 + 1;
	yl = char(64 + y);
	aux2 = rand() % 2 + 1;
	Set_Bax(x);
	Set_Bay(y);
	Set_Bayl(yl);
	Set_Bao(aux);
	Set_Bao2(aux2);
}