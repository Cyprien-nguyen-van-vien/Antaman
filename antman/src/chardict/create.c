/*
** EPITECH PROJECT, 2021
** chardict/create.c
** File description:
** cardiff/create
*/

#include "antman.h"

chardict *chardict_create_empty(void)
{
    chardict *dict = NULL;

    dict = malloc(sizeof(chardict));
    if (dict == NULL)
        return NULL;
    dict->size = 0;
    dict->key = NULL;
    dict->nbr = NULL;
    return dict;
}

void *chardict_complete(chardict *dict, int size)
{
    for (int i = 0; i < size; i++) {
        dict->key[i] = 0;
        dict->nbr[i] = 0;
        dict->path[i].size = 0;
        for (int j = 0; j < 100; j++)
            dict->path[i].path[j] = 0;
    }
}

chardict *chardict_create(int size)
{
    chardict *dict = NULL;

    dict = chardict_create_empty();
    if (dict == NULL)
        return NULL;
    dict->size = size;
    dict->key = malloc(sizeof(char) * size);
    dict->nbr = malloc(sizeof(int) * size);
    dict->path = malloc(sizeof(bitpath) * size);
    chardict_complete(dict, size);
    return dict;
}
