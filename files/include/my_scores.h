/*
** EPITECH PROJECT, 2021
** runner - my_scores.h
** File description:
** jitter jitter
*/

#ifndef MY_SCORES_H_
#define MY_SCORES_H_

#include "my_text.h"
#include "my_convert.h"

typedef struct score_s {
    int total;
    int time;
    int enemies;
    int rings;
} score_t;

score_t initialise_score(int nb);
score_t refresh_scores(score_t score);
score_t reset_scores(score_t score);

#endif