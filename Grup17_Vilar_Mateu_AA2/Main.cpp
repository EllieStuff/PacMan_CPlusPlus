//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
#include "Enemies.h"
//#include "Types.h"
//#include "Constants.h"

int main() {
	Map map;
	Player player;
	Keys key;
	Enemy enemy;
	bool endGame = false;
	bool pause = false;
	int speed = 400;
	bool right, left, up, down, escape, startPause, quitPause;

	//Inicialitzar mapa
	map.ReadMap();
	enemy.SearchEnemies(map.map, map.totalRows, map.totalColumns);

	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	player.CalculateScore(map.map);

	//Dibuixar mapa
	map.WriteMap(player.pos);

	//Game Loop
	while (!endGame) {
		//Actualitzar mapa
		key.GetKeys(right, left, up, down, escape, startPause, quitPause);
		player.MovePlayer(right, left, up, down, map.map, map.totalColumns, map.totalRows);
		enemy.MoveEnemies(map.map);
		map.ActualizeMap(player.pos, player.initialPos, player.character);
		std::cout << "\n Score: " << player.score << std::endl;

		//Pausar el joc
		if (startPause) {
			pause = true;
			std::cout << " Press space to continue...";

		}
		while (pause) {
			key.GetKeys(right, left, up, down, escape, startPause, quitPause);
			if (quitPause || escape) {
				pause = false;

			}

		}

		//Esperar i borrar mapa anterior
		Sleep(speed);
		system("cls");

		//Sortir del joc
		if (map.maxPoints == player.score || escape) {
			endGame = true;

		}

	}

	//return 0;
}