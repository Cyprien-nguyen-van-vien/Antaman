/*
** EPITECH PROJECT, 2021
** towrite.c
** File description:
** writing machine is not english
*/

#include "antman.h"

towrite *towrite_generate(int queue)
{
    towrite *writed = NULL;

    writed = malloc(sizeof(towrite));
    if (writed == NULL)
        return NULL;
    writed->value = '\0';
    writed->queue = queue;
    writed->next = NULL;
    return writed;
}

int towrite_delete_last(towrite *writed, bool printbefore, bool everything)
{
    if (writed == NULL)
        return 0;
    if (writed->next != NULL) {
        if (towrite_delete_last(writed->next, printbefore, everything))
            writed->next = NULL;
        if (!everything)
            return 0;
    }
    if (printbefore && writed->value != '\0')
        my_putchar(writed->value);
    free(writed);
    return 1;
}
