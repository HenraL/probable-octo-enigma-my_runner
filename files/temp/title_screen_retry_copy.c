/*
** EPITECH PROJECT, 2021
** get_csfml_keys - title_screen_retry.c
** File description:
** jitter jitter
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "include/my_audio.h"
#include "include/my_convert.h"
#include "include/my_lib.h"
#include "include/my_maths.h"
#include "include/my_mouse.h"
#include "include/my_sprite.h"
#include "include/my_silvers.h"
#include "include/my_scores.h"
#include "include/my_event.h"
#include "include/my_end.h"
#include "include/my_root.h"
#include "include/my_game_elements.h"
#include "include/my_text.h"
#include "include/my_image.h"
#include "include/my_window.h"



int launch_game(void) {
    music_status_t sandstorm;
    sandstorm.path = "ogg/darun_sandstorm.ogg";
    music_status_t start_prog;
    start_prog.path = "ogg/Win_95_bootup.ogg";
    music_status_t title_screen_music;
    title_screen_music.path = "ogg/Flying_Battery_Zone_Act2-Sonic_Mania_OST.ogg";
    music_status_t ring_sound;
    ring_sound.path = "ogg/ring.ogg";
    sandstorm = load_music(sandstorm, sfTrue);
    title_screen_music = load_music(title_screen_music, sfTrue);
    start_prog = load_music(start_prog, sfFalse);
    ring_sound = load_music(ring_sound, sfFalse);
    find_images_t my_images = init_images();
    image_paths_t walls_path;
    walls_path.path1 = "img/obstacles/ice_cube_block.png";
    walls_path.path2 = "img/obstacles/ice_cube_only.png";
    walls_path.path3 = "img/obstacles/snow_cap.png";
    walls_path.path4 = "img/obstacles/platform.png";
    sfRenderWindow *window;
    framebuffer_t *fb;

    sfColor my_yellow = rgba(249, 235, 0, 1);
    sfColor my_white = rgba(248, 248, 249, 1);
    sfColor my_grey = rgba(192, 192, 192, 1);
    text_t score1 = init_text_simp("score: ", 1, my_yellow, 1);
    text_t score2 = init_text_simp("0", 1, my_white, 1);
    text_t time1 = init_text_simp("time: ", 1, my_yellow, 1);
    text_t time2 = init_text_simp("0", 1, my_white, 1);
    text_t rings1 = init_text_simp("rings: ", 1, my_yellow, 1);
    text_t rings2 = init_text_simp("0", 1, my_white, 1);
    score1 = move_text(score1, 0, 5);
    score2 = move_text(score2, 240, 5);
    time1 = move_text(time1, 0, 80);
    time2 = move_text(time2, 240, 80);
    rings1 = move_text(rings1, 0, 150);
    rings2 = move_text(rings2, 240, 150);
    int max_w = 1920;
    int max_h = 1080;
    sfVector2f scale = { 30 , sfTrue };
    sprite_t button_sprite1 = load_n_size(my_images.button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite2 = load_n_size(my_images.button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite3 = load_n_size(my_images.button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite4 = load_n_size(my_images.button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite_restart = load_n_size(my_images.button_path,
                                                 initialise_sffloatrect(0, 0,
                                                                        276,
                                                                        44),
                                                 initialise_sfintrect(0, 0,
                                                                      138, 44),
                                                 scale);
    sfVector2i my_pos = { 0,200 };
    text_t title1 = init_title_simp("SILVER", 1, my_pos, sfTextBold);
    my_pos.x = -600;
    text_t title2 = init_title_simp("RUNNER", 1, my_pos, sfTextBold |
                                    sfTextItalic);
    sfVector2i my_pos2 = { -300, 930 };
    text_t description1_1 = init_desc_simp("Play Game", 2, 30, my_pos2);
    text_t description2_1 = init_desc_simp("How To", 2, 30, my_pos2);
    text_t description3_1 = init_desc_simp("Credits", 2, 30, my_pos2);
    text_t description4_1 = init_desc_simp("Exit", 2, 30, my_pos2);
    text_t restart5_1 = init_desc_simp("Restart", 2, 30, my_pos2);
    text_t main_menu6_1 = init_desc_simp("Main Menu", 2, 30, my_pos2);
    sfVector2i my_pos3 = { -214, 940 };
    text_t description1_2 = init_desc_simp("(SPACE)", 2, 15, my_pos3);
    my_pos3.x = -180;
    text_t description2_2 = init_desc_simp("(H)", 2, 15, my_pos3);
    text_t description3_2 = init_desc_simp("(C)", 2, 15, my_pos3);
    my_pos3.x = -210;
    text_t description4_2 = init_desc_simp("(ESC)", 2, 15, my_pos3);
    text_t restart5_2 = init_desc_simp("(R)", 2, 15, my_pos3);
    text_t main_menu6_2 = init_desc_simp("(M)", 2, 15, my_pos3);
    int common_y = 920;
    button_sprite1.d.y = common_y;
    button_sprite2.d.y = common_y;
    button_sprite3.d.y = common_y;
    button_sprite4.d.y = common_y;

    button_sprite1.d.x = -325;
    button_sprite2.d.x = -325;
    button_sprite3.d.x = -325;
    button_sprite4.d.x = -325;

    dimensions_for_4_assets_t dims;
    dims.dim1 = assing_dim_for_an_asset(749, 810);
    dims.dim2 = assing_dim_for_an_asset(708, 804);
    dims.dim3 = assing_dim_for_an_asset(572, 110);
    dims.dim4 = assing_dim_for_an_asset(2513, 815);
    assets_t walls = load_4_assets(walls_path, dims);

    scale.x = 60;
    scale.y = sfFalse;
    sfVector2f scale_s = { 150, sfTrue };
    end_values_t ends = initialise_end_values(
        load_n_size(my_images.end_sprite_won_path,
                    initialise_sffloatrect(0, 0, 1680, 521),
                    initialise_sfintrect(0, 0, 419, 525), scale),
        load_n_size(my_images.end_sprite_lost_path,
                    initialise_sffloatrect(0, 0, 278, 38),
                    initialise_sfintrect(0, 0, 46, 38), scale_s), 0);
    ends.sprite_won.anim.max_ticks = 15;
    ends.sprite_won.anim.wrap = sfTrue;
    ends.sprite_lost.anim.max_ticks = 25;
    ends.sprite_lost.anim.wrap = sfTrue;
    ends.window = window;
    ends.restart_text1 = restart5_1;
    ends.restart_text2 = restart5_2;
    ends.button_restart = button_sprite_restart;
    ends.main_menu_text1 = main_menu6_1;
    ends.main_menu_text2 = main_menu6_2;
    scale.y = sfFalse;
    scale.x = 80;
    sprite_t spike_sprite = load_n_size(my_images.spike_path,
                                        initialise_sffloatrect(0, 0, 373, 397),
                                        initialise_sfintrect(0, 0, 373, 397),
                                        scale);
    spike_sprite.d.x = max_w;
    spike_sprite.d.y = 680;
    sprite_t spike2_sprite = spike_sprite;
    scale.x = 60;
    sprite_t ob2_sprite = load_n_size(my_images.obstacle2_path,
                                      initialise_sffloatrect(0, 0, 235, 233),
                                      initialise_sfintrect(0, 0, 235, 233),
                                      scale);
    sprite_t rock_sprite = load_n_size(my_images.asteroid_path,
                                       initialise_sffloatrect(0, 0, 510, 500),
                                       initialise_sfintrect(0, 0, 89, 104),
                                       scale);
    rock_sprite.anim.max_ticks = 5;
    rock_sprite.anim.step_w = 85;
    rock_sprite.anim.step_h = 98;
    rock_sprite.anim.wrap = sfTrue;
    rock_sprite = move_sprite(rock_sprite, max_w - 30, 100);

    scale.y = sfTrue;
    sprite_t bomb_sprite = load_n_size(my_images.bomb_path,
                                       initialise_sffloatrect(0, 0, 48, 26),
                                       initialise_sfintrect(0, 0, 24, 26),
                                       scale);
    bomb_sprite.anim.max_ticks = 35;
    bomb_sprite.anim.step_w = 24;
    bomb_sprite.anim.wrap = sfTrue;
    bomb_sprite = move_sprite(bomb_sprite, max_w - 30, 650);
    scale.y = sfFalse;
    sprite_t river_sprite = load_sprite(my_images.river_path);
    river_sprite.d.y = 630;
    river_sprite = move_sprite_with_struct(river_sprite);
    river_sprite = rescale_sprite_by_percent(river_sprite, 1, sfTrue);
    scale.y = sfTrue;
    scale.x = 90;
    sprite_t spike_ball_sprite = load_n_size(my_images.spike_ball_path,
                                             initialise_sffloatrect(0, 0, 72,
                                                                    17),
                                             initialise_sfintrect(0, 0, 18, 17),
                                             scale);
    spike_ball_sprite.anim.max_ticks = 35;
    spike_ball_sprite.anim.step_w = 18;
    spike_ball_sprite.anim.wrap = sfTrue;
    spike_ball_sprite = move_sprite(spike_ball_sprite, max_w - 30, 650);
    scale.y = sfFalse;
    scale.x = 60;
    scale.x = 200;
    sprite_t rocket_sprite = load_n_size(my_images.rocket_path,
                                         initialise_sffloatrect(0, 0, 234, 12),
                                         initialise_sfintrect(0, 0, 56, 12),
                                         scale);
    rocket_sprite.anim.max_ticks = 5;
    rocket_sprite.anim.step_w = 56;
    rocket_sprite.anim.wrap = sfTrue;
    rocket_sprite = move_sprite(rocket_sprite, max_w - 30, 650);
    scale.x = 60;
    sprite_t rings_w_sprite = load_n_size(my_images.rings_winter_path,
                                          initialise_sffloatrect(0, 0, 1782,
                                                                 66),
                                          initialise_sfintrect(0, 0, 66, 66),
                                          scale);
    rings_w_sprite.anim.max_ticks = 5;
    rings_w_sprite.anim.step_w = 66;
    rings_w_sprite.anim.wrap = sfTrue;
    rings_w_sprite = move_sprite(rings_w_sprite, 0, 14);
    sprite_t ring_w_sprite2 = load_n_size(my_images.rings_winter_path,
                                          initialise_sffloatrect(0, 0, 1782,
                                                                 66),
                                          initialise_sfintrect(0, 0, 66, 66),
                                          scale);

    ring_w_sprite2.anim.max_ticks = 5;
    ring_w_sprite2.anim.step_w = 66;
    ring_w_sprite2.anim.wrap = sfTrue;
    ring_w_sprite2 = move_sprite(ring_w_sprite2, 0, 681);
    scale.y = 1;
    silver_states_t silvers = load_the_silvers(my_images.silver_s_path,
                                               my_images.silver_n_path,
                                               my_images.silver_f_path, scale);
    sprite_t silver_sprite = silvers.silver_f_sprite;
    silver_sprite.home_position.x = 150;
    silver_sprite.home_position.y = 680;
    silver_sprite.position.x = 150;
    silver_sprite.position.y = 680;
    sfEvent event;
    init_bkgd_t init_bkgd = init_backgrounds(my_images);
    if (init_bkgd.status == 84) {
        return 84;
    }
    two_sprites_t bkgd_sprites = init_bkgd.background1;
    two_sprites_t path_sprites = init_bkgd.background2;
    two_sprites_t ice_sprites = init_bkgd.background3;
    window = createWindow(max_w, max_h);
    fb = framebuffer_create(max_w, max_h);
    smoothing_tracker_t is_it = init_smoothing(silvers);
    score_t score = initialise_score(0);
    init_randint();
    int characters_y = 680;
    int x = 150;
    int default_x = x;
    int y = characters_y;
    int default_y = y;
    int amount_to_add = 5;
    int image_size_w = 583;
    int image_size_h = 56;
    int ob2_x = max_w * 2;
    int ob2_y = characters_y;
    int in_game = 1;
    int j = 1;
    if (randint(0, 10, 1) == 5) {
        j = 0;
    }
    unsigned int when_does_it_end = 200000000;
    mouse_trac_t mouse_sprite = init_mouse(event, rings_w_sprite, 0);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfClock *hourglass = sfClock_create();
    sfTime delta_time = sfTime_Zero;
    unsigned long int times_counter = 0;
    int track_animation = 0;
    int track_animation_to_add = rings_w_sprite.sprite_rect.width;
    track_time_t time = init_time(0);

    float count_nb_loops = 0;
    track_actions_t evt_actions = initialise_tracking(in_game, max_w, max_h);
    while (sfRenderWindow_isOpen(window)) {
        evt_actions.window = window;
        evt_actions.silver = silver_sprite;
        evt_actions.global_speed = is_it.global_speed;
        evt_actions.buttons = initialise_button(button_sprite1, button_sprite2,
                                                button_sprite3, button_sprite4);
        evt_actions.buttons.restart = button_sprite_restart;
        delta_time = sfClock_restart(hourglass);
        sfRenderWindow_setFramerateLimit(window, 120);
        while (sfRenderWindow_pollEvent(window, &event))
        {
            evt_actions = on_event(event, evt_actions);
            silver_sprite = evt_actions.silver;
            window = evt_actions.window;
            is_it.global_speed = evt_actions.global_speed;
            button_sprite1 = evt_actions.buttons.button1;
            button_sprite2 = evt_actions.buttons.button2;
            button_sprite3 = evt_actions.buttons.button3;
            button_sprite4 = evt_actions.buttons.button4;
            button_sprite_restart = evt_actions.buttons.restart;
            mouse_sprite = mouse_update_pos(event, mouse_sprite,
                                            rings_w_sprite);
        }


        silver_sprite = next_frame(silver_sprite, time.silver);
        if (silver_sprite.anim.counter_reset == sfTrue) {
            time.silver = 0;
            silver_sprite.anim.counter_reset = sfFalse;
        }
        rings_w_sprite = next_frame(rings_w_sprite, time.rings);
        ring_w_sprite2 = next_frame(ring_w_sprite2, time.rings);
        if (rings_w_sprite.anim.counter_reset == sfTrue) {
            time.rings = 0;
            rings_w_sprite.anim.counter_reset = sfFalse;
            ring_w_sprite2.anim.counter_reset = sfFalse;
        }
        rock_sprite = next_frame(rock_sprite, time.asteroid);
        if (rock_sprite.anim.counter_reset == sfTrue) {
            time.asteroid = 0;
            rock_sprite.anim.counter_reset = sfFalse;
        }
        bomb_sprite = next_frame(bomb_sprite, time.bomb);
        if (bomb_sprite.anim.counter_reset == sfTrue) {
            time.bomb = 0;
            bomb_sprite.anim.counter_reset = sfFalse;
        }
        spike_ball_sprite = next_frame(spike_ball_sprite, time.spike_ball);
        if (spike_ball_sprite.anim.counter_reset == sfTrue) {
            time.spike_ball = 0;
            spike_ball_sprite.anim.counter_reset = sfFalse;
        }
        rocket_sprite = next_frame(rocket_sprite, time.rocket);
        if (rocket_sprite.anim.counter_reset == sfTrue) {
            time.rocket = 0;
            rocket_sprite.anim.counter_reset = sfFalse;
        }
        time.silver++;
        time.rings++;
        time.asteroid++;
        time.bomb++;
        time.spike_ball++;
        time.rocket++;
        if (evt_actions.in_game == 1) {
            if (evt_actions.reset_scores == 1) {
                score = reset_scores(score);
            }
            if (start_prog.was_played == 1 || j == 0) {
                title_screen_music = play_loaded_music(title_screen_music);
            }
            if (start_prog.was_played == 0 && j == 1) {
                start_prog = play_loaded_music(start_prog);
            }
            sandstorm = stop_loaded_music(sandstorm);
            bkgd_sprites = move_two_sprites(bkgd_sprites);
            path_sprites = move_two_sprites(path_sprites);
            ice_sprites = move_two_sprites(ice_sprites);
            silver_sprite = move_sprite_with_struct(silver_sprite);
            title1 = is_moving_needed(title1, 500, 2);
            if (title2.x < 1050 && title1.x == 500) {
                title2.x += 10;
            }
            if (description1_1.x < 100 && title2.x == 1050) {
                description1_1.x += 5;
                description1_2.x += 6;
                button_sprite1.d.x += 5;
            }
            if (description2_1.x < 600 && description1_1.x == 100) {
                description2_1.x += 10;
                description2_2.x += 10;
                button_sprite2.d.x += 10;
            }
            if (description3_1.x < 900 && description2_1.x == 600) {
                description3_1.x += 15;
                description3_2.x += 15;
                button_sprite3.d.x += 15;
            }
            if (description4_1.x < 1280 && description3_1.x == 900) {
                description4_1.x += 20;
                description4_2.x += 20;
                button_sprite4.d.x += 20;
            }
            title1 = move_text_using_strut(title1);
            title2 = move_text_using_strut(title2);
            description1_1 = move_text_using_strut(description1_1);
            description1_2 = move_text_using_strut(description1_2);
            description2_1 = move_text_using_strut(description2_1);
            description2_2 = move_text_using_strut(description2_2);
            description3_1 = move_text_using_strut(description3_1);
            description3_2 = move_text_using_strut(description3_2);
            description4_1 = move_text_using_strut(description4_1);
            description4_2 = move_text_using_strut(description4_2);
            button_sprite1 = move_sprite_with_struct(button_sprite1);
            button_sprite2 = move_sprite_with_struct(button_sprite2);
            button_sprite3 = move_sprite_with_struct(button_sprite3);
            button_sprite4 = move_sprite_with_struct(button_sprite4);
            score2 = update_text(score2, nb_to_char_star(score.total));
            time2 = update_text(time2, nb_to_char_star(score.time));
            // if (score.rings > 0) {
            rings2 = update_text(rings2, nb_to_char_star(score.rings));
            // }
            rock_sprite = is_res_pos_req(rock_sprite, 0, max_w, 0);
            rock_sprite = is_res_pos_req(rock_sprite, max_h,
                                         (rock_sprite.d.h * -1), 1);
            bomb_sprite = is_res_pos_req(bomb_sprite, 0, (max_w +
                                                          bomb_sprite.d.x), 0);
            river_sprite = is_res_pos_req(river_sprite, (max_w * -1),
                                          (max_w - 200), 0);
            spike_ball_sprite = is_res_pos_req(spike_ball_sprite, 0,
                                               (max_w + spike_ball_sprite.d.w)
                                               , 0);
            rocket_sprite = is_res_pos_req(rock_sprite, 0,
                                           (max_w + rocket_sprite.d.w), 0);
            if (ring_w_sprite2.d.x <= 0) {
                ring_w_sprite2.d.x = max_w + ring_w_sprite2.d.w;
                ring_w_sprite2 = randomise_sprite_pos_y(ring_w_sprite2, 600,
                                                        700);
            }
            if (is_sprite_coliding(silver_sprite, ring_w_sprite2) == 1) {
                ring_sound = play_as_sound(ring_sound);
                score.rings++;
            }
            ring_w_sprite2 = move_sprite_with_struct(ring_w_sprite2);
            draw_two_sprites(window, bkgd_sprites, NULL);
            draw_two_sprites(window, path_sprites, NULL);
            draw_two_sprites(window, ice_sprites, NULL);

            sfRenderWindow_drawSprite(window, river_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, rocket_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite1.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite2.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite3.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite4.sprite, NULL);
            sfRenderWindow_drawSprite(window, rock_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, bomb_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, spike_ball_sprite.sprite, NULL);
            sfRenderWindow_drawText(window, title2.text, NULL);
            sfRenderWindow_drawText(window, title1.text, NULL);
            sfRenderWindow_drawSprite(window, rings_w_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, ring_w_sprite2.sprite, NULL);
            sfRenderWindow_drawText(window, score1.text, NULL);
            sfRenderWindow_drawText(window, score2.text, NULL);
            sfRenderWindow_drawText(window, time1.text, NULL);
            sfRenderWindow_drawText(window, time2.text, NULL);
            sfRenderWindow_drawText(window, rings1.text, NULL);
            sfRenderWindow_drawText(window, rings2.text, NULL);
            sfRenderWindow_drawText(window, description1_1.text, NULL);
            sfRenderWindow_drawText(window, description1_2.text, NULL);
            sfRenderWindow_drawText(window, description2_1.text, NULL);
            sfRenderWindow_drawText(window, description2_2.text, NULL);
            sfRenderWindow_drawText(window, description3_1.text, NULL);
            sfRenderWindow_drawText(window, description3_2.text, NULL);
            sfRenderWindow_drawText(window, description4_1.text, NULL);
            sfRenderWindow_drawText(window, description4_2.text, NULL);
            sfRenderWindow_drawSprite(window, silver_sprite.sprite, NULL);
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            bkgd_sprites = is_reset_drag_needed(bkgd_sprites, max_w);
            path_sprites = is_reset_drag_needed(path_sprites, max_w);
            ice_sprites = is_reset_drag_needed(ice_sprites, max_w);
            bkgd_sprites = change_two_val(bkgd_sprites, 0, 1);
            path_sprites = change_two_val(path_sprites, 0, 5);
            ice_sprites = change_two_val(ice_sprites, 0, 10);
            silver_sprite = is_out_of_home(silver_sprite, 2);
            score = refresh_scores(score);
            rock_sprite.d.x -= 3;
            rock_sprite.d.y += 5;
            bomb_sprite.d.x -= 4;
            river_sprite.d.x -= 1;
            ring_w_sprite2.d.x -= 2;

        } else if (evt_actions.in_game == 2) {
            if (evt_actions.reset_scores == 1) {
                score = reset_scores(score);
            }
            if (time.current_play == when_does_it_end) {
                evt_actions.in_game = 3;
            }
            title_screen_music = stop_loaded_music(title_screen_music);
            sandstorm = play_loaded_music(sandstorm);
            is_it = is_smoothing_time(is_it, silvers, silver_sprite);
            bkgd_sprites = move_two_sprites(bkgd_sprites);
            path_sprites = move_two_sprites(path_sprites);
            ice_sprites = move_two_sprites(ice_sprites);
            silver_sprite = move_sprite_with_struct(silver_sprite);
            if (rock_sprite.d.x <= 0) {
                rock_sprite.d.x = max_w + rock_sprite.d.w +
                    randint(0, 900, 1);
            }
            if (rock_sprite.d.y >= max_h) {
                rock_sprite.d.y = (rock_sprite.d.h * -1);
            }
            rock_sprite = move_sprite_with_struct(rock_sprite);
            if (bomb_sprite.d.x <= 0) {
                bomb_sprite.d.x = max_w + bomb_sprite.d.x + randint(0, 900, 1);
                bomb_sprite.d.y = randint(600, 800, 1);
            }
            bomb_sprite = move_sprite_with_struct(bomb_sprite);
            if (river_sprite.d.x <= ((max_w) * -1)) {
                river_sprite.d.x = (max_w - 200);
            }
            river_sprite = move_sprite_with_struct(river_sprite);
            if (spike_ball_sprite.d.x <= 0) {
                spike_ball_sprite.d.x = max_w + spike_ball_sprite.d.w +
                    randint(0, 900, 1);
                spike_ball_sprite.d.y = randint(600, 800, 1);
            }
            spike_ball_sprite = move_sprite_with_struct(spike_ball_sprite);
            if (rocket_sprite.d.x <= 0) {
                rocket_sprite.d.x = max_w + rocket_sprite.d.w +
                    randint(0, 900, 1);
                rocket_sprite.d.y = randint(600, 800, 1);
            }
            rocket_sprite = move_sprite_with_struct(rocket_sprite);
            spike_sprite = move_sprite_with_struct(spike_sprite);
            ob2_sprite = move_sprite(ob2_sprite, ob2_x, ob2_y);
            title1 = move_text_using_strut(title1);
            title2 = move_text_using_strut(title2);
            description1_1 = move_text_using_strut(description1_1);
            description1_2 = move_text_using_strut(description1_2);
            description2_1 = move_text_using_strut(description2_1);
            description2_2 = move_text_using_strut(description2_2);
            description3_1 = move_text_using_strut(description3_1);
            description3_2 = move_text_using_strut(description3_2);
            description4_1 = move_text_using_strut(description4_1);
            description4_2 = move_text_using_strut(description4_2);
            button_sprite1 = move_sprite_with_struct(button_sprite1);
            button_sprite2 = move_sprite_with_struct(button_sprite2);
            button_sprite3 = move_sprite_with_struct(button_sprite3);
            button_sprite4 = move_sprite_with_struct(button_sprite4);
            score2 = update_text(score2, nb_to_char_star(score.total));
            time2 = update_text(time2, nb_to_char_star(score.time));
            if (score.rings > 0) {
                rings2 = update_text(rings2, nb_to_char_star(score.rings));
            }
            draw_two_sprites(window, bkgd_sprites, NULL);
            draw_two_sprites(window, path_sprites, NULL);
            draw_two_sprites(window, ice_sprites, NULL);
            sfRenderWindow_drawSprite(window, spike_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, ob2_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, rings_w_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, ring_w_sprite2.sprite, NULL);
            sfRenderWindow_drawText(window, score1.text, NULL);
            sfRenderWindow_drawText(window, score2.text, NULL);
            sfRenderWindow_drawText(window, time1.text, NULL);
            sfRenderWindow_drawText(window, time2.text, NULL);
            sfRenderWindow_drawText(window, rings1.text, NULL);
            sfRenderWindow_drawText(window, rings2.text, NULL);
            sfRenderWindow_drawSprite(window, rocket_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, rock_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, bomb_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, spike_ball_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, silver_sprite.sprite, NULL);
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            bkgd_sprites = is_reset_drag_needed(bkgd_sprites, max_w);
            path_sprites = is_reset_drag_needed(path_sprites, max_w);
            ice_sprites = is_reset_drag_needed(ice_sprites, max_w);
            bkgd_sprites = change_two_val(bkgd_sprites, 0, 1 +
                                          is_it.global_speed);
            path_sprites = change_two_val(path_sprites, 0, 5 +
                                          is_it.global_speed);
            ice_sprites = change_two_val(ice_sprites, 0, 10 +
                                         is_it.global_speed);

            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            // if (is_sprite_coliding(silver_sprite, asteroid_sprite) == 1) {
            //     evt_actions.in_game = 4;
            // }
            if (is_sprite_coliding(silver_sprite, bomb_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, river_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, spike_ball_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, rocket_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            // if (is_sprite_coliding(silver_sprite, rock_sprite) == 1) {
            //     evt_actions.in_game = 4;
            // }
            silver_sprite = is_out_of_home(silver_sprite, 2);
            spike_sprite.d.x += -5;
            ob2_x += -10;
            if (spike_sprite.d.x == 0) {
                spike_sprite.d.x = max_w;
            }
            if (ob2_x == 0) {
                ob2_x = max_w * 2;
            }
            if (ring_w_sprite2.d.x <= 0) {
                ring_w_sprite2.d.x = max_w + ring_w_sprite2.d.w;
            }
            if (is_sprite_coliding(silver_sprite, ring_w_sprite2) == 1) {
                ring_sound = play_loaded_music(ring_sound);
                score.rings++;
            }
            score.time++;
            score = refresh_scores(score);
            rock_sprite.d.x -= 3;
            rock_sprite.d.y += 5;
            bomb_sprite.d.x -= 4;
            river_sprite.d.x -= 1;
            spike_ball_sprite.d.x -= 2;
            ring_w_sprite2.d.x -= 2;
        } else {
            sandstorm = pause_loaded_music(sandstorm);
            title_screen_music = pause_loaded_music(title_screen_music);
            ends.window = window;
            ends.type = evt_actions.in_game;

            ends = display_correct_ending(ends, time, window);
            if (ends.sprite_won.anim.counter_reset == sfTrue) {
                time.won = 0;
                ends.sprite_won.anim.counter_reset = sfFalse;
            }
            if (ends.sprite_lost.anim.counter_reset == sfTrue) {
                time.lost = 0;
                ends.sprite_lost.anim.counter_reset = sfFalse;
            }
            time.won++;
            time.lost++;
        }

        sfRenderWindow_drawSprite(window, ring_w_sprite2.sprite, NULL);
        times_counter++;
    }
    sfRenderWindow_destroy(window);
    framebuffer_destroy(fb);
    free_two_sprites(bkgd_sprites);
    free_two_sprites(path_sprites);
    free_two_sprites(ice_sprites);
    free_sprite(silver_sprite);
    free_sprite(button_sprite1);
    free_sprite(button_sprite2);
    free_sprite(button_sprite3);
    free_sprite(ring_w_sprite2);
    free_sprite(rings_w_sprite);
    free_text(title1);
    free_text(title2);
    free_text(description1_1);
    free_text(description2_1);
    free_text(description3_1);
    free_text(description4_1);
    free_text(description1_2);
    free_text(description2_2);
    free_text(description3_2);
    free_text(description4_2);
    free_text(score1);
    free_text(score2);
    free_text(time1);
    free_text(time2);
    free_text(rings1);
    free_text(rings2);
    free_music(sandstorm);
    free_music(start_prog);
    free_music(title_screen_music);
    free_music(ring_sound);
    free_end(ends);

    return 0;
}