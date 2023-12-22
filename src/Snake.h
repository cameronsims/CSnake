#pragma once

#include <stdbool.h>

#define SNAKE_DEFAULT_LENGTH 2
#define SNAKE_MAX_LENGTH 64

#define SNAKE_DEFAULT_HEAD 'o'
#define SNAKE_DEFAULT_BODY '*'

// The Direction that the snake is going in
enum Direction {
	MOVEMENT_NULL = 0,
	MOVEMENT_UP,
	MOVEMENT_LEFT,
	MOVEMENT_RIGHT,
	MOVEMENT_DOWN
};

struct Snake {
	unsigned int body[SNAKE_MAX_LENGTH];	// The body of the snake
	unsigned int size;						// Length of the snake
	enum Direction direction;				// The Direction the snake is moving in
};

void snake_new(struct Snake* snake, unsigned int size);

void snake_create(struct Snake* snake, unsigned int size);

void snake_reset(struct Snake* snake);

void snake_extend(struct Snake* snake);

void snake_set_body(struct Snake* snake, unsigned int* const arr);

// CONST STUFF //

bool snake_atPos(const struct Snake* const snake, unsigned int pos);
