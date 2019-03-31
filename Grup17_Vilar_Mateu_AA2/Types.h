//Definici� de tipus globals
#pragma once

#include "Constants.h"
#include "Windows.h"

struct Position {
	int x;
	int y;

};

struct Keys {
	void GetKeys(bool &right, bool &left, bool &up, bool &down) {
		right = GetAsyncKeyState(VK_RIGHT);
		left = GetAsyncKeyState(VK_LEFT);
		up = GetAsyncKeyState(VK_UP);
		down = GetAsyncKeyState(VK_DOWN);

	}

};