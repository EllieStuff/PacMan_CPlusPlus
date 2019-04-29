//Control i l�gica del mapa
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"

class Map {
private:
	int sizeX = 0;
	int sizeY = 0;

public:
	int totalRows;
	int totalColumns;
	char** map;
	int maxPoints = 0;

	void ReadMap();

	void WriteMap(Position &pos);

	void ActualizeMap(Position &pos, Position &lastPos, char &character);

};
