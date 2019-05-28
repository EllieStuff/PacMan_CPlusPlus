#include "Ranking.h"

//
//void Ranking::IncludePlayer(int score)
//{
//	std::string name;
//	std::ofstream ranking("Ranking.txt");
//	std::cin >> name;
//	//playerMap[name] = { name, score };
//
//}

std::string AskForName() {
	std::string name;
	std::cout << "Insert your name: ";
	std::cin >> name;

	return name;
}

bool Ranking::HasBeenPrinted(std::vector<std::string> namesVector, const std::string &name) {
	//Mira si name ja esta dins el vector i, per tant, ja ha estat printat
	for (std::vector<std::string>::iterator it = namesVector.begin(); it != namesVector.end(); it++) {
		if (it->data() == name) return true;

	}
	return false;
}

void Ranking::EnterInRanking(int score) {
	std::string name = AskForName();
	if (playerMap.count(name) == 0) playerMap[name] = { score };
	else {
		if (playerMap[name] < score) playerMap[name] = { score };

	}
	WriteRanking();

}

void Ranking::PrintRanking()
{
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<std::string> namesVector;
	//Mira quines son les puntuacions més altes fins  arribar al top 5
	for (int i = 0; i < NUM_OF_RANKED_PLAYERS; i++) {
		int score = 0;
		std::string name;
		for (std::map<std::string, int>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
			if (score < it->second && !HasBeenPrinted(namesVector, it->first)) {
				name = it->first;
				score = it->second;

			}

		}
		namesVector.push_back(name);

		if (i == 0) SetConsoleTextAttribute(consoleColor, 10);
		else if (i == NUM_OF_RANKED_PLAYERS - 1) SetConsoleTextAttribute(consoleColor, 12);
		else SetConsoleTextAttribute(consoleColor, 11);
		std::cout << i + 1 << "- " << name << "    		" << score << std::endl;

	}

}

void Ranking::WriteRanking()
{
	std::ofstream ranking ("Ranking.txt");
	for (std::map<std::string, int>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
		ranking << it->first << " " << it->second << std::endl;

	}
	ranking.close();

}

void Ranking::InitializeRanking()
{
	std::ifstream ranking("Ranking.txt");
	std::map<std::string, int>::iterator it;
	std::string name;
	while(ranking >> name) {
		int value;
		ranking >> value;
		playerMap[name] = { value };

	}
	ranking.close();

}
