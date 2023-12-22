#pragma once

#define FIELD_WALL '#'
#define FIELD_EMPTY ' '

#define FIELD_MAX_HEIGHT 16
#define FIELD_MAX_LENGTH 16

enum FieldGrid {
	FIELDGRID_EMPTY = 0,
	FIELDGRID_WALL
};

struct Field {
	// Length and Height of the Board
	unsigned int height, length;

	// The String of the field
	enum FieldGrid* board;
};

void field_create(struct Field* field, unsigned int height, unsigned int length);