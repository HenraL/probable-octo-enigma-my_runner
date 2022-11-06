/*
** EPITECH PROJECT, 2021
** my_runner (Workspace)
** File description:
** hex_to_255.c
*/

#include "../../include/my_lib.h"
#include "../../include/my_convert.h"
#include "../../include/my_dict.h"
#include <stdlib.h>

dict_t **create_hex_dict()
{
    char *hex_letters = "ABCDEF";
    dict_t **hex_dict = create_dict();
    int i = 0;
    for (; i < 16; i++) {
        if (i < 10) {
            add_item(hex_dict, i + '0', i);
        }
        if (i > 9) {
            add_item(hex_dict, hex_letters[i / 10], i);
        }
    }
    return hex_dict;
}

char *make_mono_hex()
{
    int a = 0;
    char *hex_letters = "abcdefgh";
    dict_t **hex_dict = create_hex_dict();
    int i = 0;
    for (; i < 17; i++) {
        if (my_str_isnum(i) < 10) {
            a = 0;
        } else {
            a = 0;
        }
    }

}

int to_decimal(char *hex_code)
{
    char mono_hex = make_mono_hex();
    int i = 0;
    int result;
    for (; i < my_strlen(hex_code); i++) {

    }
    return result;

}