#include "Help.h"

Help::Help()
{
}

Help::~Help()
{
}

void gotoxyz(short x, short y)           //definition of gotoxy function//                                               
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Help::Intro()
{
	cout  << endl << endl<< endl;
	cout << ("	         ____        _        _ _             _   _                  _ \n");
	cout<<("	        |  _ \\      | |      | | |           | \\ | |                | |\n");
	cout<<("	        | |_) | __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |\n");
	cout<<("	        |  _ < / _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |\n");
	cout<<("	        | |_) | (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |\n");
	cout<<("	        |____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| |_| \\_|\\__,_| \\_/ \\__,_|_|\n\n");
	cout << endl << endl << endl<<endl<<endl<<endl;
	cout << "Luis Silva Al-74132";
	Sleep(5000);
}

void Help::Htp()
{
	system("CLS");
	cout << "	" << "Como Jogar:" << endl << endl;
	cout << "  Regras Gerais:" << endl;
	cout << "Batalha Naval consiste em uma jogo de tabuleiro de 10 por 10 onde cada jogador posiciona os seu barcos/navios" << endl;
	cout << "e de seguida tenta afundar os barcos inimigos." << endl << "Cada Jogador pode fazer 3 disparos, podendo acertar na agua ou num barco" << endl;
	cout << endl << endl << "  Posicionamento de barcos:" << endl;
	cout << "Cada jogador deve colocar 4 submarinos, 3 contratorpedeiros, 2 cruzadores, 1 couracado e 1 porta avioes." << endl;
	cout << "As posicoes dos barcos devem ficar dentro dos limites do tabuleiro e nao podem ficar adjacentes." << endl;
	cout << "As coordenadas do barco variam entre 1 e 10 ou a e j, podendo ser inseridas em minusculas ou maiusculas(EX:a1 ou A1";
	cout << "Para colocar barcos com mais de 1 cano,deve indicar a direcao que pretende, W=cima,a=esquerda,d=direita,s=baixo" << endl;
	cout << "Veja o exemplo a baixo para compreender melhor";
	cout << endl << endl;
	T.Set_Square(0,0,'O'); T.Set_Square(0, 3, 'O'); T.Set_Square(1, 3, 'O');
	T.Set_Square(0, 9, 'O'); T.Set_Square(1, 9, 'O'); T.Set_Square(2, 9, 'O');
	T.Set_Square(5, 0, 'O'); T.Set_Square(5, 1, 'O'); T.Set_Square(5, 2, 'O'); T.Set_Square(5, 3, 'O');
	T.Set_Square(9, 5, 'O'); T.Set_Square(9, 4, 'O'); T.Set_Square(9, 3, 'O'); T.Set_Square(8, 4, 'O'); T.Set_Square(7, 4, 'O');
	T.Draw_Tabuleiro1();
	gotoxyz(60, 16); cout << "Exemplo de submarino na cordenada (a1)";
	gotoxyz(60, 17); cout << "Exemplo de contratorpedeiro na cordenada (d1s)";
	gotoxyz(60, 18); cout << "Exemplo de cruzador na cordenada (j1s)";
	gotoxyz(60, 19); cout << "Exemplo de couracado na cordenada (a6d)";
	gotoxyz(60, 20); cout << "Exemplo de porta-avioes na cordenada (e10w)";
	gotoxyz(0, 37);
	cout << endl << endl << "  Ataques:" << endl;
	cout << "Para atacar basta insirir a coordenada que pretende(EX a1 ou A1)" << endl;
	cout << "Quando atingir todos os barcos, o jogo acaba" << endl;
	system("pause");
}


