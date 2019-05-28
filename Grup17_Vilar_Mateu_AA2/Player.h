//Control i lògica del jugador
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"
#include "Enemies.h"
#include "Windows.h"

class Player {
private:
	Position firstPos;
	const int INITIAL_LIVES = 3;
	const int INITIAL_SCORE = 0;

	void ReinitPos();

public:
	Position pos;
	Position initialPos;
	int lives = 3;
	int score = 0;
	char character;

	void InitializePlayer(int totalRows, int totalColumns, char** map);

	void MovePlayer(bool keyboard[], char** map, int columns, int rows);

	void CalculateScore(char** map);

	void CalculateHealth(Enemy enemyList[], int enemyNum);

	void ReinitPlayer();

};