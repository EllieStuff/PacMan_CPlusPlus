//Control i lògica del mapa
//TODO: ReadMap()
#include "Map.h"

void Map::ReadMap() {
	std::ifstream config("config.txt");
	if (config.is_open()) {
		char heap;
		//Assignació mida de l'array
		config >> totalRows;
		config >> heap;
		config >> totalColumns;
		config >> heap;

		//Creació de l'array map
		map = new char*[totalRows];
		for (int i = 0; i < totalRows; i++) {
			map[i] = new char[totalColumns];

		}
		config >> std::noskipws >> map[sizeX][sizeY];

		for (int i = 0; i < totalRows; i++) {
			for (int j = 0; j < totalColumns; j++) {
				config >> std::noskipws >> map[i][j];

				if (map[i][j] == '*') maxPoints++;

			}
			config >> heap;

		}

	}
	else
		return;

	config.close();

}

void Map::WriteMap(Position &playerPos) {
	//Assignar posició del jugador en la array map
	map[playerPos.x][playerPos.y] = '>';

	//Escriure mapa
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < totalRows; i++) {
		for (int j = 0; j < totalColumns; j++) {
			if (map[i][j] == '>' || map[i][j] == '0') {
				SetConsoleTextAttribute(consoleColor, 6);

			}
			else if (map[i][j] == '#') {
				SetConsoleTextAttribute(consoleColor, 4);

			}
			else if (map[i][j] == '&') {
				SetConsoleTextAttribute(consoleColor, 5);

			}
			else if (map[i][j] == '$') {
				SetConsoleTextAttribute(consoleColor, 2);

			}
			else if (map[i][j] == 'X') {
				map[i][j] = (char)219;
				SetConsoleTextAttribute(consoleColor, 1);

			}
			else if (map[i][j] == (char)219) {
				SetConsoleTextAttribute(consoleColor, 1);

			}
			else {
				SetConsoleTextAttribute(consoleColor, 7);

			}

			if (map[i][j] == (char)219) {
				std::cout << (char)219 << map[i][j];

			}
			else {
				std::cout << ' ' << map[i][j];

			}

		}
		std::cout << std::endl;

	}
	SetConsoleTextAttribute(consoleColor, 7);

}

void Map::ActualizeMap(Position &playerPos, Position &lastPos, char &character, Enemy enemyList[], const int &enemyNum) {
	map[lastPos.x][lastPos.y] = ' ';
	if (map[playerPos.x][playerPos.y] == (char)219) {
		playerPos = lastPos;

	}
	map[playerPos.x][playerPos.y] = character;

	for (int i = 0; i < enemyNum; i++) {
		map[enemyList[i].initialPos.x][enemyList[i].initialPos.y] = enemyList[i].overlapSave;

		switch (enemyList[i].id) {
		case 0:
			map[enemyList[i].pos.x][enemyList[i].pos.y] = '#';

			break;

		case 1:
			map[enemyList[i].pos.x][enemyList[i].pos.y] = '&';

			break;

		case 2:
			map[enemyList[i].pos.x][enemyList[i].pos.y] = '$';

			break;

		default:
			break;

		}

	}

	//Escriure mapa
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < totalRows; i++) {
		for (int j = 0; j < totalColumns; j++) {
			if (map[i][j] == '<' || map[i][j] == '>' || map[i][j] == 'v' || map[i][j] == '^' || map[i][j] == '0') {
				SetConsoleTextAttribute(consoleColor, 6);

			}
			else if (map[i][j] == '#') {
				SetConsoleTextAttribute(consoleColor, 4);

			}
			else if (map[i][j] == '&') {
				SetConsoleTextAttribute(consoleColor, 5);

			}
			else if (map[i][j] == '$') {
				SetConsoleTextAttribute(consoleColor, 2);

			}
			else if (map[i][j] == (char)219) {
				SetConsoleTextAttribute(consoleColor, 1);

			}
			else {
				SetConsoleTextAttribute(consoleColor, 7);

			}
			
			if (map[i][j] == (char)219) {
				std::cout << (char)219 << map[i][j];

			}
			else {
				std::cout << ' ' << map[i][j];

			}

		}
		std::cout << std::endl;

	}
	SetConsoleTextAttribute(consoleColor, 7);

}

void Map::WriteSplashScreen(std::string sceneString)
{
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\n\n\n                                                                                " << sceneString;
	SetConsoleTextAttribute(consoleColor, 232);
	std::cout << "              " << std::endl;
	std::cout << "                                                                                     " << sceneString;
	SetConsoleTextAttribute(consoleColor, 30); 
	std::cout << "  ";
	SetConsoleTextAttribute(consoleColor, 233);
	std::cout << "           " << std::endl;
	std::cout << " ______       ___         ______           ___     ___       ___       ___   ___               " << sceneString << std::endl;
	std::cout << " |  __ \\     / _ \\       /  ____|          |  \\   /  |      / _ \\      |  \\  | |           " << sceneString << std::endl;
	std::cout << " | |__| |   / /_\\ \\     |  |         ___   |   \\_/   |     / /_\\ \\     |   \\ | |         " << sceneString << std::endl;
	std::cout << " | ____/   /  ___  \\    |  |        /__/   | |\\___/| |    /  ___  \\    | |\\ \\| |         " << sceneString << std::endl;
	std::cout << " | |      /  /   \\  \\   |  |____           | |     | |   /  /   \\  \\   | | \\   |           " << sceneString << std::endl;
	std::cout << " |_|     /__/     \\__\\   \\______|          |_|     |_|  /__/     \\__\\  |_|  \\__|               " << sceneString << std::endl;
	std::cout << "                                                                                                  " << sceneString << std::endl;
	SetConsoleTextAttribute(consoleColor, 30);
	std::cout << "                                                                                             " << sceneString << std::endl;
	SetConsoleTextAttribute(consoleColor, 0);

}

void Map::WriteMainMenu()
{
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColor, 224);
	std::cout << "*-*-*-MAIN MENU-*-*-*" << std::endl;
	SetConsoleTextAttribute(consoleColor, 10);	//10
	std::cout << "1 - Play" << std::endl;
	SetConsoleTextAttribute(consoleColor, 11);	//11
	std::cout << "2 - Ranking" << std::endl;
	SetConsoleTextAttribute(consoleColor, 12);	//12
	std::cout << "0 - Exit Game" << std::endl;

}

void Map::WriteRanking()
{
	std::ofstream ranking("Ranking.txt");
	ranking << "";
	ranking.close();

}
