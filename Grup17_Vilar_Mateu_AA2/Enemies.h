#pragma once
#include "Types.h"
#include <cmath>
#include <ctime>

class Enemy {
private:
	Position firstPos;

	void Resize(int newSize);

	void MoveBlinky(char ** map, int i);

	void MoveInky(char ** map, int i, bool keyboard[]);

	void MoveClyde(char ** map, int i, bool keyboard[]);

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

	void MoveEnemies(char** map, bool keyboard[]);

	void ReinitEnemies(char ** map);

};
