#include "Enemies.h"

enum class InputKeyEnemies { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, COUNT };

Enemy::Enemy()
{
	enemyNumber = 0;
	enemyList = new Enemy[enemyNumber];

}

void Enemy::SearchEnemies(char ** map, int maxRows, int maxColumns)
{
	for (int i = 0; i < maxRows; i++) {
		for (int j = 0; j < maxColumns; j++) {
			if (map[i][j] != 'X' && map[i][j] != '*' && map[i][j] != ' ' && map[i][j] != '>') {
				enemyNumber++;
				Resize(enemyNumber);
				enemyList[enemyNumber - 1].initialPos.x = i;
				enemyList[enemyNumber - 1].initialPos.y = j;
				enemyList[enemyNumber - 1].pos = enemyList[enemyNumber - 1].initialPos;
				enemyList[enemyNumber - 1].firstPos = enemyList[enemyNumber - 1].initialPos;
				enemyList[enemyNumber - 1].overlapSymbol = ' ';

				switch (map[i][j]) {
				case '#':
					enemyList[enemyNumber - 1].id = 0;

					break;

				case '&':
					enemyList[enemyNumber - 1].id = 1;

					break;

				case '$':
					enemyList[enemyNumber - 1].id = 2;

					break;

				default:
					enemyList[enemyNumber - 1].id = -1;
					break;

				}

			}

		}

	}

}

void Enemy::MoveEnemies(char ** map, bool keyboard[], int columns, int rows)
{
	for (int i = 0; i < enemyNumber; i++) {
		switch (enemyList[i].id) {
		case 0:	//El Blinky es mou de forma random, però mai cap endarrere
			MoveBlinky(map, i);

			break;

		case 1: //El Inky es mou seguint els Inputs del teclat
			MoveInky(map, i, keyboard);

			break;

		case 2: //El Clyde es mou seguint l'inversa dels Inputs del teclat
			MoveClyde(map, i, keyboard);

			break;

		default:
			break;

		}
		CheckTP(map, i, columns, rows);

	}


}

void Enemy::ReinitEnemies(char ** map)
{
	for (int i = 0; i < enemyNumber; i++) {
		map[pos.x][pos.y] = overlapSymbol;
		enemyList[i].pos = enemyList[i].firstPos;
		enemyList[i].initialPos = enemyList[i].firstPos;
		overlapSymbol = ' ';
		overlapSave = ' ';

	}

}


void Enemy::MoveBlinky(char ** map, int i)
{
	int random = rand() % 3;
	bool canMove = false;

	if (enemyList[i].initialPos.y < enemyList[i].pos.y) {
		int counter = 0;
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;

			}

			if (counter > 2) {

				break;
			}

		}

	}
	else if (enemyList[i].initialPos.y > enemyList[i].pos.y) {
		int counter = 0;
		while (!canMove) {
			if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
				enemyList[i].overlapSave = ' ';

			}
			else {
				enemyList[i].overlapSave = enemyList[i].overlapSymbol;

			}

			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];


				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;

			}

			if (counter > 2) {

				break;
			}

		}

	}
	else if (enemyList[i].initialPos.x < enemyList[i].pos.x) {
		int counter = 0;
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;

			}

			if (counter > 2) {
				enemyList[i].initialPos = enemyList[i].pos;

				break;
			}

		}
	}
	else if (enemyList[i].initialPos.x > enemyList[i].pos.x) {
		int counter = 0;
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
					canMove = true;
					map[enemyList[i].pos.x][enemyList[i].pos.y] = enemyList[i].overlapSymbol;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y++;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
					canMove = true;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y--;
					enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;

			}

			if (counter > 2) {

				break;
			}

		}
	}
	else {
		random = rand() % 4;
		int counter = 0;
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		while (!canMove) {
			switch (random) {
			case 0: //Right
				if (map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
					canMove = true;
					map[enemyList[i].pos.x][enemyList[i].pos.y] = enemyList[i].overlapSymbol;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y++;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //Left
				if (map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
					canMove = true;
					map[enemyList[i].pos.x][enemyList[i].pos.y] = enemyList[i].overlapSymbol;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.y--;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //Up
				if (map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					map[enemyList[i].pos.x][enemyList[i].pos.y] = enemyList[i].overlapSymbol;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x--;

				}
				else {
					random = 3;
					counter++;

				}

				break;

			case 3: //Down
				if (map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
					canMove = true;
					map[enemyList[i].pos.x][enemyList[i].pos.y] = enemyList[i].overlapSymbol;
					enemyList[i].initialPos = enemyList[i].pos;
					enemyList[i].pos.x++;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;

			}

			if (counter > 3) {

				break;
			}

		}

	}

}

void Enemy::MoveInky(char ** map, int i, bool keyboard[])
{
	if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
		enemyList[i].overlapSave = ' ';

	}
	else {
		enemyList[i].overlapSave = enemyList[i].overlapSymbol;

	}

	if (keyboard[(int)InputKeyEnemies::K_RIGHT] && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y++;

	}
	else if (keyboard[(int)InputKeyEnemies::K_LEFT] && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y--;

	}
	else if (keyboard[(int)InputKeyEnemies::K_UP] && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x--;

	}
	else if (keyboard[(int)InputKeyEnemies::K_DOWN] && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x++;

	}

	if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '&') {
		enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

	}

}

void Enemy::MoveClyde(char ** map, int i, bool keyboard[])
{
	if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
		enemyList[i].overlapSave = ' ';

	}
	else {
		enemyList[i].overlapSave = enemyList[i].overlapSymbol;

	}

	if (keyboard[(int)InputKeyEnemies::K_RIGHT] && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y--;

	}
	else if (keyboard[(int)InputKeyEnemies::K_LEFT] && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y++;

	}
	else if (keyboard[(int)InputKeyEnemies::K_UP] && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x++;

	}
	else if (keyboard[(int)InputKeyEnemies::K_DOWN] && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x--;

	}

	if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '$') {
		enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

	}

}

void Enemy::CheckTP(char ** map, int i, int columns, int rows)
{
	char character = '-';
	if (enemyList[i].id == 0) character = '#';
	else if (enemyList[i].id == 1) character = '&';
	else if (enemyList[i].id == 2) character = '$';

	if (pos.x > columns - 1) {
		map[enemyList[i].pos.x][enemyList[i].pos.y] = ' ';
		if (map[0][enemyList[i].pos.y] != (char)219) {
			enemyList[i].pos.x = 0;
			if (enemyList[i].id == 0) initialPos.x = -1;
		}
		else enemyList[i].pos.x = columns - 1;

		map[enemyList[i].pos.x][enemyList[i].pos.y] = character;

	}
	else if (enemyList[i].pos.x < 0) {
		map[enemyList[i].pos.x][enemyList[i].pos.y] = ' ';
		if (map[columns - 1][enemyList[i].pos.y] != (char)219) {
			enemyList[i].pos.x = columns - 1;
			if (enemyList[i].id == 0) initialPos.x = columns - 2;
		}
		else enemyList[i].pos.x = 0;

		map[enemyList[i].pos.x][enemyList[i].pos.y] = character;

	}
	else if (enemyList[i].pos.y > rows - 1) {
		map[enemyList[i].pos.x][enemyList[i].pos.y] = ' ';
		if (map[enemyList[i].pos.x][0] != (char)219) {
			enemyList[i].pos.y = 0;
			if (enemyList[i].id == 0) initialPos.y = -1;
		}
		else enemyList[i].pos.y = rows - 1;

		map[enemyList[i].pos.x][enemyList[i].pos.y] = character;

	}
	else if (enemyList[i].pos.y < 0) {
		map[enemyList[i].pos.x][enemyList[i].pos.y] = ' ';
		if (map[enemyList[i].pos.x][rows - 1] != (char)219) {
			enemyList[i].pos.y = rows - 1;
			if (enemyList[i].id == 0) initialPos.y = rows - 2;
		}
		else enemyList[i].pos.y = rows - 1;

		map[enemyList[i].pos.x][enemyList[i].pos.y] = character;

	}

}

void Enemy::Resize(int newSize)
{
	Enemy* tmpList;
	tmpList = new Enemy[newSize];
	for (int i = 0; i < newSize && i < enemyNumber; i++) {
		tmpList[i] = enemyList[i];

	}
	enemyList = tmpList;

}
