//Control i lògica del mapa
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"

struct Map {
	int totalRows;
	int totalColumns;
	char** map;
	int sizeX = 0;
	int sizeY = 0;

	void ReadMap();

	void WriteMap(Position &pos);

	void ActualizeMap(Position &pos, Position &lastPos, char &character);

};
