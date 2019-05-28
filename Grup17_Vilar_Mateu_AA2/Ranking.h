#pragma once

#include "Types.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Ranking {
private:
	const int NUM_OF_RANKED_PLAYERS = 5;

	bool HasBeenPrinted(std::vector<std::string> namesVector, const std::string &name);

	void WriteRanking();

public:
	std::map<std::string, int> playerMap;

	void EnterInRanking(int score);

	void PrintRanking();

	void InitializeRanking();

};