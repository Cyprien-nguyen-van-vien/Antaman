/*
** EPITECH PROJECT, 2021
** count_chars.c
** File description:
** 1, 2, 3 soleil
*/

#include "antman.h"

int count_chars_seg(char const *inp, chardict *dict, int start)
{
    int i = 0;

    if (inp[start] == '\0')
        return 0;
    for (i = 0; i < dict->size && dict->nbr[i] > 0; i++) {
        if (inp[start] == dict->key[i]) {
            dict->nbr[i] += 1;
            return 1;
        }
    }
    dict->key[i] = inp[start];
    dict->nbr[i] += 1;
    return 1;
}

void count_chars(char const *inp, chardict *dict, int start)
{
    int i = start;
    int returned = 1;

    while (returned == 1) {
        returned = count_chars_seg(inp, dict, i);
        i++;
    }
}
