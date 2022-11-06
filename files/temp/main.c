/*
** EPITECH PROJECT, 2021
** get_csfml_keys (Workspace)
** File description:
** main.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

int main()
{
    char *image_path = "img/sprite_test.png";
    char *font_path = "html/font/css/fonts/Algerian Regular/Algerian Regular.ttf";//s_f_f_d/NiseSegaSonic.ttf";
    char *music_path = "ogg/facebook_pop.ogg";
    sfVideoMode mode = { 800, 600, 32 };
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfMusic *music;
    sfEvent event;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    /* Load a sprite to display */
    texture = sfTexture_createFromFile(image_path, NULL);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    /* Create a graphical text to display */
    font = sfFont_createFromFile(font_path);
    if (!font)
        return EXIT_FAILURE;
    text = sfText_create();
    sfText_setString(text, "Hello CSFML");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    /* Load a music to play */
    music = sfMusic_createFromFile(music_path);
    if (!music)
        return EXIT_FAILURE;
    /* Play the music */
    sfMusic_play(music);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        /* Draw the sprite */
        sfRenderWindow_drawSprite(window, sprite, NULL);
        /* Draw the text */
        sfRenderWindow_drawText(window, text, NULL);
        /* Update the window */
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfMusic_destroy(music);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}