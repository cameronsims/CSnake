#pragma once

#include "Field.h"

#define APPLE_ICON '@'

struct Apple {
	unsigned int pos;
};

void apple_set(const struct Field* const field, struct Apple* apple, unsigned int x, unsigned int y);
void apple_generate(const struct Field* const field, struct Apple* const apple);