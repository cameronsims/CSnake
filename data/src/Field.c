#include "Field.h"

#include <stdlib.h>

// Must call field_destroy after
void field_create(struct Field* field, unsigned int height, unsigned int length) {
	// Size of string
	const unsigned int size = (height * length);
	// Define the board...
	field->height = height;
	field->length = length;
	// Set to null reference at the end of the string
	field->board = malloc(sizeof(enum FieldGrid) * size);
	// For every position:
	for (unsigned int i = 0; i < size; i++) {
		field->board[i] = FIELDGRID_EMPTY;
		if (i < length ||					// IF we are on the top
			i > length * (height - 1) ||	// OR bottom
			i % length == 0 ||				// OR far-left
			(i+1) % length == 0				// OR far-right
		) {
			// Set the character to a wall
			field->board[i] = FIELDGRID_WALL;
		}
	}
}