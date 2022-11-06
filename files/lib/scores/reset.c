/*
** EPITECH PROJECT, 2021
** runner - reset.c
** File description:
** jitter jitter
*/

#include "../../include/my_scores.h"

score_t reset_scores(score_t score)
{
    score.enemies = 0;
    score.rings = 0;
    score.time = 0;
    score.total = 0;
    return score;
}