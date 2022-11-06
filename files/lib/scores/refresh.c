/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** refresh.c
*/

#include "../../include/my_scores.h"

score_t refresh_scores(score_t score)
{
    score.time++;
    score.total = score.time + score.rings + score.enemies;
    return score;
}