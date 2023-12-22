#include "Snake.h"

#include <stdlib.h>


void snake_new(struct Snake* snake, unsigned int size) {
	// Set the size of the snake to a certain size
	snake->size = size;
}

void snake_create(struct Snake* snake, unsigned int size) {
	snake_new(snake, size);
	// Set to a default direction
	snake->direction = MOVEMENT_UP;
}

void snake_reset(struct Snake* snake) {
	snake_create(snake, SNAKE_DEFAULT_LENGTH);
}


void snake_extend(struct Snake* snake) {
	// The body of the snake before resizing
	int oldBody[SNAKE_MAX_LENGTH];

	for (unsigned int i = 0; i < snake->size; i++) {
		oldBody[i] = snake->body[i];
	}
	
	// If we are not under the size limit
	if (snake->size < SNAKE_MAX_LENGTH) {
		// Increment the size
		snake->size++;

		// Reconstruct the snake
		snake_new(snake, snake->size);
		// Save the body to the old body
		snake_set_body(snake, oldBody);
	}
}

void snake_set_body(struct Snake* snake, unsigned int* const arr) {
	// Set the values to the old body
	for (unsigned int i = 0; i < snake->size; i++) {
		snake->body[i] = arr[i];
	}
}

bool snake_atPos(const struct Snake* const snake, unsigned int pos) {
	// Check if there is a body part here
	for (unsigned int i = 0; i < snake->size; i++) {
		if (snake->body[i] == pos) {
			return true;
		}
	}
	return false;
}