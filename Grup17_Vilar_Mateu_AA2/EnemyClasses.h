#pragma once
//#include "Enemies.h"
/*
class Blinky {
public:
	void Move(Enemy* enemyList, char** map, int i) {
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

};


class Inky {
private:
	enum class InputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_PAUSE, K_SPACE, COUNT };

public:
	void Move(Enemy enemyList[], char ** map, int i, bool keyboard[])
	{
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		if (keyboard[(int)InputKey::K_RIGHT] && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.y++;

		}
		else if (keyboard[(int)InputKey::K_LEFT] && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.y--;

		}
		else if (keyboard[(int)InputKey::K_UP] && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.x--;

		}
		else if (keyboard[(int)InputKey::K_DOWN] && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.x++;

		}

		if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '&') {
			enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

		}

	}

};

class Clyde {
private:
	enum class InputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_PAUSE, K_SPACE, COUNT };

public:
	void Move(Enemy enemyList[], char ** map, int i, bool keyboard[])
	{
		if (enemyList[i].overlapSymbol == '<' || enemyList[i].overlapSymbol == '>' || enemyList[i].overlapSymbol == 'v' || enemyList[i].overlapSymbol == '^') {
			enemyList[i].overlapSave = ' ';

		}
		else {
			enemyList[i].overlapSave = enemyList[i].overlapSymbol;

		}

		if (keyboard[(int)InputKey::K_RIGHT] && map[enemyList[i].pos.x][enemyList[i].pos.y - 1] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.y--;

		}
		else if (keyboard[(int)InputKey::K_LEFT] && map[enemyList[i].pos.x][enemyList[i].pos.y + 1] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.y++;

		}
		else if (keyboard[(int)InputKey::K_UP] && map[enemyList[i].pos.x + 1][enemyList[i].pos.y] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.x++;

		}
		else if (keyboard[(int)InputKey::K_DOWN] && map[enemyList[i].pos.x - 1][enemyList[i].pos.y] != (char)219) {
			enemyList[i].initialPos = enemyList[i].pos;
			enemyList[i].pos.x--;

		}

		if (map[enemyList[i].pos.x][enemyList[i].pos.y] != '$') {
			enemyList[i].overlapSymbol = map[enemyList[i].pos.x][enemyList[i].pos.y];

		}

	}

};
*/
