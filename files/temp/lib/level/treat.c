/*
** EPITECH PROJECT, 2021
** runner (Workspace)
** File description:
** treat.c
*/

#include "../../include/my_level.h"

char **treat_level(char *file_content)
{
    int i = 0;
    int content_length = my_strlen(file_content);
    char *level_content = malloc(sizeof(char) * content_length);
    char **final_list = malloc(sizeof(char) * content_length);
    char *temp = "";
    char **temp_list = malloc(sizeof(char) * 400);
    int index_track = 0;
    char *temp_content = malloc(sizeof(char) * content_length);
    int matrix = 0;
    int level_track = 0;
    int temp_track = 0;
    for (;i < content_length; i++) {
        my_putstr("temp_content = ");
        my_putchar(temp_content[i]);
        my_putchar('\n');
        if (file_content[i] == '|') {
            matrix++;
            temp_list[matrix] = "EOT";
            matrix = 0;
            sprite_element_t my_sprite = translate_sprite_level(temp_list);
            level_track++;
        }
        if (file_content[i] != '|' && file_content[i] == ',') {
            temp_list[matrix] = temp;
            temp = "";
            temp_track = 0;
            matrix++;
        }
        if (file_content[i] != '|' && file_content[i] != ',') {
            temp[temp_track] = file_content[i];
            temp_track++;
        }
    }
}