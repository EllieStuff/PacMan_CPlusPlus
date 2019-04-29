#pragma once
#include "Types.h"

class Enemy {
private:
	//enum enemyType { BLINKY, INKY, CLYDE };
	Enemy* enemyList;
	int enemyNumber;
	int id;

	void Resize(int newSize);

	void DecideBlinkyPosition(char** map, int i);

public:
	Position pos;
	Position intialPos;

	Enemy();

	void SearchEnemies(char** map, int maxRows, int maxColumns);

	void MoveEnemies(char** map);

};