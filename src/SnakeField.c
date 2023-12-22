#include "SnakeField.h"

#include "Field.h"
#include "Snake.h"
#include "Trail.h"

#include <math.h>

int snake_update(struct Field* const field, struct Snake* snake, struct Trail* trail) {
	// UP, LEFT, RIGHT, DOWN
	const int mvntAmount[4] = { -(int)field->length, -1, 1, field->length};
	// Make a new array full of new values
	unsigned int newBody[SNAKE_MAX_LENGTH];
	// Set first value to new direction
	newBody[0] = snake->body[0] + mvntAmount[snake->direction - 1];		// 0 = NULL NOT UP!!!
	snake->body[snake->size - 1] = snake->body[snake->size - 2];

	trail->path[ newBody[0] ] = CYAN;

	// IF we hit a wall OR ourself
	if (newBody[0] < field->length || newBody[0] > (field->height - 1) * field->length ||	// Top || Bottom ||
		newBody[0] % field->length == 0 || (newBody[0] + 1) % field->length == 0 ||			// Left || Right ||
		snake_atPos(snake, newBody[0])														// Ourself
	) {
		return 0;
	}

	// Shift the values down 1
	for (unsigned int i = 1; i < snake->size; i++) {
		newBody[i] = snake->body[i - 1];
		unsigned int sizeColour = (snake->size % 16);
		trail->path[i] = (enum Colours)sizeColour;
	}
	// Set the new body to the snake
	snake_set_body(snake, newBody);

	return 1;
}

void snake_set_position(struct Field* const field, struct Snake* const snake) {
	snake->direction = MOVEMENT_UP;
	snake->body[0] = (int)floor((field->height * field->length) / 2) + (int)floor(field->length / 2);
	snake->body[1] = snake->body[0] + field->length;
}