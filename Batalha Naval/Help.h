#pragma once
#include <iostream>
#include<windows.h>
#include "Tabuleiro.h"
using namespace std;

class Help
{
private:

	Tabuleiro T;

public:
	Help();
	~Help();
	void Intro ();
	void Htp();
	
};

