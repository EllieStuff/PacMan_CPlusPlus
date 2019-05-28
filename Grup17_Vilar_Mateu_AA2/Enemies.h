#pragma once
#include "Types.h"
#include <cmath>
#include <ctime>

class Enemy {
private:
	Position firstPos;
	char character;

	void Resize(int newSize);

	void MoveBlinky(char ** map, int i);

	void MoveInky(char ** map, int i, bool keyboard[]);

	void MoveClyde(char ** map, int i, bool keyboard[]);

	void CheckTP(char** map, int i, int columns, int rows);

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

	void MoveEnemies(char** map, bool keyboard[], int columns, int rows);

	void ReinitEnemies(char ** map);

};
