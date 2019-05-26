//Definició de tipus globals
#pragma once

#include "Constants.h"
#include "Windows.h"

struct Position {
public:
	int x;
	int y;

	bool Equal(Position otherPos) {
		if (x == otherPos.x && y == otherPos.y) {

			return true;
		}

		return false;
	}

};

class Keys {
public:
	void GetKeys(bool keyboard[]) {
		enum class newInputKey { K_ESC, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_PAUSE, K_SPACE, K_ZERO, K_ONE, K_TWO, COUNT };
		keyboard[(int)newInputKey::K_RIGHT] = GetAsyncKeyState(VK_RIGHT);
		keyboard[(int)newInputKey::K_LEFT] = GetAsyncKeyState(VK_LEFT);
		keyboard[(int)newInputKey::K_UP] = GetAsyncKeyState(VK_UP);
		keyboard[(int)newInputKey::K_DOWN] = GetAsyncKeyState(VK_DOWN);
		keyboard[(int)newInputKey::K_ESC] = GetAsyncKeyState(VK_ESCAPE);
		keyboard[(int)newInputKey::K_PAUSE] = GetAsyncKeyState(0x50);
		keyboard[(int)newInputKey::K_SPACE] = GetAsyncKeyState(' ');
		keyboard[(int)newInputKey::K_ZERO] = GetAsyncKeyState('0');
		keyboard[(int)newInputKey::K_ONE] = GetAsyncKeyState('1');
		keyboard[(int)newInputKey::K_TWO] = GetAsyncKeyState('2');


	}

};
