/*
** EPITECH PROJECT, 2021
** get_csfml_keys - title_screen_retry.c
** File description:
** jitter jitter
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
#include "include/my_game_elements.h"
#include "include/my_end.h"
#include "include/my_root.h"
#include "include/my_scores.h"
#include "include/my_image.h"
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
    two_sprites_t bkgd_sprites = load_two_sprite(path1, path1, 1 + inc_factor_w,
                                                 0.5 + inc_factor_h);
    // path image settings //
    two_sprites_t path_sprites = load_two_sprite(path2, path2, 1 + inc_factor_w,
                                                 0.7 + inc_factor_h);//0.5);
                                                // ice image settings //
    two_sprites_t ice_sprites = load_two_sprite(path3, path3, 1 + inc_factor_w,
                                                1 + inc_factor_h);
    // background sprites //
    if (bkgd_sprites.status == 84 || path_sprites.status == 84
        || ice_sprites.status == 84) {
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


int launch_game(void) {
    music_status_t sandstorm;
    sandstorm.path = "ogg/darun_sandstorm.ogg";
    audio_status_t start_game;
    start_game.path = "ogg/facebook_pop.ogg";// ignore
    music_status_t start_prog;
    start_prog.path = "ogg/Win_95_bootup.ogg";
    music_status_t title_screen_music;
    title_screen_music.path = "ogg/Flying_Battery_Zone_Act_2_-_Sonic_Mania_OST.ogg";
    music_status_t ring_sound;
    ring_sound.path = "ogg/ring.ogg";
    find_images_t my_images = init_images();
    char *asteroid_path = "img/enemies/asteroid.png";
    char *bomb_path = "img/enemies/bomb.png";
    char *river_path = "img/enemies/frozen river.png";
    char *spike_ball_path = "img/enemies/spike_ball.png";
    char *button_path = "img/title_screen/button_sprite.png";
    char *background_image_path = "img/background/final_background.png";
    char *path_image_path = "img/background/path_final.png";
    char *ice_image_path = "img/background/ice_final.png";
    char *silver_s_path = "img/sprite/silver/silver_running_very_slow.png";
    char *silver_n_path = "img/sprite/silver/silver_running_slow.png";
    char *silver_f_path = "img/sprite/silver/silver_running_fast.png";
    char *end_sprite_won_path = "img/ending/eggman_end.png";
    char *end_sprite_lost_path = "img/ending/silver_loading.png";
    char *coins_path = "img/bonuses/blue ring_shrunk.png";
    char *rings_winter_path = "img/bonuses/coin_winter_spritesheet.png";
    char *rocket_path = "img/enemies/rk2.png";
    image_paths_t walls_path;
    walls_path.path1 = "img/obstacles/ice_cube_block.png";
    walls_path.path2 = "img/obstacles/ice_cube_only.png";
    walls_path.path3 = "img/obstacles/snow_cap.png";
    walls_path.path4 = "img/obstacles/platform.png";

    char *spike_path = "img/enemies/spike.png";
    char *obstacle2_path = "img/spike-ball.png";

    sfRenderWindow *window;
    framebuffer_t *fb;

    sandstorm = load_music(sandstorm, sfTrue);
    start_prog = load_music(start_prog, sfFalse);

    title_screen_music = load_music(title_screen_music, sfFalse);
    ring_sound = load_music(ring_sound, sfFalse);

    /* Window size */
    float border_score_width = 1;
    text_t score1 = init_text("score: ", 3, 50);
    score1 = set_colors(score1, rgba(249, 235, 0, 1), rgba(0, 0, 0, 1));
    score1 = set_more_info(score1, border_score_width, 0, sfTextBold);

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
    scale.x = 30;
    scale.y = sfTrue;
    // scale.y = sfFalse;
    // button //
    sprite_t button_sprite1 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite2 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite3 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite4 = load_n_size(button_path,
                                          initialise_sffloatrect(0, 0, 276, 44),
                                          initialise_sfintrect(0, 0, 138, 44),
                                          scale);
    sprite_t button_sprite_restart = load_n_size(button_path,
                                                 initialise_sffloatrect(0, 0, 276, 44),
                                                 initialise_sfintrect(0, 0, 138, 44),
                                                 scale);
    text_t title1 = init_text("SILVER", 1, 100);
    title1 = set_colors(title1, rgba(192, 192, 192, 1), rgba(211, 211, 211, 1));
    title1 = set_more_info(title1, 10, 0, sfTextBold);
    title1 = text_positioning(title1, 0, 200, 2.0);
    text_t title2 = init_text("RUNNER", 1, 100);
    title2 = set_colors(title2, rgba(192, 192, 192, 1), rgba(211, 211, 211, 1));
    title2 = set_more_info(title2, 10, 0, sfTextBold | sfTextItalic);
    title2 = text_positioning(title2, -600, 200, 2.0);
    text_t description1_1 = init_text("Play Game", 2, 30);
    description1_1 = set_colors(description1_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description1_1 = set_more_info(description1_1, 3.5, 0, sfTextBold);
    text_t description2_1 = init_text("How To", 2, 30);
    description2_1 = set_colors(description2_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description2_1 = set_more_info(description2_1, 3.5, 0, sfTextBold);
    text_t description3_1 = init_text("Credits", 2, 30);
    description3_1 = set_colors(description3_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description3_1 = set_more_info(description3_1, 3.5, 0, sfTextBold);
    text_t description4_1 = init_text("Exit", 2, 30);
    description4_1 = set_colors(description4_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description4_1 = set_more_info(description4_1, 3.5, 0, sfTextBold);
    text_t restart5_1 = init_text("Restart", 2, 30);
    restart5_1 = set_colors(restart5_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    restart5_1 = set_more_info(restart5_1, 3.5, 0, sfTextBold);
    text_t main_menu6_1 = init_text("Main Menu", 2, 30);
    main_menu6_1 = set_colors(main_menu6_1, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    main_menu6_1 = set_more_info(main_menu6_1, 3.5, 0, sfTextBold);

    text_t description1_2 = init_text("(SPACE)", 2, 15);
    description1_2 = set_colors(description1_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description1_2 = set_more_info(description1_2, 3.5, 0, sfTextBold);
    text_t description2_2 = init_text("(H)", 2, 15);
    description2_2 = set_colors(description2_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description2_2 = set_more_info(description2_2, 3.5, 0, sfTextBold);
    text_t description3_2 = init_text("(C)", 2, 15);
    description3_2 = set_colors(description3_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description3_2 = set_more_info(description3_2, 3.5, 0, sfTextBold);
    text_t description4_2 = init_text("(ESC)", 2, 15);
    description4_2 = set_colors(description4_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    description4_2 = set_more_info(description4_2, 3.5, 0, sfTextBold);
    text_t restart5_2 = init_text("(R)", 2, 15);
    restart5_2 = set_colors(restart5_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    restart5_2 = set_more_info(restart5_2, 3.5, 0, sfTextBold);
    text_t main_menu6_2 = init_text("(M)", 2, 15);
    main_menu6_2 = set_colors(main_menu6_2, rgba(250, 255, 255, 1), rgba(0, 155, 255, 1));
    main_menu6_2 = set_more_info(main_menu6_2, 3.5, 0, sfTextBold);
    int common_y = 920;
    description1_1.y = common_y + 10;
    description2_1.y = common_y + 10;
    description3_1.y = common_y + 10;
    description4_1.y = common_y + 10;
    description1_2.y = common_y + 20;
    description2_2.y = common_y + 20;
    description3_2.y = common_y + 20;
    description4_2.y = common_y + 20;
    button_sprite1.y = common_y;
    button_sprite2.y = common_y;
    button_sprite3.y = common_y;
    button_sprite4.y = common_y;
    description1_1.x = -300;
    description2_1.x = -300;
    description3_1.x = -300;
    description4_1.x = -300;
    description1_2.x = -214;
    description2_2.x = -180;
    description3_2.x = -180;
    description4_2.x = -210;
    button_sprite1.x = -325;
    button_sprite2.x = -325;
    button_sprite3.x = -325;
    button_sprite4.x = -325;

    // walls //
    dimensions_for_4_assets_t dims;
    dims.dim1 = assing_dim_for_an_asset(749, 810);
    dims.dim2 = assing_dim_for_an_asset(708, 804);
    dims.dim3 = assing_dim_for_an_asset(572, 110);
    dims.dim4 = assing_dim_for_an_asset(2513, 815);
    assets_t walls = load_4_assets(walls_path, dims);

    // end image //
    scale.x = 60;
    scale.y = sfTrue;
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
    ends.restart_text1 = restart5_1;
    ends.restart_text2 = restart5_2;
    ends.button_restart = button_sprite_restart;
    ends.main_menu_text1 = main_menu6_1;
    ends.main_menu_text2 = main_menu6_2;
    my_putstr("end_image sprite initialised\n");
    // spike //
    scale.y = sfFalse;
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
    scale.x = 90;
    sprite_t spike_ball_sprite = load_n_size(spike_ball_path,
                                             initialise_sffloatrect(0, 0, 72,
                                                                    17),
                                             initialise_sfintrect(0, 0, 18, 17),
                                             scale);
    spike_ball_sprite.anim.max_ticks = 35;
    spike_ball_sprite.anim.step_w = 18;
    spike_ball_sprite.anim.wrap = sfTrue;
    spike_ball_sprite = move_sprite(spike_ball_sprite, max_width - 30, 650);
    scale.y = sfFalse;
    scale.x = 60;
    my_putstr("obstacle 2 sprite initialised\n");
    // rocket //
    scale.x = 200;
    sprite_t rocket_sprite = load_n_size(rocket_path,
                                         initialise_sffloatrect(0, 0, 234, 12),
                                         initialise_sfintrect(0, 0, 56, 12),
                                         scale);
    rocket_sprite.anim.max_ticks = 5;
    rocket_sprite.anim.step_w = 56;
    rocket_sprite.anim.wrap = sfTrue;
    rocket_sprite = move_sprite(rocket_sprite, max_width - 30, 650);
    scale.x = 60;
    // Coins_winter //
    sprite_t rings_w_sprite = load_n_size(rings_winter_path,
                                          initialise_sffloatrect(0, 0, 1782,
                                                                 66),
                                          initialise_sfintrect(0, 0, 66, 66),
                                          scale);
    // rings_w_sprite //
    rings_w_sprite.anim.max_ticks = 5;
    rings_w_sprite.anim.step_w = 66;
    rings_w_sprite.anim.wrap = sfTrue;
    rings_w_sprite = move_sprite(rings_w_sprite, 0, 14);
    sprite_t ring_w_sprite2 = load_n_size(rings_winter_path,
                                          initialise_sffloatrect(0, 0, 1782,
                                                                 66),
                                          initialise_sfintrect(0, 0, 66, 66),
                                          scale); //dup_sprite((const sprite_t)rings_w_sprite);

    ring_w_sprite2.anim.max_ticks = 5;
    ring_w_sprite2.anim.step_w = 66;
    ring_w_sprite2.anim.wrap = sfTrue;
    ring_w_sprite2 = move_sprite(ring_w_sprite2, 0, 681);//14);
    my_putstr("Coins winter initialised.\n");
    // character //
    scale.y = 1;
    silver_states_t silvers = load_the_silvers(silver_s_path, silver_n_path,
                                               silver_f_path, scale);
    sprite_t silver_sprite = silvers.silver_f_sprite;
    silver_sprite.home_position.x = 150;
    silver_sprite.home_position.y = 680;
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
    int ob2_x = max_width * 2;
    int ob2_y = characters_y;
    int in_game = 1;
    int j = 1;
    if (randint(0, 10, 1) == 5) {
        j = 0;
    }
    unsigned int when_does_it_end = 200000000;
    my_putstr("more basic vars initialised\n");
    /* mouse */
    mouse_trac_t mouse_sprite = init_mouse(event, rings_w_sprite, 0);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfClock *hourglass = sfClock_create();
    sfTime delta_time = sfTime_Zero;
    unsigned long int times_counter = 0;
    int track_animation = 0;
    int track_animation_to_add = rings_w_sprite.sprite_rect.width;

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
        evt_actions.buttons = initialise_button(button_sprite1, button_sprite2,
                                                button_sprite3, button_sprite4);
        evt_actions.buttons.restart = button_sprite_restart;
        // evt_actions.change_to_game = start_game;
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
            // start_game.was_played = evt_actions.change_to_game.was_played;
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
        asteroid_sprite = next_frame(asteroid_sprite, time.asteroid);
        if (asteroid_sprite.anim.counter_reset == sfTrue) {
            time.asteroid = 0;
            asteroid_sprite.anim.counter_reset = sfFalse;
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
        // printf("silver_sprite.x = %d | silver_sprite.y = %d\n", silver_sprite.x, silver_sprite.y);
        if (evt_actions.in_game == 1) {
            if (evt_actions.reset_scores == 1) {
                score = reset_scores(score);
            }
            // start_game = play_loaded_audio(start_game);
            if (start_prog.was_played == 1 || j == 0) {
                title_screen_music = play_loaded_music(title_screen_music);
            }
            if (start_prog.was_played == 0 && j == 1) {
                start_prog = play_loaded_music(start_prog);
            }
            sandstorm = stop_loaded_music(sandstorm);
            // Background //
            bkgd_sprites = move_two_sprites(bkgd_sprites);
            // path //
            path_sprites = move_two_sprites(path_sprites);
            // // ice //
            ice_sprites = move_two_sprites(ice_sprites);
            // silver //
            silver_sprite = move_sprite(silver_sprite, silver_sprite.x, silver_sprite.y);
            printf("silver_sprite.x = %d | silver_sprite.y = %d\n", silver_sprite.x, silver_sprite.y);
            // coin_w_sprite //
            // rings_w_sprite = move_sprite(rings_w_sprite, 10, 10);
            if (title1.x < 500) {
                title1.x += 2;
            }
            if (title2.x < 1050 && title1.x == 500) {
                title2.x += 10;
            }
            if (description1_1.x < 100 && title2.x == 1050) {
                description1_1.x += 5;
                description1_2.x += 6;
                button_sprite1.x += 5;
            }
            if (description2_1.x < 600 && description1_1.x == 100) {
                description2_1.x += 10;
                description2_2.x += 10;
                button_sprite2.x += 10;
            }
            if (description3_1.x < 900 && description2_1.x == 600) {
                description3_1.x += 15;
                description3_2.x += 15;
                button_sprite3.x += 15;
            }
            if (description4_1.x < 1280 && description3_1.x == 900) {
                description4_1.x += 20;
                description4_2.x += 20;
                button_sprite4.x += 20;
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
            button_sprite1 = move_sprite_with_s_x_n_y(button_sprite1);
            button_sprite2 = move_sprite_with_s_x_n_y(button_sprite2);
            button_sprite3 = move_sprite_with_s_x_n_y(button_sprite3);
            button_sprite4 = move_sprite_with_s_x_n_y(button_sprite4);
            score2 = update_text(score2, nb_to_char_star(score.total));
            time2 = update_text(time2, nb_to_char_star(score.time));
            if (score.rings > 0) {
                rings2 = update_text(rings2, nb_to_char_star(score.rings));
            }
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
            if (river_sprite.x <= ((max_width) * -1)) {
                river_sprite.x = (max_width - 200);
            }
            river_sprite = move_sprite_with_s_x_n_y(river_sprite);
            if (spike_ball_sprite.x <= 0) {
                spike_ball_sprite.x = max_width + spike_ball_sprite.w;
            }
            spike_ball_sprite = move_sprite_with_s_x_n_y(spike_ball_sprite);
            if (rocket_sprite.x <= 0) {
                rocket_sprite.x = max_width + rocket_sprite.w;
            }
            rocket_sprite = move_sprite_with_s_x_n_y(rocket_sprite);
            if (ring_w_sprite2.x <= 0) {
                ring_w_sprite2.x = max_width + ring_w_sprite2.w;
                ring_w_sprite2 = randomise_sprite_pos_y(ring_w_sprite2, 600,
                                                        700);
            }
            if (is_sprite_coliding(silver_sprite, ring_w_sprite2) == 1) {
                ring_sound = play_as_sound(ring_sound);
                score.rings++;
            }
            ring_w_sprite2 = move_sprite_with_s_x_n_y(ring_w_sprite2);
            // if (ring)
            draw_two_sprites(window, bkgd_sprites, NULL);
            // path //
            draw_two_sprites(window, path_sprites, NULL);
            // ice //
            draw_two_sprites(window, ice_sprites, NULL);
            // river //
            sfRenderWindow_drawSprite(window, river_sprite.sprite, NULL);
            // silver //
            sfRenderWindow_drawSprite(window, rocket_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite1.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite2.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite3.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite4.sprite, NULL);
            sfRenderWindow_drawSprite(window, asteroid_sprite.sprite, NULL);
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
            silver_sprite = is_out_of_home(silver_sprite, 2);
            score = refresh_scores(score);
            asteroid_sprite.x -= 3;
            asteroid_sprite.y += 5;
            bomb_sprite.x -= 4;
            river_sprite.x -= 1;
            ring_w_sprite2.x -= 2;

        } else if (evt_actions.in_game == 2) {
            if (evt_actions.reset_scores == 1) {
                score = reset_scores(score);
            }
            // play_loaded_audio
            if (time.current_play == when_does_it_end) {
                evt_actions.in_game = 3;
            }
            // char **level_map = ;
            title_screen_music = stop_loaded_music(title_screen_music);
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
            // silver //
            silver_sprite = move_sprite_with_s_x_n_y(silver_sprite);
            if (asteroid_sprite.x <= 0) {
                asteroid_sprite.x = max_width + asteroid_sprite.w +
                    randint(0, 900, 1);
            }
            if (asteroid_sprite.y >= max_height) {
                asteroid_sprite.y = (asteroid_sprite.h * -1);
            }
            asteroid_sprite = move_sprite_with_s_x_n_y(asteroid_sprite);
            if (bomb_sprite.x <= 0) {
                bomb_sprite.x = max_width + bomb_sprite.x + randint(0, 900, 1);
                bomb_sprite.y = randint(600, 800, 1);
            }
            bomb_sprite = move_sprite_with_s_x_n_y(bomb_sprite);
            if (river_sprite.x <= ((max_width) * -1)) {
                river_sprite.x = (max_width - 200);
            }
            river_sprite = move_sprite_with_s_x_n_y(river_sprite);
            if (spike_ball_sprite.x <= 0) {
                spike_ball_sprite.x = max_width + spike_ball_sprite.w +
                    randint(0, 900, 1);
                spike_ball_sprite.y = randint(600, 800, 1);
            }
            spike_ball_sprite = move_sprite_with_s_x_n_y(spike_ball_sprite);
            if (rocket_sprite.x <= 0) {
                rocket_sprite.x = max_width + rocket_sprite.w +
                    randint(0, 900, 1);
                rocket_sprite.y = randint(600, 800, 1);
            }
            rocket_sprite = move_sprite_with_s_x_n_y(rocket_sprite);
            // obstacle 1 //
            spike_sprite = move_sprite_with_s_x_n_y(spike_sprite);
            // obstacle 2 //
            ob2_sprite = move_sprite(ob2_sprite, ob2_x, ob2_y);
            // coin_w_sprite //
            /* Display sprites in the window */
            // background //
            draw_two_sprites(window, bkgd_sprites, NULL);
            // path //
            draw_two_sprites(window, path_sprites, NULL);
            // ice //
            draw_two_sprites(window, ice_sprites, NULL);
            // silver //
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
            sfRenderWindow_drawSprite(window, button_sprite1.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite2.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite3.sprite, NULL);
            sfRenderWindow_drawSprite(window, button_sprite4.sprite, NULL);
            sfRenderWindow_drawSprite(window, asteroid_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, bomb_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, spike_ball_sprite.sprite, NULL);
            sfRenderWindow_drawSprite(window, silver_sprite.sprite, NULL);
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
            bkgd_sprites = change_two_val(bkgd_sprites, 0, 1 +
                                          is_it.global_speed);
            // path //
            path_sprites = change_two_val(path_sprites, 0, 5 +
                                          is_it.global_speed);
            // ice //
            ice_sprites = change_two_val(ice_sprites, 0, 10 +
                                         is_it.global_speed);
            // y++;

            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, spike_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            if (is_sprite_coliding(silver_sprite, ob2_sprite) == 1) {
                evt_actions.in_game = 4;
            }
            silver_sprite = is_out_of_home(silver_sprite, 2);
            // x += amount_to_add;
            spike_sprite.x += -5;
            ob2_x += -10;
            if (spike_sprite.x == 0) {
                spike_sprite.x = max_width;
            }
            if (ob2_x == 0) {
                ob2_x = max_width * 2;
            }
            if (ring_w_sprite2.x <= 0) {
                ring_w_sprite2.x = max_width + ring_w_sprite2.w;
            }
            if (is_sprite_coliding(silver_sprite, ring_w_sprite2) == 1) {
                ring_sound = play_loaded_music(ring_sound);
                score.rings++;
            }
            score.time++;
            score = refresh_scores(score);
            asteroid_sprite.x -= 3;
            asteroid_sprite.y += 5;
            bomb_sprite.x -= 4;
            river_sprite.x -= 1;
            spike_ball_sprite.x -= 2;
            ring_w_sprite2.x -= 2;
        } else {
            sandstorm = pause_loaded_music(sandstorm);
            title_screen_music = pause_loaded_music(title_screen_music);
            ends.window = window;
            ends.type = in_game;

            ends = display_correct_ending(ends, time);
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
            if (ends.type == 3) {
                ends.sprite_won = move_sprite(ends.sprite_won, 900, 450);
                sfRenderWindow_drawSprite(window, ends.sprite_won.sprite, NULL);
            } else {
                sfRenderWindow_drawSprite(window, ends.sprite_lost.sprite, NULL);
            }
            sfRenderWindow_drawSprite(window, ends.button_restart.sprite, NULL);
            sfRenderWindow_drawText(window, ends.restart_text1.text, NULL);
            sfRenderWindow_drawText(window, ends.restart_text2.text, NULL);
            sfRenderWindow_drawText(window, ends.main_menu_text1.text, NULL);
            sfRenderWindow_drawText(window, ends.main_menu_text2.text, NULL);
            sfRenderWindow_display(window);
            if (in_game == 3) {
                sfRenderWindow_clear(window, sfBlack);
            } else if (in_game == 4) {
                sfRenderWindow_clear(window, sfBlue);
            } else {
                sfRenderWindow_clear(window, sfGreen);
            }
        }

        sfRenderWindow_drawSprite(window, ring_w_sprite2.sprite, NULL);
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
    // free_sprite(button_sprite_restart);
    // coins_sprite //
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
    // free_audio(start_game);

    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        return launch_game();
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("In help\n");
    } else if (argc > 2 || (argv[1][0] == '-' && argv[1][1] == 'h')) {
        my_putstr("Do a deeper annalyssis\n");
    }
}