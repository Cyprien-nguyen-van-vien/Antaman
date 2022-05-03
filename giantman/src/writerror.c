/*
** EPITECH PROJECT, 2021
** writerror.c
** File description:
** Used to write errors, returning ERROR
*/

#include "antman.h"

int writerror(char const *msg)
{
    write(2, msg, LEN(msg));
    return ERROR;
}
