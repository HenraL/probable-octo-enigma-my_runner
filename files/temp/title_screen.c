/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** display_sprite.c
*/

#include <stdlib.h>
#include "include/my_audio.h"
#include "include/my_window.h"
#include "include/my_lib.h"
#include "include/my_maths.h"
#include "include/my_sprite.h"
#include "include/my_mouse.h"
#include "include/my_text.h"
#include "include/my_silvers.h"
#include "include/my_event.h"
#include "include/my_convert.h"
#include <SFML/Window.h>

typedef struct initialise_backgrounds_s {
    two_sprites_t background1;
    two_sprites_t background2;
    two_sprites_t background3;
    int status;
} initialise_backgrounds_t;

initialise_backgrounds_t init_backgrounds(char *path1, char *path2, char *path3)
{
    initialise_backgrounds_t init_bkgd;
    float inc_factor_h = 0.4;
    float inc_factor_w = 0;
    // Background image settings //
    two_sprites_t bkgd_sprites = load_two_sprite(path1, path1, 1 + inc_factor_w, 0.5 + inc_factor_h);
    // path image settings //
    two_sprites_t path_sprites = load_two_sprite(path2, path2, 1 + inc_factor_w, 0.7 + inc_factor_h);//0.5);
    // ice image settings //
    two_sprites_t ice_sprites = load_two_sprite(path3, path3, 1 + inc_factor_w, 1 + inc_factor_h);
    // background sprites //
    if (bkgd_sprites.status == 84) {
        init_bkgd.status = 84;
        return init_bkgd;
    }
    // path sprites //
    if (path_sprites.status == 84) {
        init_bkgd.status = 84;
        return init_bkgd;
    }
    // ice sprites //
    if (ice_sprites.status == 84) {
        init_bkgd.status = 84;
        return init_bkgd;
    }
    // Background settings //
    bkgd_sprites.sprite_widths = 3642 + inc_factor_w; //3642x702
    bkgd_sprites.sprite_heights = 702 + inc_factor_h;
    // path settings //1920x219
    path_sprites.sprite_widths = 1920 + inc_factor_w;
    path_sprites.sprite_heights = 219 + inc_factor_h;
    // ice settings //
    ice_sprites.sprite_widths = 1920 + inc_factor_w;//1920x217
    ice_sprites.sprite_heights = 217 + inc_factor_h;
    // background //
    bkgd_sprites = initialise_drag_axis(bkgd_sprites, 0);
    bkgd_sprites.s2_x = bkgd_sprites.sprite_widths;
    // path //
    int bigger_indent = 132;
    path_sprites = initialise_drag_axis(path_sprites, 0);
    path_sprites.indent_level = 500 + bigger_indent;
    path_sprites.s1_y = path_sprites.indent_level;
    path_sprites.s2_x = path_sprites.sprite_widths;
    path_sprites.s2_y = path_sprites.indent_level;
    // ice //
    ice_sprites = initialise_drag_axis(ice_sprites, 0);
    ice_sprites.indent_level = path_sprites.indent_level + 145 + bigger_indent;
    ice_sprites.s1_y = ice_sprites.indent_level;
    ice_sprites.s2_x = ice_sprites.sprite_widths;
    ice_sprites.s2_y = ice_sprites.indent_level;
    init_bkgd.background1 = bkgd_sprites;
    init_bkgd.background2 = path_sprites;
    init_bkgd.background3 = ice_sprites;
    init_bkgd.status = 0;
    return init_bkgd;
}



typedef struct end_values_s {
    int type;
    sprite_t sprite_won;
    sprite_t sprite_lost;
    sprite_t button_restart;
    sfRenderWindow *window;

} end_values_t;

end_values_t initialise_end_values(sprite_t sprite1, sprite_t sprite2, int type)
{
    end_values_t end_values;
    end_values.sprite_won = sprite1;
    end_values.sprite_lost = sprite2;
    end_values.type = type;
    return end_values;
}

end_values_t display_correct_ending(end_values_t end, track_time_t time)
{
    if (end.type == 3) {
        end.sprite_won = move_sprite(end.sprite_won, 560, 340);
        end.sprite_won = next_frame(end.sprite_won, time.won);
    } else if (end.type == 4) {
        end.sprite_lost = move_sprite(end.sprite_lost, 560, 340);
        end.sprite_lost = next_frame(end.sprite_lost, time.lost);
    }
    return end;
}

int main(void)
{
    /* music path*/
    //Darun sandstorm//
    music_status_t sandstorm;
    sandstorm.path = "ogg/darun_sandstorm.ogg";
    audio_status_t start_game;
    start_game.path = "ogg/F5YUGD6-game-award.wav";
    /* image_paths */
    // asteroiad 510x500//
    char *asteroid_path = "img/enemies/asteroid.png";
    // Bomb path 48x26 //
    char *bomb_path = "img/enemies/bomb.png";
    // river path 638x262 //
    char *river_path = "img/enemies/frozen river.png";
    // spikes //
    char *spike_ball_path = "img/enemies/spike_ball.png";
    // button //
    char *button_path = "img/title_screen/bluebutton.png";
    // Background path //
    char *background_image_path = "img/background/final_background.png";
    // char *background_image_path2 = "img/background/block.jpg";
    // path path //
    char *path_image_path = "img/background/path_final.png";
    // ice path //
    char *ice_image_path = "img/background/ice_final.png";
    // silver path //
    char *silver_s_path = "img/sprite/silver/silver_running_very_slow.png";
    char *silver_n_path = "img/sprite/silver/silver_running_slow.png";
    char *silver_f_path = "img/sprite/silver/silver_running_fast.png";
    // end sprites //
    char *end_sprite_won_path = "img/ending/eggman_end.png";
    char *end_sprite_lost_path = "img/ending/silver_loading.png";
    // coin //
    char *coins_path = "img/bonuses/blue ring_shrunk.png";
    // coins (spritesheet) //
    char *coins_winter_path = "img/bonuses/coin_winter_spritesheet.png";

    char *spike_path = "img/enemies/spike.png";
    char *obstacle2_path = "img/spike-ball.png";
    printf("char * initialised\n");
    sfRenderWindow *window;
    framebuffer_t *fb;
    printf("Framebuffer initialised\n");
    sandstorm = load_music(sandstorm);
    // start_game = load_audio(start_game);

    /* Window size */
    float border_score_width = 1;
    text_t score1 = init_text("score: ", 3, 50);
    score1 = set_colors(score1, rgba(249, 235, 0, 1), rgba(0, 0, 0, 1));
    score1 = set_more_info(score1, border_score_width, 0, sfTextBold);
    printf("Score1 (text)  initialised\n");
    text_t score2 = init_text("0", 3, 50);
    score2 = set_colors(score2, rgba(248, 248, 249, 1), rgba(0, 0, 0, 1));
    score2 = set_more_info(score2, border_score_width, 0, sfTextBold);
    text_t time1 = init_text("time: ", 3, 50);
    time1 = set_colors(time1, rgba(249, 235, 0, 1), rgba(0, 0, 0, 1));
    time1 = set_more_info(time1, border_score_width, 0, sfTextBold);
    text_t time2 = init_text("0", 3, 50);
    time2 = set_colors(time2, rgba(248, 248, 249, 1), rgba(0, 0, 0, 1));
    time2 = set_more_info(time2, border_score_width, 0, sfTextBold);
    text_t rings1 = init_text("rings: ", 3, 50);
    rings1 = set_colors(rings1, rgba(249, 235, 0, 1), rgba(0, 0, 0, 1));
    rings1 = set_more_info(rings1, border_score_width, 0, sfTextBold);
    text_t rings2 = init_text("0", 1, 50);
    rings2 = set_colors(rings2, rgba(248, 248, 249, 1), rgba(0, 0, 0, 1));
    rings2 = set_more_info(rings2, border_score_width, 0, sfTextBold);

    score1 = move_text(score1, 0, 5);
    score2 = move_text(score2, 240, 5);

    time1 = move_text(time1, 0, 80);
    time2 = move_text(time2, 240, 80);//110, y

    rings1 = move_text(rings1, 0, 150);
    rings2 = move_text(rings2, 240, 150);//120, y
    int max_width = 1920;//1500;
    int max_height = 1080;//700;
    my_putstr("basic vars declared\n");
    /* sprite_vars */
    sfVector2f scale;
    scale.x = 100;
    // scale.y = sfTrue;
    scale.y = sfFalse;
    // button //
    sprite_t button_sprite1 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 476, 159),
                                          initialise_sfintrect(0, 0, 476, 159),
                                          scale);
    sprite_t button_sprite2 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 476, 159),
                                          initialise_sfintrect(0, 0, 476, 159),
                                          scale);
    sprite_t button_sprite3 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 476, 159),
                                          initialise_sfintrect(0, 0, 476, 159),
                                          scale);
    text_t title1 = init_text("SILVER", 1, 100);
    title1 = set_colors(title1, rgba(192, 192, 192, 1), rgba(211, 211, 211, 1));
    title1 = set_more_info(title1, 10, 0, sfTextBold);
    title1 = text_positioning(title1, 0, 200, 2.0);
    text_t title2 = init_text("RUNNER", 1, 100);
    title2 = set_colors(title2, rgba(192, 192, 192, 1), rgba(211, 211, 211, 1));
    title2 = set_more_info(title2, 10, 0, sfTextBold | sfTextItalic);
    title2 = text_positioning(title2, -600, 200, 2.0);
    text_t description1 = init_text("Play Game", 2, 50);
    description1 = set_colors(description1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description1 = set_more_info(description1, 3.5, 0, sfTextBold);
    text_t description2 = init_text("HowTo", 2, 50);
    description2 = set_colors(description2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description2 = set_more_info(description2, 3.5, 0, sfTextBold);
    text_t description3 = init_text("Exit", 2, 50);
    description3 = set_colors(description3, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description3 = set_more_info(description3, 3.5, 0, sfTextBold);

    description1.y = 930;
    description2.y = 930;
    description3.y = 930;
    description1.x = -300;
    description2.x = -300;
    description3.x = -300;

    // end image //
    scale.x = 60;
    scale.y = sfFalse;
    end_values_t ends = initialise_end_values(
        load_n_size(end_sprite_won_path,
                    initialise_sffloatrect(0, 0, 1680, 521),
                    initialise_sfintrect(0, 0, 448, 517),
                    scale),
        load_n_size(end_sprite_lost_path,
                    initialise_sffloatrect(0, 0, 279, 38),
                    initialise_sfintrect(0, 0, 47, 38),
                    scale), 0);
    ends.window = window;
    my_putstr("end_image sprite initialised\n");
    // spike //
    scale.x = 80;
    sprite_t spike_sprite = load_n_size(spike_path,
                                        initialise_sffloatrect(0, 0, 373, 397),
                                        initialise_sfintrect(0, 0, 373, 397),
                                        scale);
    spike_sprite.x = max_width;
    spike_sprite.y = 680;
    sprite_t spike2_sprite = spike_sprite;
    scale.x = 60;
    my_putstr("obstacle 1 sprite initialised\n");
    // enemy 2 //
    sprite_t ob2_sprite = load_n_size(obstacle2_path,
                                      initialise_sffloatrect(0, 0, 235, 233),
                                      initialise_sfintrect(0, 0, 235, 233),
                                      scale);
    // asteroids 89x104// 
    sprite_t asteroid_sprite = load_n_size(asteroid_path,
                                           initialise_sffloatrect(0, 0, 510, 500),
                                           initialise_sfintrect(0, 0, 89, 104),
                                           scale);
    asteroid_sprite.anim.max_ticks = 5;
    asteroid_sprite.anim.step_w = 85;
    asteroid_sprite.anim.step_h = 98;
    asteroid_sprite.anim.wrap = sfTrue;
    asteroid_sprite = move_sprite(asteroid_sprite, max_width - 30, 100);

    // bomb //
    // scale.x = 100;
    scale.y = sfTrue;
    sprite_t bomb_sprite = load_n_size(bomb_path,
                                       initialise_sffloatrect(0, 0, 48, 26),
                                       initialise_sfintrect(0, 0, 24, 26),
                                       scale);
    bomb_sprite.anim.max_ticks = 35;
    bomb_sprite.anim.step_w = 24;
    bomb_sprite.anim.wrap = sfTrue;
    bomb_sprite = move_sprite(bomb_sprite, max_width - 30, 650);
    scale.y = sfFalse;
    my_putstr("obstacle 2 sprite initialised\n");
    // river_sprite //
    sprite_t river_sprite = load_sprite(river_path);
    river_sprite.y = 630;
    river_sprite = move_sprite_with_s_x_n_y(river_sprite);
    river_sprite = rescale_sprite_by_percent(river_sprite, 1, sfTrue);
    // spike_ball_sprite //
    scale.y = sfTrue;
    sprite_t spike_ball_sprite = load_n_size(spike_ball_path,
                                             initialise_sffloatrect(0, 0, 68,
                                                                    17),
                                             initialise_sfintrect(0, 0, 15, 17),
                                             scale);
    spike_ball_sprite.anim.max_ticks = 35;
    spike_ball_sprite.anim.step_w = 16;
    spike_ball_sprite.anim.wrap = sfTrue;
    spike_ball_sprite = move_sprite(spike_ball_sprite, max_width - 30, 650);
    scale.y = sfFalse;
    my_putstr("obstacle 2 sprite initialised\n");
    // Coins_winter //
    sprite_t coins_w_sprite = load_n_size(coins_winter_path,
                                          initialise_sffloatrect(0, 0, 1782,
                                                                 66),
                                          initialise_sfintrect(0, 0, 66, 66),
                                          scale);
    // coins_w_sprite //
    coins_w_sprite.anim.max_ticks = 5;
    coins_w_sprite.anim.step_w = 66;
    coins_w_sprite.anim.wrap = sfTrue;
    coins_w_sprite = move_sprite(coins_w_sprite, 0, 14);
    sprite_t coins_w_sprite2 = load_n_size(coins_winter_path,
                                           initialise_sffloatrect(0, 0, 1782,
                                                                  66),
                                           initialise_sfintrect(0, 0, 66, 66),
                                           scale); //dup_sprite((const sprite_t)coins_w_sprite);
    my_putstr("Coins winter initialised.\n");
    // character //
    scale.y = 1;
    silver_states_t silvers = load_the_silvers(silver_s_path, silver_n_path,
                                               silver_f_path, scale);
    sprite_t silver_sprite = silvers.silver_f_sprite;
    silver_sprite.position.x = 150;
    silver_sprite.position.y = 680;
    my_putstr("Silver sprite initialised\n");
    // event generation //
    sfEvent event;
    initialise_backgrounds_t init_bkgd = init_backgrounds(background_image_path,
                                                          path_image_path,
                                                          ice_image_path);
    /* loading the sprites */
    /* Setting the size of the images */
    /* initialising index counters */
    if (init_bkgd.status == 84) {
        return 84;
    }
    two_sprites_t bkgd_sprites = init_bkgd.background1;
    two_sprites_t path_sprites = init_bkgd.background2;
    two_sprites_t ice_sprites = init_bkgd.background3;
    my_putstr("event and backgrounds initialised\n");
    //1- Create the ressources
    window = createWindow(max_width, max_height);
    fb = framebuffer_create(max_width, max_height);
    my_putstr("window and framebuffer initialised\n");
    smoothing_tracker_t is_it = init_smoothing(silvers);
    score_t score;
    score.coins = 0;
    score.enemies = 0;
    score.time = 0;
    score.total = 0;
    int characters_y = 680;
    int x = 150;
    int default_x = x;
    int y = characters_y;
    int default_y = y;
    int amount_to_add = 5;
    int image_size_w = 583;
    int image_size_h = 56;
    int ob2_x = max_width * 2;
    int ob2_y = characters_y;
    int in_game = 1;
    my_putstr("more basic vars initialised\n");
    /* mouse */
    mouse_trac_t mouse_sprite = init_mouse(event, coins_w_sprite, 0);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfClock *hourglass = sfClock_create();
    sfTime delta_time = sfTime_Zero;
    unsigned long int times_counter = 0;
    int track_animation = 0;
    int track_animation_to_add = coins_w_sprite.sprite_rect.width;

    // end_values_t end_content = initialise_end_values()
        // end_values_t end_values;
    // sfSprite_copy
    track_time_t time;
    time.silver = 0;
    time.rings = 0;
    time.asteroid = 0;
    time.bomb = 0;
    time.eggman = 0;
    time.lost = 0;
    time.rocket = 0;
    time.spike_ball = 0;
    time.won = 0;

    float count_nb_loops = 0;
    track_actions_t evt_actions = initialise_tracking(in_game, max_width,
                                                      max_height);

    my_putstr("mouse sprite initialised\n");
    my_putstr("before while\n");
    while (sfRenderWindow_isOpen(window)) {
        evt_actions.window = window;
        evt_actions.silver = silver_sprite;
        evt_actions.global_speed = is_it.global_speed;
        // evt_actions.change_to_game = start_game;
        delta_time = sfClock_restart(hourglass);
        sfRenderWindow_setFramerateLimit(window, 120);
        while (sfRenderWindow_pollEvent(window, &event))
        {
            evt_actions = on_event(event, evt_actions);
            silver_sprite = evt_actions.silver;
            window = evt_actions.window;
            is_it.global_speed = evt_actions.global_speed;
            // start_game.was_played = evt_actions.change_to_game.was_played;
            mouse_sprite = mouse_update_pos(event, mouse_sprite,
                                            coins_w_sprite);
        }
        silver_sprite = next_frame(silver_sprite, time.silver);
        if (silver_sprite.anim.counter_reset == sfTrue) {
            // my_putstr("\n\nIn anim.counter_reset (silver)\n\n");
            time.silver = 0;
            // printf("time.silver = %d\n", time.silver);
            silver_sprite.anim.counter_reset = sfFalse;
        }
        coins_w_sprite = next_frame(coins_w_sprite, time.rings);
        if (coins_w_sprite.anim.counter_reset == sfTrue) {
            // my_putstr("\n\nIn anim.counter_reset (coins)\n\n");
            time.rings = 0;
            // printf("time.rings = %d\n", time.rings);
            coins_w_sprite.anim.counter_reset = sfFalse;
        }
        asteroid_sprite = next_frame(asteroid_sprite, time.asteroid);
        if (asteroid_sprite.anim.counter_reset == sfTrue) {
            time.asteroid = 0;
            // printf("time.rings = %d\n", time.rings);
            asteroid_sprite.anim.counter_reset = sfFalse;
        }
        bomb_sprite = next_frame(bomb_sprite, time.bomb);
        if (bomb_sprite.anim.counter_reset == sfTrue) {
            time.bomb = 0;
            // printf("time.rings = %d\n", time.rings);
            bomb_sprite.anim.counter_reset = sfFalse;
        }
        spike_ball_sprite = next_frame(spike_ball_sprite, time.spike_ball);
        if (spike_ball_sprite.anim.counter_reset == sfTrue) {
            time.spike_ball = 0;
            // printf("time.rings = %d\n", time.rings);
            spike_ball_sprite.anim.counter_reset = sfFalse;
        }

        time.silver++;
        time.rings++;
        time.asteroid++;
        time.bomb++;
        time.spike_ball++;
        printf("silver_sprite.x = %d | silver_sprite.y = %d\n", silver_sprite.x, silver_sprite.y);
        if (evt_actions.in_game == 1) {
            // Background //
            bkgd_sprites = move_two_sprites(bkgd_sprites);
            // path //
            path_sprites = move_two_sprites(path_sprites);
            // // ice //
            ice_sprites = move_two_sprites(ice_sprites);
            // silver //
            // silver_sprite = move_sprite_with_s_x_n_y(silver_sprite);
            // silver_sprite = move_sprite(silver_sprite, x, y);
            silver_sprite = move_sprite(silver_sprite, silver_sprite.x, silver_sprite.y);
            // printf("silver_sprite.x = %d | silver_sprite.y = %d\n", silver_sprite.x, silver_sprite.y);
            // coin_w_sprite //
            // coins_w_sprite = move_sprite(coins_w_sprite, 10, 10);
            if (title1.x < 500) {//825) {
                // printf("title1.x = %d\n", title1.x);
                title1.x += 2;
            }
            if (title2.x < 1050 && title1.x == 500) {
                // printf("title2.x = %d\n", title2.x);
                title2.x += 10;
            }
            title1 = move_text_using_strut(title1);
            title2 = move_text_using_strut(title2);
            coins_w_sprite2 = move_sprite(coins_w_sprite2, 0, 0);
            button_sprite1 = move_sprite(button_sprite1, 100, 906);
            button_sprite2 = move_sprite(button_sprite2, 750, 906);
            button_sprite3 = move_sprite(button_sprite3, 1400, 906);

            if (description1.x < 150 && title2.x == 1050) {
                description1.x += 5;
            }
            if (description2.x < 850 && description1.x == 150) {
                description2.x += 10;
            }
            if (description3.x < 1540 && description2.x == 850) {
                description3.x += 15;
            }
            description1 = move_text_using_strut(description1);
            description2 = move_text_using_strut(description2);
            description3 = move_text_using_strut(description3);
            // score2 = update_text(score2, (char *)score.total);
            // char *my_number = nb_to_char_star(score.total);
            // score2 = update_text(score2, my_number);
            printf("score.total = %d\n", score.total);
            printf("score.coins = %d\n", score.coins);
            printf("score.time = %d\n", score.time);
            // description1 = 
            /* Display sprites in the window */

            // background //
            if (asteroid_sprite.x <= 0) {
                asteroid_sprite.x = max_width + asteroid_sprite.w;
            }
            if (asteroid_sprite.y >= max_height) {
                asteroid_sprite.y = (asteroid_sprite.h * -1);
            }
            asteroid_sprite = move_sprite_with_s_x_n_y(asteroid_sprite);
            if (bomb_sprite.x <= 0) {
                bomb_sprite.x = max_width + bomb_sprite.x;
            }
            bomb_sprite = move_sprite_with_s_x_n_y(bomb_sprite);
            my_put_nbr(river_sprite.x);
            my_putchar('\n');
            if (river_sprite.x <= ((max_width) * -1)) {
                river_sprite.x = (max_width / 2);
            }
            river_sprite = move_sprite_with_s_x_n_y(river_sprite);
            if (spike_ball_sprite.x <= 0) {
                spike_ball_sprite.x = max_width + spike_ball_sprite.w;
            }
            spike_ball_sprite = move_sprite_with_s_x_n_y(spike_ball_sprite);
            draw_two_sprites(window, bkgd_sprites, NULL);
            // path //
            draw_two_sprites(window, path_sprites, NULL);
            // ice //
            draw_two_sprites(window, ice_sprites, NULL);
            // river //
            sfRenderWindow_drawSprite(window, river_sprite.sprite, NULL);
            // silver //
            sfRenderWindow_drawSprite(window, silver_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite1.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite2.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite3.sprite, NULL);
            sfRenderWindow_drawSprite(window, asteroid_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, bomb_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, spike_ball_sprite.sprite, NULL);
            sfRenderWindow_drawText(window, title2.text, NULL);
            sfRenderWindow_drawText(window, title1.text, NULL);
            sfRenderWindow_drawText(window, score2.text, NULL);
            sfRenderWindow_drawText(window, time1.text, NULL);
            sfRenderWindow_drawText(window, time2.text, NULL);
            sfRenderWindow_drawText(window, rings1.text, NULL);
            sfRenderWindow_drawText(window, rings2.text, NULL);
            sfRenderWindow_drawText(window, description1.text, NULL);
            sfRenderWindow_drawText(window, description2.text, NULL);
            sfRenderWindow_drawText(window, description3.text, NULL);
            sfRenderWindow_drawSprite(window, coins_w_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, coins_w_sprite2.sprite, NULL);
            sfRenderWindow_drawText(window, score1.text, NULL);
            //v- Display the window
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            // Background //
            bkgd_sprites = is_reset_drag_needed(bkgd_sprites, max_width);
            // path //
            path_sprites = is_reset_drag_needed(path_sprites, max_width);
            // ice //
            ice_sprites = is_reset_drag_needed(ice_sprites, max_width);
            /*changing values of indexes */
            // background //
            bkgd_sprites = change_two_val(bkgd_sprites, 0, 1);
            // path //
            path_sprites = change_two_val(path_sprites, 0, 5);
            // ice //
            ice_sprites = change_two_val(ice_sprites, 0, 10);
            score.time++;
            score.total = score.time + score.coins;
            asteroid_sprite.x -= 3;
            asteroid_sprite.y += 5;
            bomb_sprite.x -= 4;
            river_sprite.x -= 1;

        } else if (evt_actions.in_game == 2) {
            // play_loaded_audio
            // start_game = play_loaded_audio(start_game);
            sandstorm = play_loaded_music(sandstorm);
            /* Check the clock */
            is_it = is_smoothing_time(is_it, silvers, silver_sprite);
            // silver_sprite = override_sprite(silver_sprite, is_it.silver);
            /* Move sprites */
            // Background //
            bkgd_sprites = move_two_sprites(bkgd_sprites);
            // path //
            path_sprites = move_two_sprites(path_sprites);
            // // ice //
            ice_sprites = move_two_sprites(ice_sprites);
            // silver_sprite.x = silvers.silver_s_sprite.x + is_it.global_speed;
            // silver //
            silver_sprite = move_sprite(silver_sprite, silver_sprite.x, silver_sprite.y);
            // obstacle 1 //
            spike_sprite = move_sprite_with_s_x_n_y(spike_sprite);
            // obstacle 2 //
            ob2_sprite = move_sprite(ob2_sprite, ob2_x, ob2_y);
            // coin_w_sprite //
            coins_w_sprite = move_sprite(coins_w_sprite, 0, 0);
            /* Display sprites in the window */
            // background //
            draw_two_sprites(window, bkgd_sprites, NULL);
            // path //
            draw_two_sprites(window, path_sprites, NULL);
            // ice //
            draw_two_sprites(window, ice_sprites, NULL);
            // silver //
            sfRenderWindow_drawSprite(window, silver_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, spike_sprite.sprite, NULL);
            // sfRenderWindow_drawSprite(window, coins_w_sprite2.sprite, NULL);
            sfRenderWindow_drawSprite(window, ob2_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, coins_w_sprite.sprite, NULL);
            //v- Display the window
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            // Background //
            bkgd_sprites = is_reset_drag_needed(bkgd_sprites, max_width);
            // path //
            path_sprites = is_reset_drag_needed(path_sprites, max_width);
            // ice //
            ice_sprites = is_reset_drag_needed(ice_sprites, max_width);
            /*changing values of indexes */
            // background //
            bkgd_sprites = change_two_val(bkgd_sprites, 0, 1 + is_it.global_speed);
            // path //
            path_sprites = change_two_val(path_sprites, 0, 5 + is_it.global_speed);
            // ice //
            ice_sprites = change_two_val(ice_sprites, 0, 10 + is_it.global_speed);
            // y++;

            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 3;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 3;
            }
            if (silver_sprite.x > silver_sprite.position.x) {
                silver_sprite.x += -2;//1;
            }
            if (silver_sprite.x < silver_sprite.position.x) {
                silver_sprite.x += 2;//1;
            }
            if (silver_sprite.y > silver_sprite.position.y) {
                silver_sprite.y += -2;//1;
            }
            if (silver_sprite.y < silver_sprite.position.y) {
                silver_sprite.y += 2;//1;
            }
            // x += amount_to_add;
            spike_sprite.x += -5;
            ob2_x += -10;
            if (spike_sprite.x == 0) {
                spike_sprite.x = max_width;
            }
            if (ob2_x == 0) {
                ob2_x = max_width * 2;
            }
            score.time++;
        } else {
            sandstorm = pause_loaded_music(sandstorm);
            ends.window = window;
            ends.type = in_game;
            ends = display_correct_ending(ends, time);
            if (ends.sprite_won.anim.counter_reset == sfTrue) {
                time.won = 0;
                ends.sprite_won.anim.counter_reset = sfFalse;
            }
            if (ends.sprite_lost.anim.counter_reset == sfTrue) {
                time.won = 0;
                ends.sprite_lost.anim.counter_reset = sfFalse;
            }
            time.won++;
            time.lost++;
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
        }

        sfRenderWindow_drawSprite(window, coins_w_sprite2.sprite, NULL);
        times_counter++;
        // printf("times_counter = %d, time.silver = %d, time.rings = %d, score.time = %d\n", times_counter, time.silver, time.rings, score.time);
    }
    printf("score = %d\n", score.time);
    sfRenderWindow_destroy(window);
    framebuffer_destroy(fb);
    /* freeing ressources */
    // background sprites //
    free_two_sprites(bkgd_sprites);
    // path sprite //
    free_two_sprites(path_sprites);
    // ice_sprite //
    free_two_sprites(ice_sprites);
    // silver_sprite //
    free_sprite(silver_sprite);
    free_sprite(button_sprite1);
    free_sprite(button_sprite2);
    free_sprite(button_sprite3);
    // coins_sprite //
    free_sprite(coins_w_sprite2);
    free_sprite(coins_w_sprite);
    free_text(title1);
    free_text(title2);
    free_text(description1);
    free_text(description2);
    free_text(description3);
    free_text(score1);
    free_text(score2);
    free_text(time1);
    free_text(time2);
    free_text(rings1);
    free_text(rings2);
    free_music(sandstorm);
    // free_audio(start_game);
}
