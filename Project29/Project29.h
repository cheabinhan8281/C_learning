#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>

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

void save_score(const SCORE* scores, size_t count);
size_t load_score(SCORE** ppScores);

void show_menu();
char select_menu();
char get_grade(float avg);
void wait();


void print_scores(const SCORE* pScores, size_t count);
size_t input_score(SCORE** ppScores, size_t count);

int find_score(SCORE* pScores, size_t count, uint number);
void select_update(SCORE* pScores, size_t count);




