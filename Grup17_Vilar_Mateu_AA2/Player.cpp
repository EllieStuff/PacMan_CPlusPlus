//Control i lògica del jugador

#include "Player.h"

void Player::InitializePlayer(int totalRows, int totalColumns, char** map) {
	//Primer mira si troba un jugador en el taulell i, en cas de fer-ho, assigna les dades alla on es trobi. En cas contrari, 
	//mira si la posició inicial del jugador està en un punt en que es pugui moure en almenys dos direccions en la part
	//inferior del mapa de forma centrica. En cas que no pugui, anirà buscant una posició vàlida per tot el mapa i, de no 
	//trobar-la, enviarà un error de que no existeix una posició vàlida per a assignar al jugador.
	character = '>';
	for (int i = 0; i < totalRows; i++) {
		for (int j = 0; j < totalColumns; j++) {
			if (map[i][j] == '>') {
				pos.x = i;
				pos.y = j;
				initialPos = pos;
				firstPos = pos;
				return;

			}

		}

	}

	int possibleWays = 0;
	bool validPoint = false;
	pos.x = 2 * totalRows / 3;
	pos.y = totalColumns / 2;
	initialPos = pos;

	while (!validPoint) {
		if (map[pos.x + 1][pos.y] == '*' || map[pos.x + 1][pos.y] == ' ') {
			possibleWays++;

		}
		if (map[pos.x - 1][pos.y] == '*' || map[pos.x - 1][pos.y] == ' ') {
			possibleWays++;

		}
		if (map[pos.x][pos.y + 1] == '*' || map[pos.x][pos.y + 1] == ' ') {
			possibleWays++;

		}
		if (map[pos.x][pos.y - 1] == '*' || map[pos.x][pos.y - 1] == ' ') {
			possibleWays++;

		}

		if (possibleWays > 1 && (map[pos.x][pos.y] == '*' || map[pos.x][pos.y] == ' ') && map[pos.x][pos.y] != '#' && map[pos.x][pos.y] != '&' && map[pos.x][pos.y] != '$') {
			firstPos = pos;
			validPoint = true;

		}
		else {
			possibleWays = 0;
			pos.x++;
			if (pos.x == totalColumns) {
				pos.x = 0;
				pos.y++;

				if (pos.y == totalRows) {
					pos.y = 0;

				}

			}
			else if (pos.x == initialPos.x && pos.y == initialPos.y) {

				return;
			}
		}
	}

}

void Player::MovePlayer(bool keyboard[], char** map, int columns, int rows) {
	enum class InputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_PAUSE, K_SPACE, COUNT };
	initialPos = pos;

	//Actualitza la posició del jugador
	if (keyboard[(int)InputKey::K_RIGHT]) {
		if (pos.y == columns - 1 && map[pos.x][0] != (char)219) {
			pos.y = 0;

		}
		else if (pos.y == columns - 1 && map[pos.x][0] == (char)219) {
			//En aquest cas no vull que faci res

		}
		else {
			pos.y++;
			CalculateScore(map);

		}

		character = '<';

	}
	else if (keyboard[(int)InputKey::K_LEFT]) {
		if (pos.y == 0 && map[pos.x][columns - 1] != (char)219) {
			pos.y = columns - 1;

		}
		else if (pos.y == 0 && map[pos.x][columns - 1] == (char)219) {
			//En aquest cas no vull que faci res

		}
		else {
			pos.y--;
			CalculateScore(map);

		}

		character = '>';


	}
	else if (keyboard[(int)InputKey::K_UP]) {
		if (pos.x == rows - 1 && map[0][pos.y] != (char)219) {
			pos.x = 0;

		}
		else if (pos.x == rows - 1 && map[0][pos.y] == (char)219) {
			//En aquest cas no vull que faci res

		}
		else {
			pos.x--;
			CalculateScore(map);

		}

		character = 'v';

	}
	else if (keyboard[(int)InputKey::K_DOWN]) {
		if (pos.x == 0 && map[rows - 1][pos.y] != (char)219) {
			pos.x = 0;

		}
		else if (pos.x == 0 && map[rows - 1][pos.y] == (char)219) {
			//En aquest cas no vull que faci res

		}
		else {
			pos.x++;
			CalculateScore(map);

		}

		character = '^';

	}

}

void Player::CalculateScore(char** map) {
	if (map[pos.x][pos.y] == '*') {
		score++;

	}

}

void Player::ReinitPos() {
	pos = firstPos;
	initialPos = firstPos;
	character = '>';

}
void Player::CalculateHealth(Enemy enemyList[], int enemyNum)
{
	for (int i = 0; i < enemyNum; i++) {
		if (enemyList[i].pos.Equal(pos) || (enemyList[i].initialPos.Equal(pos) && enemyList[i].pos.Equal(initialPos))) {
			lives--;
			ReinitPos();

		}

	}

	HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "		LIVES: ";
	SetConsoleTextAttribute(consoleColor, 6);
	for (int i = 0; i < lives; i++) {
		std::cout << (char)219 << ' ';

	}
	std::cout << std::endl;
	SetConsoleTextAttribute(consoleColor, 7);

}

void Player::ReinitPlayer()
{
	pos = firstPos;
	initialPos = firstPos;
	lives = INITIAL_LIVES;
	score = INITIAL_SCORE;
	character = '>';

}

