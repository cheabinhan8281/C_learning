#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_NAME 20
#define FILENAME "score.dat"

typedef unsigned int uint;
typedef struct {
	uint number;
	char name[MAX_NAME];
	uint kor;
	uint eng;
	uint math;
	uint total;
	float avg;
	char grade;
	uint rank;
}SCORE;

void save_score(const SCORE* score);
SCORE* load_score();
void show_menu();
char select_menu();


