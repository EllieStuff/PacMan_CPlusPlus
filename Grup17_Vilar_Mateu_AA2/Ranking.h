#pragma once

#include "Types.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Ranking {
private:
	const int NUM_OF_RANKED_PLAYERS = 5;

	//void OrderRanking(const int &value);

public:
	std::map<std::string, int> playerMap;


	//void IncludePlayer(int score);

	bool CheckIfTop5(int score);

	void ReadRanking();

	void InitializeRanking();

	void WriteTop5();

	void OrderRanking();

};