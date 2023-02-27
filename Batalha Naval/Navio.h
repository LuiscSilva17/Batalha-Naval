#pragma once
#include "Barco.h"


class Navio : public Barco
{
private:
	int a, x, y;

public:

	Navio();
	~Navio();

	void Draw_mc();
	void Set_Saux(int a_x) { a = a_x; }
	int Get_Saux() { return a; }
};

