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
	std::string name = "df";
	std::cout << "Insert your name: ";
	std::cin >> name;

	return name;
}

bool Ranking::CheckIfTop5(int score)
{
	bool playerInserted = false;
	std::string name;

	std::map <std::string, int>::iterator it;
	for (it = playerMap.begin(); it != playerMap.end(); it++) {
		if (score > it->second) {
			name = AskForName();
			playerMap.insert(it, std::pair<std::string, int>(name, score));
			/*if (playerMap[name] > it->second) {
				int lastValue = it->second;
				std::string lastName = it->first;
				it 

			}*/
			playerMap.erase(it);
			//playerMap[name] = { score };
			playerInserted = true;
			break;
		}
	}
	if (playerMap.size() < NUM_OF_RANKED_PLAYERS && !playerInserted) {
		name = AskForName();
		playerMap.insert(playerMap.end(), std::pair<std::string, int>(name, score));
		//playerMap[name] = { score };
		playerInserted = true;
		
	}
	return playerInserted;
}

void Ranking::ReadRanking()
{
	//if (CheckIfTop5(score))
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
		//Vull que em llegeixi l'actual txt però per alguna raó no em deixa fer-ho amb el it
		int value;
		ranking >> value;
		playerMap[name] = { value };

	}
	ranking.close();

}



void Ranking::WriteTop5()
{
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	std::map <std::string, int>::iterator it;
	int count = 0;
	for (it = playerMap.begin(); it != playerMap.end(); it++) {
		if(count == 1) SetConsoleTextAttribute(consoleColor, 10);
		else if (count == 5) SetConsoleTextAttribute(consoleColor, 12);
		else SetConsoleTextAttribute(consoleColor, 11);
		if (count != 0) std::cout << count << "- " << it->first << "		" << it->second << std::endl;
		count++;

	}

}

void Ranking::OrderRanking()
{
	int* values = new int[NUM_OF_RANKED_PLAYERS];
	std::string* names = new std::string[NUM_OF_RANKED_PLAYERS];
	//Ja que això no funciona, pots provar a iniciar les arrays a partir d'un iterator i després canviar els valors del map (?)
	int count = 0;
	for (std::map<std::string, int>::iterator it = playerMap.begin(); it != playerMap.end(); it++) {
		names[count] = it->first;
		count++;

	}
	playerMap["tmp"];
	for (int i = 0; i < NUM_OF_RANKED_PLAYERS - 1; i++) {
		for (int j = 0; j < NUM_OF_RANKED_PLAYERS - i - 1; j++) {
			if (playerMap[names[j]] < playerMap[names[j + 1]]) {
				playerMap["tmp"] = playerMap[names[j]];
				playerMap[names[j]] = playerMap[names[j + 1]];
				playerMap[names[j]] = playerMap["tmp"];

			}

		}

	}
	playerMap.erase("tmp");

}
