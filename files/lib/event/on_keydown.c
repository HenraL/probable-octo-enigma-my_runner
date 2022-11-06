/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** on_keydown.c
*/

#include "../../include/my_event.h"

track_actions_t on_keydown_of4(sfEvent event, track_actions_t actions)
{
    if (event.key.code == sfKeyR && actions.in_game != 2) {
        actions.in_game = 2;
    } else if (event.key.code == sfKeyH && actions.in_game == 1) {
        actions.in_game = 5;
    } else {
        actions = on_keydown_of5(event, actions);
    }
    return actions;
}

track_actions_t on_keydown_of3(sfEvent event, track_actions_t actions)
{
    if ((event.key.code == sfKeyA || event.key.code == sfKeyB ||
         event.key.code == sfKeyC)
        && actions.silver.d.y == actions.silver.position.y) {
        actions.silver.d.y = 50;
    } else if (event.key.code == sfKeyM) {
        actions.in_game = 1;
        actions.reset_scores = 1;
    } else {
        actions = on_keydown_of4(event, actions);
    }
    return actions;
}

track_actions_t on_keydown_of2(sfEvent event, track_actions_t actions)
{
    if (event.key.code == sfKeyDown &&
        actions.silver.d.y < actions.max_height - 266) {
        actions.silver.d.y += actions.silver.y_step / 4;
    } else if (event.key.code == sfKeySpace || event.key.code == sfKeyS ||
               event.key.code == sfKeyEnter) {
        actions.reset_scores = 1;
        actions.in_game = 2;
    } else {
        actions = on_keydown_of3(event, actions);
    }
    return actions;
}

track_actions_t on_keydown_overflow1(sfEvent event, track_actions_t actions)
{
    if (event.key.code == sfKeyUp && actions.silver.d.y > 50 &&
        actions.silver.d.y > 550) {
        actions.silver.d.y -= actions.silver.y_step / 2;
    } else if (((event.key.code == sfKeyRight || event.key.code == sfKeyLeft) &&
                event.key.code == sfKeyDown) && actions.sprint == sfFalse) {
        actions.sprint = sfTrue;
        actions.global_speed += 5;
    } else {
        actions = on_keydown_of2(event, actions);
    }
    return actions;
}

track_actions_t on_keydown(sfEvent event, track_actions_t actions)
{
    actions.reset_scores = 0;
    if (event.key.code == sfKeyLeft && actions.silver.d.x > 0) {
        actions.silver.d.x -= actions.silver.x_step / 2;
    } else if (event.key.code == sfKeyRight && actions.silver.d.x
               < actions.max_width - 100) {
        actions.silver.d.x += actions.silver.x_step / 2;
    } else {
        actions = on_keydown_overflow1(event, actions);
    }
    return actions;
}
