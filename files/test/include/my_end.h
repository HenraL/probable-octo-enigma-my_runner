/*
** EPITECH PROJECT, 2021
** get_csfml_keys - my_end.h
** File description:
** jitter jitter
*/

#ifndef MY_END_H_
#define MY_END_H_

#include "my_sprite.h"
#include "my_text.h"
#include <stdlib.h>

typedef struct end_values_s {
    int type;
    sprite_t sprite_won;
    sprite_t sprite_lost;
    sprite_t button_restart;
    text_t restart_text1;
    text_t restart_text2;
    text_t main_menu_text1;
    text_t main_menu_text2;
    sfRenderWindow *window;

} end_values_t;

end_values_t display_correct_ending(end_values_t end, track_time_t time,
                                    sfRenderWindow *window);
end_values_t end_text_move(end_values_t end);
end_values_t initialise_end_values(sprite_t sprite1, sprite_t sprite2,
                                   int type);
void free_end(end_values_t end);

#endif