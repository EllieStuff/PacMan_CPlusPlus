//Control i l�gica del jugador
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"
#include "Enemies.h"
#include "Windows.h"

class Player {
private:
	//int columns;
	//int rows;

public:
	Position pos;
	Position initialPos;
	int lives = 3;
	int score = 0;
	char character;

	void InitializePlayer(int totalRows, int totalColumns, char** map);

	void MovePlayer(bool right, bool left, bool up, bool down, char** map, int columns, int rows);

	void CalculateScore(char** map);

	void CalculateHealth(Enemy enemyList[], int enemyNum);

};