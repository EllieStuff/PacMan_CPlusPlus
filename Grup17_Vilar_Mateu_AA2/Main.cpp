//GameLoop

#include "Map.h"
#include "Player.h"
#include "Types.h"
#include "Enemies.h"
#include <time.h>
#include "Ranking.h"

enum class InputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_PAUSE, K_SPACE, K_ZERO, K_ONE, K_TWO, COUNT};
enum class GameState {SPLASH_SCREEN, MAIN_MENU, GAME, RANKING, EXIT};

//TODO: 1. Ranking (llegir dades actuals), 2. PowerUps i 3. Revisar EnemyClasses.h i borrar-lo en casque doni masses problemes
int main() {
	srand(NULL(time));
	time_t start = clock();
	bool keyboard[(int)InputKey::COUNT] = {};
	GameState myGameState = GameState::SPLASH_SCREEN;
	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	Map map;
	Player player;
	Enemy enemy;
	Keys key;
	Ranking ranking;
	bool pause = false;
	bool init = false;
	bool gameOver = false;
	int speed = 400;
	const int DELAY = 1000;

	//Inicialitzar mapa
	map.ReadMap();
	enemy.SearchEnemies(map.map, map.totalRows, map.totalColumns);

	//Inicialitzar jugador
	player.InitializePlayer(map.totalRows, map.totalColumns, map.map);
	player.CalculateScore(map.map);

	//Inicialitzar ranking
	ranking.InitializeRanking();


	//Game Loop
	while (myGameState != GameState::EXIT || gameOver) {
		switch (myGameState) {
		case GameState::SPLASH_SCREEN:
			map.WriteSplashScreen("");
			Sleep(DELAY);
			system("cls");
			map.WriteSplashScreen("  ");
			Sleep(DELAY);
			system("cls");
			map.WriteSplashScreen("    ");
			Sleep(DELAY);
			system("cls");
			myGameState = GameState::MAIN_MENU;

			break;

		case GameState::MAIN_MENU:
			map.WriteMainMenu();
			while (true) {
				key.GetKeys(keyboard);
				if (keyboard[static_cast<int>(InputKey::K_ONE)]) {
					myGameState = GameState::GAME;
					system("cls");
					break;

				}
				else if (keyboard[static_cast<int>(InputKey::K_TWO)]) {
					myGameState = GameState::RANKING;
					system("cls");
					break;

				}
				else if (keyboard[static_cast<int>(InputKey::K_ZERO)] || keyboard[static_cast<int>(InputKey::K_ESC)]) {
					myGameState = GameState::EXIT;
					system("cls");
					break;

				}


			}

			break;

		case GameState::GAME:
			SetConsoleTextAttribute(consoleColor, 224);

			//Controlador d'estats: Pause
			if (!init) {
				map.ReadMap();
				SetConsoleTextAttribute(consoleColor, 224);
				std::cout << "*-*-INIT-*-*" << std::endl;
				map.WriteMap(player.pos);
				std::cout << "SCORE: " << player.score;
				player.CalculateHealth(enemy.enemyList, enemy.enemyNumber, map.map, map.maxPoints);
				while (true) {
					key.GetKeys(keyboard);
					if (keyboard[static_cast<int>(InputKey::K_SPACE)]) {
						init = true;
						system("cls");
						SetConsoleTextAttribute(consoleColor, 224);
						std::cout << "*-*-PLAY-*-*" << std::endl;
						SetConsoleTextAttribute(consoleColor, 7);
						break;

					}
				}

			}
			else if (player.lives < 1 || map.maxPoints - 1 == player.score) {
				std::cout << "*-*-GAME OVER-*-*" << std::endl;
				SetConsoleTextAttribute(consoleColor, 7);
				std::cout << "Press escape to exit or space to see the ranking." << std::endl;
				map.ActualizeMap(player.pos, player.initialPos, player.character, enemy.enemyList, enemy.enemyNumber, player.hasPowerUp);
				while (true) {
					key.GetKeys(keyboard);
					if (keyboard[static_cast<int>(InputKey::K_SPACE)]) {
						init = false;
						enemy.ReinitEnemies(map.map);
						myGameState = GameState::RANKING;
						ranking.EnterInRanking(player.score);
						player.ReinitPlayer();
						break;

					}
					else if (keyboard[static_cast<int>(InputKey::K_ESC)]) {
						init = false;
						player.ReinitPlayer();
						enemy.ReinitEnemies(map.map);
						myGameState = GameState::MAIN_MENU;
						break;

					}

				}

			}
			else if (keyboard[static_cast<int>(InputKey::K_PAUSE)]) {
				std::cout << "*-*-PAUSE-*-*" << std::endl;
				SetConsoleTextAttribute(consoleColor, 7);
				std::cout << "Press space to continue." << std::endl;
				map.ActualizeMap(player.pos, player.initialPos, player.character, enemy.enemyList, enemy.enemyNumber, player.hasPowerUp);
				while (true) {
					key.GetKeys(keyboard);
					if (keyboard[static_cast<int>(InputKey::K_SPACE)]) {
						system("cls");
						SetConsoleTextAttribute(consoleColor, 224);
						std::cout << "*-*-PLAY-*-*" << std::endl;
						break;

					}
					else if (keyboard[static_cast<int>(InputKey::K_ESC)]) {
						myGameState = GameState::MAIN_MENU;
						system("cls");
						break;

					}

				}

			}
			else if (keyboard[static_cast<int>(InputKey::K_ESC)]) {
				init = false;
				player.ReinitPlayer();
				enemy.ReinitEnemies(map.map);
				myGameState = GameState::MAIN_MENU;

			}
			else {
				std::cout << "*-*-PLAY-*-*" << std::endl;

			}

			//Input
			key.GetKeys(keyboard);
			player.MovePlayer(keyboard, map.map, map.totalColumns, map.totalRows);
			player.ControlPowerUpState(start);

			if (myGameState != GameState::GAME) {
				SetConsoleTextAttribute(consoleColor, 7);

			}
			else {
				//Update
				enemy.MoveEnemies(map.map, keyboard, map.totalRows, map.totalColumns);
				//Update del mapa i Draw
				map.ActualizeMap(player.pos, player.initialPos, player.character, enemy.enemyList, enemy.enemyNumber, player.hasPowerUp);
				//Draw
				std::cout << "SCORE: " << player.score;
				player.CalculateHealth(enemy.enemyList, enemy.enemyNumber, map.map, map.maxPoints);

			}

			//Esperar i borrar mapa anterior
			Sleep(speed);
			system("cls");

			break;

		case GameState::RANKING:
			SetConsoleTextAttribute(consoleColor, 224);
			std::cout << "*-*-*-RANKING-*-*-*" << std::endl;
			SetConsoleTextAttribute(consoleColor, 7);
			ranking.PrintRanking();
			while (true) {
				key.GetKeys(keyboard);
				if (keyboard[static_cast<int>(InputKey::K_ESC)]) {
					myGameState = GameState::MAIN_MENU;
					system("cls");
					Sleep(speed);
					break;

				}

			}

			break;

		case GameState::EXIT:

			break;

		default:
			break;

		}


	}

	return 0;
}