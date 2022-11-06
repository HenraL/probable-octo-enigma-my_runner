/*
** EPITECH PROJECT, 2021
** runner - title.c
** File description:
** jitter jitter
*/

#include <SFML/Window.h>
#include "include/my_sprite.h"
#include "include/my_text.h"

sfRenderWindow *refresh_3_title_sprites(sfRenderWindow *window, sprite_t sp1,
                                        sprite_t sp2, sprite_t sp3)
{
    sfRenderWindow_drawSprite(window, sp1.sprite, NULL);
    sfRenderWindow_drawSprite(window, sp2.sprite, NULL);
    sfRenderWindow_drawSprite(window, sp3.sprite, NULL);
    return window;
}


sfRenderWindow *refresh_3_title_text(sfRenderWindow *window, text_t sp1,
                                     text_t sp2, text_t sp3)
{
    sfRenderWindow_drawText(window, sp1.text, NULL);
    sfRenderWindow_drawText(window, sp2.text, NULL);
    sfRenderWindow_drawText(window, sp3.text, NULL);
    return window;
}