//Control i lògica del jugador
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"
#include "Windows.h"

struct Player {
	Position pos;
	Position initialPos;
	int columns;
	int rows;
	int score;
	char character;

	void InitializePlayer(int totalRows, int totalColumns, char** map);

	void MovePlayer(bool right, bool left, bool up, bool down, char** map, int columns, int rows);

};