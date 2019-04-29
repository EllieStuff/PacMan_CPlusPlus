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
			if (map[i][j] != 'X' && map[i][j] != '*' && map[i][j] != ' ') {
				enemyNumber++;
				Resize(enemyNumber);
				enemyList[enemyNumber - 1].intialPos.x = i;
				enemyList[enemyNumber - 1].intialPos.y = j;
				enemyList[enemyNumber - 1].pos = enemyList[enemyNumber - 1].intialPos;

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
					break;

				}

			}

		}

	}

}

void Enemy::MoveEnemies(char ** map)
{
	for (int i = 0; i < enemyNumber; i++) {
		switch (enemyList[i].id) {
		case 0:	//El Blinky es mou de forma random, però mai cap endarrere
			DecideBlinkyPosition(map, i);

			break;

		case 1: //El Inky es mou seguint els Inputs del teclat

			break;

		case 2: //El Clyde es mou seguint l'inversa dels Inputs del teclat

			break;

		default:
			break;

		}

	}

				
}

void Enemy::DecideBlinkyPosition(char ** map, int i)
{
	int random = rand() % 3;
	bool canMove = false;

	if (enemyList[i].intialPos.y < enemyList[i].pos.y) {
		int counter = 0;
		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.y][enemyList[i].pos.x + 1] != 'X') {
					canMove = true;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.y + 1][enemyList[i].pos.x] != 'X') {
					canMove = true;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.y][enemyList[i].pos.x - 1] != 'X') {
					canMove = true;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;
				break;

			}

			if (counter > 2) {

				break;
			}

		}

	}
	else if (enemyList[i].intialPos.y > enemyList[i].pos.y) {
		int counter = 0;
		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.y][enemyList[i].pos.x - 1] != 'X') {
					canMove = true;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.y - 1][enemyList[i].pos.x] != 'X') {
					canMove = true;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.y][enemyList[i].pos.x + 1] != 'X') {
					canMove = true;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;
				break;

			}

			if (counter > 2) {

				break;
			}

		}

	}
	else if (enemyList[i].intialPos.x < enemyList[i].pos.x) {
		int counter = 0;
		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.y - 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y--;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.y][enemyList[i].pos.x + 1] != 'X') {
					canMove = true;
					enemyList[i].pos.x++;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.y + 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y++;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;
				break;

			}

			if (counter > 2) {

				break;
			}

		}
	}
	else if (enemyList[i].intialPos.x > enemyList[i].pos.x) {
		int counter = 0;
		while (!canMove) {
			switch (random) {
			case 0: //His Left
				if (map[enemyList[i].pos.y + 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y++;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //His towards
				if (map[enemyList[i].pos.y][enemyList[i].pos.x - 1] != 'X') {
					canMove = true;
					enemyList[i].pos.x--;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //His Right
				if (map[enemyList[i].pos.y - 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y--;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;
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
		while (!canMove) {
			switch (random) {
			case 0: //Right
				if (map[enemyList[i].pos.y + 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y++;

				}
				else {
					random = 1;
					counter++;

				}

				break;

			case 1: //Left
				if (map[enemyList[i].pos.y - 1][enemyList[i].pos.x] != 'X') {
					canMove = true;
					enemyList[i].pos.y--;

				}
				else {
					random = 2;
					counter++;

				}

				break;

			case 2: //Up
				if (map[enemyList[i].pos.y][enemyList[i].pos.x - 1] != 'X') {
					canMove = true;
					enemyList[i].pos.x--;

				}
				else {
					random = 3;
					counter++;

				}

				break;

			case 3: //Down
				if (map[enemyList[i].pos.y][enemyList[i].pos.x + 1] != 'X') {
					canMove = true;
					enemyList[i].pos.x++;

				}
				else {
					random = 0;
					counter++;

				}

				break;

			default:
				break;
				break;

			}

			if (counter > 3) {

				break;
			}

		}
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
