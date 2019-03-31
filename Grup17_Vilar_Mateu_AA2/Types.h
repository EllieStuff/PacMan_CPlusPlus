//Definició de tipus globals
#pragma once

#include "Constants.h"
#include "Windows.h"

struct Position {
	int x;
	int y;

};

struct Keys {
	void GetKeys(bool &right, bool &left, bool &up, bool &down, bool &escape) {
		right = GetAsyncKeyState(VK_RIGHT);
		left = GetAsyncKeyState(VK_LEFT);
		up = GetAsyncKeyState(VK_UP);
		down = GetAsyncKeyState(VK_DOWN);
		escape = GetAsyncKeyState(VK_ESCAPE);

	}

};