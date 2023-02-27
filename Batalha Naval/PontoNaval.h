#pragma once
#include <fstream>
#include<windows.h>

class PontoNaval
{
	private:
		int x; //1 -- 10
		char y; //A -- J
		
	public:
		PontoNaval();
		PontoNaval(int t_x, char t_y);
		PontoNaval(int t_x, int t_y);
		~PontoNaval();

		bool Set_X(int t_x); // verificaçao da coordenada
		bool Set_Y(char t_y); // verificaçao da coordenada
			
		int Get_X() const { return x; } // devolve as coordenadas x
		char Get_Y() const { return y; } // devolve as coordenadas y
		int Get_Int_Y(); // devolve as coordenadas y 
		int Get_Y_N(); // devolve as coordenadas y em numero aschii
	

		void Ask2Set(void); //pede as cordenadas e verifica
		void Show(); // mostra os pontos

	
	};


