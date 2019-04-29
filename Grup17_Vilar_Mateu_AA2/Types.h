//Definició de tipus globals
#pragma once

#include "Constants.h"
#include "Windows.h"

struct Position {
	int x;
	int y;

};

class Keys {
public:
	void GetKeys(bool &right, bool &left, bool &up, bool &down, bool &escape, bool &startPause, bool &quitPause) {
		right = GetAsyncKeyState(VK_RIGHT);
		left = GetAsyncKeyState(VK_LEFT);
		up = GetAsyncKeyState(VK_UP);
		down = GetAsyncKeyState(VK_DOWN);
		escape = GetAsyncKeyState(VK_ESCAPE);
		startPause = GetAsyncKeyState(0x50);
		quitPause = GetAsyncKeyState(' ');

	}

};