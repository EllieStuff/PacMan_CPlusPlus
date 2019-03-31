//Control i l�gica del jugador

#include "Player.h"

void Player::InitializePlayer(int totalRows, int totalColumns, char** map) {
	//Mira si la posici� inicial del jugador est� en un punt en que es pugui moure en almenys dos direccions en la 
	//part inferior del mapa de forma centrica. En cas que no pugui, anir� buscant una posici� v�lida per tot el
	//mapa i, de no trobar-la, enviar� un error de que no existeix una posici� v�lida per a assignar al jugador.
	character = '>';
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

		if (possibleWays > 1 && (map[pos.x][pos.y] == '*' || map[pos.x][pos.y] == ' ')) {
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
				std::cout << "\nERROR, THERE IS NO VALID START POINT.\nPLEASE, CREATE A VALID START POINT.";
				break;

			}
		}
	}

}

void Player::MovePlayer(bool right, bool left, bool up, bool down, char** map, int columns, int rows) {
	initialPos = pos;

	//Actualitza la posici� del jugador
	if (right) {
		if (pos.y == columns - 1 && map[pos.x][0] != 'X') {
			pos.y = 0;

		}
		else if (pos.y == columns - 1 && map[pos.x][0] == 'X') {
			//En aquest cas no vull que faci res

		}
		else {
			pos.y++;
			CalculateScore(map);

		}

		character = '<';

	}
	else if (left) {
		if (pos.y == 0 && map[pos.x][columns - 1] != 'X') {
			pos.y = columns - 1;

		}
		else if (pos.y == 0 && map[pos.x][columns - 1] == 'X') {
			//En aquest cas no vull que faci res

		}
		else {
			pos.y--;
			CalculateScore(map);

		}

		character = '>';


	}
	else if (up) {
		if (pos.x == rows - 1 && map[0][pos.y] != 'X') {
			pos.x = 0;

		}
		else if (pos.x == rows - 1 && map[0][pos.y] == 'X') {
			//En aquest cas no vull que faci res

		}
		else {
			pos.x--;
			CalculateScore(map);

		}

		character = 'v';

	}
	else if (down) {
		if (pos.x == 0 && map[rows - 1][pos.y] != 'X') {
			pos.x = 0;

		}
		else if (pos.x == 0 && map[rows - 1][pos.y] == 'X') {
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
