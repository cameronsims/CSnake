#include "Trail.h"

#include <stdlib.h>

void trail_init(const struct Field* const field, struct Trail* trail) {
	const unsigned int size = field->height * field->length;
	trail->path = malloc(sizeof(enum Colours) * size);
	for (unsigned int i = 0; i < size; i++) {
		trail->path[i] = BLACK;
	}
}