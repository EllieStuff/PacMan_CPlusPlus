#include "Enemies.h"

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

void Enemy::MoveEnemies(char ** map, bool right, bool left, bool up, bool down)
{
	for (int i = 0; i < enemyNumber; i++) {
		switch (enemyList[i].id) {
		case 0:	//El Blinky es mou de forma random, per� mai cap endarrere
			MoveBlinky(map, i);

			break;

		case 1: //El Inky es mou seguint els Inputs del teclat
			MoveInky(map, i, right, left, up, down);

			break;

		case 2: //El Clyde es mou seguint l'inversa dels Inputs del teclat
			MoveClyde(map, i, right, left, up, down);

			break;

		default:
			break;

		}

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

void Enemy::MoveInky(char ** map, int i, bool right, bool left, bool up, bool down)
{
	if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
		enemyList[i].overlapSave = ' ';

	}
	else {
		enemyList[i].overlapSave = enemyList[i].overlapSymbol;

	}

	if (right && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y++;

	}
	else if (left && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y--;

	}
	else if (up && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x--;

	}
	else if (down && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x++;

	}

	if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '&') {
		enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

	}

}

void Enemy::MoveClyde(char ** map, int i, bool right, bool left, bool up, bool down)
{
	if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
		enemyList[i].overlapSave = ' ';

	}
	else {
		enemyList[i].overlapSave = enemyList[i].overlapSymbol;

	}

	if (right && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y--;

	}
	else if (left && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.y++;

	}
	else if (up && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x++;

	}
	else if (down && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
		enemyList[i].initialPos = enemyList[i].pos;
		enemyList[i].pos.x--;

	}

	if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '$') {
		enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

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
