#include "Printer.h"
#include "Field.h"
#include "Snake.h"
#include "Apple.h"
#include "Trail.h"

#include <stdio.h>
#include <stdint.h>
#include <windows.h>

void field_print(const struct Field* const field, const struct Snake* const snake, const struct Apple* const apple, const struct Trail* const trail) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	const unsigned int size = field->height * field->length;
	// For all parts of the field
	for (unsigned int i = 0; i < size; i++) {
		// The character to print
		char cell = FIELD_EMPTY;
		// If we should print the apple
		bool drawApple = apple->pos == i,
			 drawSnake = snake_atPos(snake, i);
		if (drawApple) {
			cell = APPLE_ICON;
		} else if (drawSnake) {
			cell = SNAKE_DEFAULT_BODY;
			if (snake->body[0] == i) {
				cell = SNAKE_DEFAULT_HEAD;
			}
		} else {
			cell = (field->board[i] == FIELDGRID_EMPTY) ? FIELD_EMPTY : FIELD_WALL;
		}
		// Change Colour
		int8_t clr = 0x10*(15 - trail->path[i]) + 0x1*trail->path[i];
		SetConsoleTextAttribute(console, clr);
		// Print the character in location
		printf("%c", cell);

		SetConsoleTextAttribute(console, 0x0F);

		printf("%c", ((i + 1) % field->length == 0) ? '\n' : ' ');
	}
}

void field_clear() {
	// The top right of the screen
	const COORD origin = { 0, 0 };
	// Get the window the console resides in
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	// The console's screen
	CONSOLE_SCREEN_BUFFER_INFO screen;
	// Other data
	DWORD data;

	GetConsoleScreenBufferInfo(console, &screen);

	const WORD colours = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;// Reset colours
	const DWORD size = screen.dwSize.X * screen.dwSize.Y;

	FillConsoleOutputCharacterA(console, ' ', size, origin, &data);
	FillConsoleOutputAttribute(console, colours, size, origin, &data);
	SetConsoleCursorPosition(console, origin);
}