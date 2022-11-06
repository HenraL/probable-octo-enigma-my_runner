/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** which_ending.c
*/

#include "../../include/my_end.h"

end_values_t end_text_move(end_values_t end)
{
    end.button_restart = move_sprite(end.button_restart, 900, 681);
    end.restart_text1 = move_text(end.restart_text1, 929, 684);
    end.restart_text2 = move_text(end.restart_text2, 1070, 688);
    end.main_menu_text1 = move_text(end.main_menu_text1, 900, 740);
    end.main_menu_text2 = move_text(end.main_menu_text2, 1070, 744);
    return end;
}

end_values_t display_correct_ending(end_values_t end, track_time_t time,
                                    sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    if (end.type == 3) {
        end.sprite_won = move_sprite(end.sprite_won, 900, 450);
        end.sprite_won = next_frame(end.sprite_won, time.won);
        sfRenderWindow_drawSprite(window, end.sprite_won.sprite, NULL);
        sfText_setString(end.restart_text1.text, "Play again");
    } else if (end.type == 4) {
        end.sprite_lost = move_sprite(end.sprite_lost, 900, 550);
        end.sprite_lost = next_frame(end.sprite_lost, time.lost);
        sfRenderWindow_drawSprite(window, end.sprite_lost.sprite, NULL);
        sfText_setString(end.restart_text1.text, "Retry luck");
    }
    end = end_text_move(end);
    sfRenderWindow_drawSprite(window, end.button_restart.sprite, NULL);
    sfRenderWindow_drawText(window, end.restart_text1.text, NULL);
    sfRenderWindow_drawText(window, end.restart_text2.text, NULL);
    sfRenderWindow_drawText(window, end.main_menu_text1.text, NULL);
    sfRenderWindow_drawText(window, end.main_menu_text2.text, NULL);
    sfRenderWindow_display(window);
    return end;
}
