/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Requires my_putchar
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
