/*
** EPITECH PROJECT, 2021
** runner - create.c
** File description:
** jitter jitter
*/

#include "../../include/my_event.h"

track_actions_t on_event2(sfEvent event, track_actions_t actions)
{
    if (event.type == sfEvtMouseMoved) {
        actions.mouse = get_pos(event, actions.mouse);
        actions = is_in_box1(event, actions);
        actions = is_in_box2(event, actions);
        actions = is_in_box4(event, actions);
        actions = is_in_box_restart(event, actions);
    }
    return actions;
}

track_actions_t on_event(sfEvent event, track_actions_t actions)
{
    if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyReleased &&
         (event.key.code == sfKeyQ || event.key.code == sfKeyEscape))) {
        sfRenderWindow_close(actions.window);
    } else if (event.type == sfEvtKeyPressed) {
        actions = on_keydown(event, actions);
    } else {
        actions = on_event2(event, actions);
    }
    return actions;
}