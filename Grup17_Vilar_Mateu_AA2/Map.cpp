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

		while (sizeX < totalRows) {
			while (sizeY < totalColumns) {
				config >> std::noskipws >> map[sizeX][sizeY];

				sizeY++;
			}
			sizeY = 0;

			sizeX++;
			//config >> std::noskipws >> map[sizeX][sizeY];
			config >> heap;

		}

	}
	else
		std::cout << "I AM ERROR";

	config.close();

}

void Map::WriteMap(Position &pos) {
	//Assignar posició del jugador en la array map
	map[pos.x][pos.y] = '>';

	//Escriure mapa
	for (int i = 0; i < totalRows; i++) {
		for (int j = 0; j < totalColumns; j++) {
			std::cout << ' ' << map[i][j];

		}
		std::cout << '\n';

	}


}

void Map::ActualizeMap(Position &pos, Position &lastPos, char &character) {
	system("cls");
	map[lastPos.x][lastPos.y] = ' ';
	if (map[pos.x][pos.y] == 'X') {
		pos = lastPos;

	}
	map[pos.x][pos.y] = character;

	//Escriure mapa
	for (int i = 0; i < totalRows; i++) {
		for (int j = 0; j < totalColumns; j++) {
			std::cout << ' ' << map[i][j];

		}
		std::cout << '\n';

	}

}