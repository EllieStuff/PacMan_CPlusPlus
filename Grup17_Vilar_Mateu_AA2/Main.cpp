//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
//#include "Types.h"
//#include "Constants.h"

int main() {
	Map map;
	Player player;
	Keys key;
	bool endGame = false;
	int speed = 400;
	bool right, left, up, down, escape;

	//Inicialitzar mapa
	map.ReadMap();

	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	player.CalculateScore(map.map);

	//Dibuixar mapa
	map.WriteMap(player.pos);

	//Game Loop
	while (!endGame) {
		key.GetKeys(right, left, up, down, escape);
		player.MovePlayer(right, left, up, down, map.map, map.totalColumns, map.totalRows);
		map.ActualizeMap(player.pos, player.initialPos, player.character);
		std::cout << "\n Score: " << player.score;
		Sleep(speed);
		system("cls");

		if (map.maxPoints == player.score || escape) {
			endGame = true;

		}

	}

	return 0;
}