/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** init.C
*/

#include "../../include/my_scores.h"

score_t initialise_score(int nb)
{
    score_t score;
    score.enemies = nb;
    score.rings = nb;
    score.time = nb;
    score.total = nb;
    return score;
}