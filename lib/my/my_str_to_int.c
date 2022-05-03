/*
** EPITECH PROJECT, 2021
** my_str_to_int.c
** File description:
** No Requirement
*/

int my_str_to_int_cond(char *str, int i)
{
    if ('0' <= str[i] && str[i] <= '9')
        return (1);
    if (str[i] == '-')
        return (2);
    return (0);
}

int my_str_to_int_loop(char *str, int i)
{
    int nbr = 0;
    int mul = 1;

    for (i = i - 1; i > -1; i--) {
        if (my_str_to_int_cond(str, i) == 1) {
            nbr = nbr + (str[i] - '0') * mul;
            mul = mul * 10;
        }
        if (my_str_to_int_cond(str, i) == 2)
            nbr = 0 - nbr;
        if (my_str_to_int_cond(str, i) == 0) {
            nbr = 0;
            mul = 1;
        }
    }
    return (nbr);
}

int my_str_to_int(char *str)
{
    int i = 0;
    int nbr = 0;
    int mul = 1;

    while (str[i] != '\0')
        i++;
    return (my_str_to_int_loop(str, i));
}
