#pragma once

#define NAME_SIZE 8

#define FILE_SCORE "data/score.txt"

struct HUD {

	const unsigned int* currentScore;

	unsigned int highScore;
	char name[NAME_SIZE + 1];

};

void hud_new_highscore(struct HUD* hud);
void hud_check(struct HUD* hud);
void hud_init(struct HUD* hud, unsigned int* score);
void hud_drawTop(struct HUD* hud);


void file_read(const char* file, struct HUD* hud);

void file_write(const char* file, const struct HUD* const hud);