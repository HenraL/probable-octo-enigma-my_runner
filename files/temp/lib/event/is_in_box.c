/*
** EPITECH PROJECT, 2021
** runner - is_in_box.c
** File description:
** jitter jitter
*/

#include "../../include/my_event.h"


track_actions_t is_in_box1(sfEvent event, track_actions_t actions)
{
    sprite_t butt = actions.buttons.button1;
    if (is_mouse_in_square(actions.mouse, butt) == sfTrue) {
        butt.sprite_rect.left += butt.anim.step_w;
    } else {
        butt.sprite_rect.left -= butt.anim.step_w;
    }
    actions.buttons.button1 = butt;
    return actions;
}

track_actions_t is_in_box2(sfEvent event, track_actions_t actions)
{
    sprite_t butt = actions.buttons.button2;
    if (is_mouse_in_square(actions.mouse, butt) == sfTrue) {
        butt.sprite_rect.left += butt.anim.step_w;
    } else {
        butt.sprite_rect.left -= butt.anim.step_w;
    }
    actions.buttons.button2 = butt;
    return actions;

}

track_actions_t is_in_box3(sfEvent event, track_actions_t actions)
{
    sprite_t butt = actions.buttons.button3;
    if (is_mouse_in_square(actions.mouse, butt) == sfTrue) {
        butt.sprite_rect.left += butt.anim.step_w;
    } else {
        butt.sprite_rect.left -= butt.anim.step_w;
    }
    actions.buttons.button3 = butt;
    return actions;

}

track_actions_t is_in_box4(sfEvent event, track_actions_t actions)
{
    sprite_t butt = actions.buttons.button4;
    if (is_mouse_in_square(actions.mouse, butt) == sfTrue) {
        butt.sprite_rect.left += butt.anim.step_w;
    } else {
        butt.sprite_rect.left -= butt.anim.step_w;
    }
    actions.buttons.button4 = butt;
    return actions;

}

track_actions_t is_in_box_restart(sfEvent event, track_actions_t actions)
{
    sprite_t butt = actions.buttons.restart;
    if (is_mouse_in_square(actions.mouse, butt) == sfTrue) {
        butt.sprite_rect.left += butt.anim.step_w;
    } else {
        butt.sprite_rect.left -= butt.anim.step_w;
    }
    actions.buttons.restart = butt;
    return actions;

}