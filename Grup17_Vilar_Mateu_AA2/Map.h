//Control i lògica del mapa
#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Types.h"
#include "Enemies.h"

class Map {
private:
	int sizeX = 0;
	int sizeY = 0;

public:
	int totalRows;
	int totalColumns;
	char** map;
	int maxPoints = 0;

	void ReadMap();

	void WriteMap(Position &pos);

	void ActualizeMap(Position &pos, Position &lastPos, char &character, Enemy enemyList[], const int &enemyNum, const bool &hasPowerUp);

	void WriteSplashScreen(std::string sceneString);

	void WriteMainMenu();

	void WriteRanking();

};
