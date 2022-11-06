/*
** EPITECH PROJECT, 2021
** get_csfml_keys - next_frame.c
** File description:
** jitter jitter
*/

#include "../../include/my_sprite.h"

sprite_t next_line(sprite_t default_sprite, time_t time)
{
    int wrap = default_sprite.anim.wrap;
    anim_t anim = default_sprite.anim;
    sfIntRect rect = default_sprite.sprite_rect;

    if ((rect.top >= anim.max_h || rect.top <= 0) && wrap == sfFalse) {
        anim.step_h *= -1;
    } else if ((rect.top >= anim.max_h || rect.top <= 0) && wrap == 1) {
        rect.top = 0;
    }
    rect.top += anim.step_h;
    sfSprite_setTextureRect(default_sprite.sprite, rect);
    default_sprite.sprite_rect = rect;
    default_sprite.anim = anim;
    return default_sprite;
}

sprite_t next_frame(sprite_t default_sprite, int time)
{
    int wrap = default_sprite.anim.wrap;
    anim_t anim = default_sprite.anim;
    sfIntRect rect = default_sprite.sprite_rect;

    if (time > anim.max_ticks) {
        if ((rect.left >= anim.max_w || rect.left <= 0) && wrap == sfFalse) {
            anim.step_w *= -1;
        } else if ((rect.left >= anim.max_w || rect.left <= 0) && wrap == 1) {
            rect.left = 0;
        }
        rect.left += anim.step_w;
        sfSprite_setTextureRect(default_sprite.sprite, rect);
        anim.counter_reset = sfTrue;
        anim.time = 0;
    } else {
        anim.counter_reset = sfFalse;
    }
    default_sprite.sprite_rect = rect;
    default_sprite.anim = anim;
    return default_sprite;
}

