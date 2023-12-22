// Structs
#include "Field.h"
#include "Snake.h"
#include "Apple.h"
#include "Trail.h"
#include "HUD.h"

// Other things
#include "SnakeField.h"
#include "Printer.h"
#include "Input.h"

#include <windows.h>

int main() {
	// The Field that the snake slithers in //
	struct Field field;	
	field_create(&field, 16, 16);

	// The apple //
	struct Apple apple;
	apple_generate(&field, &apple);

	// The Snake in question //
	struct Snake snake;
	snake_create(&snake, SNAKE_DEFAULT_LENGTH);
	snake_set_position(&field, &snake);

	// The HUD
	struct HUD hud;
	hud_init(&hud, &snake.size);
	file_read(FILE_SCORE, &hud);

	struct Trail trail;
	trail_init(&field, &trail);

	while (true) {
		field_print(&field, &snake, &apple, &trail);
		// Buffer so snake doesn't die instantly
		Sleep(100);
		// Get movement from user
		enum Direction movement = input_get();
		// If the movement isn't null
		if (movement != 0) {
			snake.direction = movement;
		}

		// Clear the field
		field_clear();

		////// DRAW HUD ELEMENTS HERE //////

		hud_drawTop(&hud);

		////////////////////////////////////

		// If the snake is going to eat the apple
		if (snake.body[0] == apple.pos) {
			apple_generate(&field, &apple);
			snake_extend(&snake);
		}

		if (!snake_update(&field, &snake, &trail)) {
			// Check if new high score
			hud_check(&hud);
			// Blah blah blah
			snake_create(&snake, SNAKE_DEFAULT_LENGTH);
			snake_set_position(&field, &snake);
			// Generate a new apple
			apple_generate(&field, &apple);
		}
	}

	free(snake.body);
}