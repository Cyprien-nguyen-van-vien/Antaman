/*
** EPITECH PROJECT, 2021
** chardict/free.c
** File description:
** cardiff/free
*/

#include "antman.h"

void chardict_free(chardict *dict)
{
    if (dict == NULL)
        return;
    if (dict->key != NULL)
        free(dict->key);
    if (dict->nbr != NULL)
        free(dict->nbr);
    if (dict->path != NULL)
        free(dict->path);
    free(dict);
}
