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

void free_hex_dict(dict_t **dictionary)
{
    dict_t *tmp = NULL;
    if (dictionary == NULL) {
        return;
    }
    while (dictionary != NULL) {
        free((*dictionary)->key);
        free((*dictionary)->value);
        tmp = (*dictionary);
        (*dictionary) = (*dictionary)->next;
        free(tmp);
    }
    if (dictionary != NULL) {
        dict_free(dictionary);
    }
}

char *handle_key(int i, const char *hex_letters)
{
    char *key = malloc(sizeof(char) * 2);
    key[1] = '\0';
    if (i < 10) {
        key[0] = i + '0';
    } else {
        key[0] = hex_letters[i - 10];
    }
    return key;
}

dict_t **create_hex_dict()
{
    char *hex_letters = "ABCDEF";
    dict_t **hex_dict = create_dict();
    for (int i = 0; i < 16; i++) {
        char *key = handle_key(i, hex_letters);
        int *value = malloc(sizeof(int));
        *value = i;
        add_item(hex_dict, key, value);
    }
    return hex_dict;
}

char make_mono_hex(const char c)
{
    if (c >= '0' && c <= '9') {
        return c;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 32;
    }
    if (c >= 'A' && c <= 'F') {
        return c;
    }

    return '\0';
}

int to_decimal(char *hex_code)
{
    int result = 0;
    int value = 0;
    char c = '\0';
    for (int i = 0; i < my_strlen(hex_code); i++) {
        c = make_mono_hex(hex_code[i]);
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else {
            value = c - 'A' + 10;
        }
        result = result * 16 + value;
    }
    return result;
}
