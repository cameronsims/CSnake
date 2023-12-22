#pragma once

#include "Field.h"

enum Colours {
	BLACK = 0,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LGRAY,
	DGRAY,
	LBLUE,
	LGREEN,
	LCYAN,
	LRED,
	LMAGENTA,
	YELLOW,
	WHITE
};

struct Trail {
	enum Colours* path;
};

void trail_init(const struct Field* const field, struct Trail* trail);