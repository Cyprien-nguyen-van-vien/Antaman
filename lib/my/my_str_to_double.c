/*
** EPITECH PROJECT, 2021
** my_str_to_double.c
** File description:
** No Requirement
*/

int my_str_to_double_cond(char *str, int i)
{
    if ('0' <= str[i] && str[i] <= '9')
        return (1);
    if (str[i] == '-')
        return (2);
    return (0);
}

double my_str_to_double_loop(char *str, int i)
{
    double nbr = 0;
    int mul = 1;

    for (i = i - 1; i > -1; i--) {
        if (my_str_to_double_cond(str, i) == 1) {
            nbr = nbr + (str[i] - '0') * mul;
            mul = mul * 10;
        }
        if (my_str_to_double_cond(str, i) == 2)
            nbr = 0 - nbr;
        if (my_str_to_double_cond(str, i) == 0) {
            nbr = 0;
            mul = 1;
        }
    }
    return (nbr);
}

double my_str_to_double(char *str)
{
    int i = 0;
    double nbr = 0;
    int mul = 1;

    while (str[i] != '\0')
        i++;
    return (my_str_to_double_loop(str, i));
}
