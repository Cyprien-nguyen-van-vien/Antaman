/*
** EPITECH PROJECT, 2021
** compress.c
** File description:
** hydrolic
*/

#include "antman.h"

int display_bytecomp(bytecomp *byte)
{
    int comp = 0;
    int size = 0;

    byte->size -= 8;
    if (byte->size < 0)
        byte->size = 0;
    size = byte->size;
    for (int i = 7; i >= 0; i--) {
        comp *= 2;
        if (i < byte->size)
            comp += 0;
        else
            comp += byte->bit[i];
    }
    my_putchar(comp);
}

int display_bitpath(bitpath path, bytecomp *byte)
{
    int size = path.size;

    for (int i = 0; i < size; i++) {
        byte->bit[byte->size] = path.path[i];
        byte->size += 1;
        if (byte->size >= 8)
            display_bytecomp(byte);
    }
    return size;
}

int compress_char(char const c, chardict *dict, bytecomp *byte)
{
    int size = dict->size;

    for (int i = 0; i < size; i++)
        if (c == dict->key[i])
            return display_bitpath(dict->path[i], byte);
}

void compress(char const *inp, chardict *dict)
{
    int leftovers = 0;
    bytecomp *byte = NULL;

    generate_tree(dict);
    byte = malloc(sizeof(bytecomp));
    byte->size = 0;
    for (int i = 0; i < 8; i++)
        byte->bit[i] = 0;
    for (int i = 0; inp[i] != '\0'; i++)
        compress_char(inp[i], dict, byte);
    byte->size;
    leftovers = (8 - byte->size) / dict->path[0].size;
    while (byte->size > 0)
        display_bytecomp(byte);
    my_putchar('0' + leftovers);
    free(byte);
}
