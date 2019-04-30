#pragma once
#include "Types.h"
#include <cmath>
#include <ctime>

class Enemy {
private:
	//enum enemyType { BLINKY, INKY, CLYDE };
	void Resize(int newSize);

	void DecideBlinkyPosition(char** map, int i);

public:
	int id;
	Enemy* enemyList;
	int enemyNumber;
	Position pos;
	Position initialPos;
	char overlapSymbol;
	char overlapSave;

	Enemy();

	void SearchEnemies(char** map, int maxRows, int maxColumns);

	void MoveEnemies(char** map);

};