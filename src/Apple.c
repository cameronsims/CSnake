#include "Apple.h"

#include <stdlib.h>
#include <time.h>

void apple_set(const struct Field* const field, struct Apple* apple, unsigned int x, unsigned int y) {
	apple->pos = x + (field->length * y);
}

void apple_generate(const struct Field* const field, struct Apple* const apple) {
	// Generate the seed
	const time_t seed = time(NULL) * field->length * field->height;
	srand(seed);

	// Coordinates
	unsigned int x = 0, y = 0;

	const unsigned int xFlr = 2,
					   xCiel = field->length - 2,
					   yFlr = 2,
					   yCiel = field->height - 2;

	x = (rand() % (field->length - 2) + 1);
	y = (rand() % (field->height - 2) + 1);

	apple_set(field, apple, x, y);
}