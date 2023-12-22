#include "HUD.h"

#include "Printer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void hud_new_highscore(struct HUD* hud) {
	char* newName = malloc((NAME_SIZE + 1) * sizeof(char));

	field_clear();

	printf("Sorry about this text below, please click enter to continue.\n");
	char* buffer = malloc(256*sizeof(char));
	scanf_s("%s", buffer, 256 * sizeof(char));
	free(buffer);

	printf("Congrats! You beat the previous score by %s!\n", hud->name);
	printf("Put in a name for your name to be at the top: ");
	scanf_s("%s", newName, NAME_SIZE);

	strcpy_s(hud->name, NAME_SIZE * sizeof(char), newName);
	hud->highScore = *hud->currentScore;

	printf("");

	free(newName);
}

void hud_check(struct HUD* hud) {
	if (*hud->currentScore > hud->highScore) {
		hud_new_highscore(hud);
		file_write(FILE_SCORE, hud);
	}
}

void hud_init(struct HUD* hud, unsigned int* score) {
	hud->currentScore = score;
	hud->highScore = 256;
	strcpy_s(hud->name, (NAME_SIZE + 1) * sizeof(char), "........");
}

void hud_drawTop(struct HUD* hud) {
	printf("Current %u - High Score: %u (%s)\n", *(hud->currentScore), hud->highScore, hud->name);
}

void file_read(const char* file, struct HUD* hud) {
	// Open file
	FILE* f = fopen(file, "r");
	// Save to HUD
	char name[NAME_SIZE + 1] = "........";
	fscanf(f, "%s %u", name, &hud->highScore);

	strcpy_s(hud->name, (NAME_SIZE+1)*sizeof(char), name);
	printf("%s, %u", name, hud->highScore);
	// Close file
	fclose(f);
}

void file_write(const char* file, const struct HUD* const hud) {
	// Open file
	FILE* f = NULL;
	errno_t err = fopen_s(&f, file, "w");
	if (err != 0) {
		return;
	}
	// Save to HUD
	fprintf_s(f, "%s %u", hud->name, hud->highScore);
	// Close file
	fclose(f);
}