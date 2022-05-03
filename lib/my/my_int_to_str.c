/*
** EPITECH PROJECT, 2021
** my_int_to_str.c
** File description:
** Requires my_revstr
*/

#include <stdlib.h>

char *my_revstr(char *);

int my_int_to_str_s(int val)
{
    int i = 0;

    if (val < 0) {
        val *= -1;
        i++;
    }
    for (i = i; val != 0; i++) {
        val /= 10;
        i++;
    }
    if (i == 0)
        i = 1;
    return i;
}

char *my_int_to_str_s2(char *str, int val, int n, int i)
{
    for (i = i; val != 0; i++) {
        str[i] = val % 10 + '0';
        val /= 10;
    }
    if (n == 1) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *my_int_to_str(int val)
{
    int len = my_int_to_str_s(val) + 1;
    char *str = malloc(sizeof(char) * len);
    int i = 0;
    int n = 0;

    if (val == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if (val < 0) {
        val *= -1;
        n = 1;
    }
    return my_int_to_str_s2(str, val, n, i);
}
