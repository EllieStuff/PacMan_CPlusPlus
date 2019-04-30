//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
#include "Enemies.h"
//#include "Types.h"
//#include "Constants.h"

//TODO: Ara que el Blinky ja esta fet, falta comprovar que les direccions a les que apunta siguin sempre random i correctes
int main() {
	Map map;
	Player player;
	Keys key;
	Enemy enemy;
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	bool endGame = false;
	bool pause = false;
	bool startPause = false;
	bool gameOver = false;
	int speed = 400;
	bool right, left, up, down, escape, quitPause;
	srand(NULL(time));

	//Inicialitzar mapa
	map.ReadMap();
	enemy.SearchEnemies(map.map, map.totalRows, map.totalColumns);

	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	player.CalculateScore(map.map);

	//Dibuixar mapa
	std::cout << " *-*-INIT-*-*" << std::endl << " Press space to start game." << std::endl;
	map.WriteMap(player.pos);
	std::cout << " SCORE: " << player.score << "		LIFES: ";
	SetConsoleTextAttribute(consoleColor, 6);
	for (int i = 0; i < player.lives; i++) {
		std::cout << (char)219 << ' ';

	}
	std::cout << std::endl;

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
			std::cout << " *-*-PAUSE-*-*" << std::endl << " Press space to continue." << std::endl;

		}
		else if (gameOver) {
			std::cout << " *-*-GAME OVER-*-*" << std::endl << " Press escape to exit." << std::endl;

		}
		else {
			std::cout << " *-*-PLAY-*-*" << std::endl;

		}

		if (player.lives < 1 || map.maxPoints == player.score) {
			gameOver = true;

		}

		//Actualitzar mapa
		key.GetKeys(right, left, up, down, escape, startPause, quitPause);
		player.MovePlayer(right, left, up, down, map.map, map.totalColumns, map.totalRows);
		enemy.MoveEnemies(map.map);
		player.CalculateHealth(enemy.enemyList, enemy.enemyNumber);
		map.ActualizeMap(player.pos, player.initialPos, player.character, enemy.enemyList, enemy.enemyNumber);
		std::cout << " SCORE: " << player.score << "		LIFES: ";
		SetConsoleTextAttribute(consoleColor, 6);
		for (int i = 0; i < player.lives; i++) {
			std::cout << (char)219 << ' ';

		}
		std::cout << std::endl;
		SetConsoleTextAttribute(consoleColor, 7);

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

	//return 0;
}