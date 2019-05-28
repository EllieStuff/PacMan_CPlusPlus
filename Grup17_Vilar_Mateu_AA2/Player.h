//Control i lògica del jugador
#pragma once

#include <fstream>
#include <iostream>
#include "Types.h"
#include "Enemies.h"
#include "Windows.h"
#include <time.h>

class Player {
private:
	Position firstPos;
	const int INITIAL_LIVES = 3;
	const int INITIAL_SCORE = 0;
	const int POWER_UP_TIME = 7000;
	const int BONUS_POINTS = 15;
	bool onCountDown = false;

	void ReinitPos();

public:
	Position pos;
	Position initialPos;
	int lives = 3;
	int score = 0;
	char character;
	bool hasPowerUp = false;

	void InitializePlayer(int totalRows, int totalColumns, char** map);

	void MovePlayer(bool keyboard[], char** map, int columns, int rows);

	void CalculateScore(char** map);

	void CalculateHealth(Enemy enemyList[], int enemyNum, char** map, int &maxPoints);

	void ReinitPlayer();

	void ControlPowerUpState(time_t &start);

};