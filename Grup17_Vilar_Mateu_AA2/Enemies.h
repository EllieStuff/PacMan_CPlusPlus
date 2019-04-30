#pragma once
#include "Types.h"
#include <cmath>
#include <ctime>

class Enemy {
private:
	void Resize(int newSize);

	void MoveBlinky(char** map, int i);

	void MoveInky(char** map, int i, bool right, bool left, bool up, bool down);

	void MoveClyde(char** map, int i, bool right, bool left, bool up, bool down);

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

	void MoveEnemies(char** map, bool right, bool left, bool up, bool down);

};