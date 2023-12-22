#include "Input.h"

#include <windows.h>

// 0 = NULL, 1 = Up, 2 = Left, 3 = Right, 4 = Down
unsigned int input_get() {
	if (input_isDown('W')) { return 1; }
	if (input_isDown('A')) { return 2; }
	if (input_isDown('D')) { return 3; }
	if (input_isDown('S')) { return 4; }
	return 0;
}

bool input_isDown(char key) {
	return GetKeyState(key) & 0x8000;	// If key is down = true, otherwise false
}