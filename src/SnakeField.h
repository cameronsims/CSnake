#pragma once

#include "Field.h"
#include "Snake.h"

int snake_update(struct Field* const field, struct Snake* snake, struct Trail* trail);

void snake_set_position(struct Field* const field, struct Snake* const snake);