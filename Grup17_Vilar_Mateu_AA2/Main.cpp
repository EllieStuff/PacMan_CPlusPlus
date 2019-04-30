//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
#include "Enemies.h"
//#include "Types.h"
//#include "Constants.h"

//TODO: Ara que el Blinky ja esta fet, falta comprovar que les direccions a les que apunta siguin sempre random i correctes
int main() {
	srand(NULL(time));
	Map map;
	Player player;
	Keys key;
	Enemy enemy;
	bool endGame = false;
	bool pause = false;
	bool startPause = false;
	bool gameOver = false;
	int speed = 400;
	bool right, left, up, down, escape, quitPause;

	//Inicialitzar mapa
	map.ReadMap();
	enemy.SearchEnemies(map.map, map.totalRows, map.totalColumns);

	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	player.CalculateScore(map.map);

	//Dibuixar mapa
	std::cout <<" *-*-INIT-*-*" << std::endl << "Press space to start game." << std::endl;
	map.WriteMap(player.pos);
	std::cout << "SCORE: " << player.score;
	player.CalculateHealth(enemy.enemyList, enemy.enemyNumber);

	//Controlador d'estats: Init
	while (true) {
		key.GetKeys(right, left, up, down, escape, startPause, quitPause);
		if (quitPause || escape) {
			system("cls");
			break;

		}

	}

	//Game Loop
	while (!endGame) {
		//Controlador d'estats: Pause
		if (startPause) {
			pause = true;
			std::cout << "*-*-PAUSE-*-*" << std::endl << "Press space to continue." << std::endl;

		}
		else if (gameOver) {
			std::cout << "*-*-GAME OVER-*-*" << std::endl << "Press escape to exit." << std::endl;

		}
		else {
			std::cout << "*-*-PLAY-*-*" << std::endl;

		}

		if (player.lives < 1 || map.maxPoints == player.score) {
			gameOver = true;

		}

		//Actualitzar mapa
		key.GetKeys(right, left, up, down, escape, startPause, quitPause);
		player.MovePlayer(right, left, up, down, map.map, map.totalColumns, map.totalRows);
		enemy.MoveEnemies(map.map, right, left, up, down);
		map.ActualizeMap(player.pos, player.initialPos, player.character, enemy.enemyList, enemy.enemyNumber);
		std::cout << "SCORE: " << player.score;
		player.CalculateHealth(enemy.enemyList, enemy.enemyNumber);

		//Pausar el joc
		while (pause) {
			key.GetKeys(right, left, up, down, escape, startPause, quitPause);
			if (quitPause || escape) {
				pause = false;

			}

		}

		//Game Over
		while (gameOver) {
			key.GetKeys(right, left, up, down, escape, startPause, quitPause);
			if (escape) {
				gameOver = false;

			}

		}

		//Esperar i borrar mapa anterior
		Sleep(speed);
		system("cls");

		//Sortir del joc
		if (escape) {
			endGame = true;

		}

	}

	return 0;
}