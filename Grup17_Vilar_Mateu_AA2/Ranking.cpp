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
			playerMap.erase(it);
			playerMap.insert(it, std::pair<std::string, int>(name, score));
			playerInserted = true;
			break;
		}
	}
	if (playerMap.size() < NUM_OF_RANKED_PLAYERS) {
		name = AskForName();
		playerMap.insert(playerMap.end(), std::pair<std::string, int>(name, score));
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

void Ranking::WriteRanking()
{
	std::ifstream ranking("Ranking.txt");
	std::map<std::string, int>::iterator it;
	for (it = playerMap.begin(); it != playerMap.end(); it++) {
		//Vull que em llegeixi l'actual txt però per alguna raó no em deixa fer-ho amb el it
		//ranking >> it->second;

	}
	ranking.close();

}



void Ranking::WriteTop5()
{
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	std::map <std::string, int>::iterator it;
	int count = 1;
	for (it = playerMap.begin(); it != playerMap.end(); it++) {
		if(count == 1) SetConsoleTextAttribute(consoleColor, 10);
		else if (count == 5) SetConsoleTextAttribute(consoleColor, 12);
		else SetConsoleTextAttribute(consoleColor, 11);
		std::cout << count << "- " << it->first << "		" << it->second << std::endl;
		count++;

	}

}
