#pragma once

#include "Field.h"
#include "Snake.h"
#include "Trail.h"
#include "Apple.h"

void field_print(const struct Field* const field, const struct Snake* const snake, const struct Apple* const apple, const struct Trail* const trail);
void field_clear();