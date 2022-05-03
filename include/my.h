/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** mything
*/

#ifndef MYH
    #define MYH

    #define BUFF 2000000000
    #define EXIT 0
    #define ERROR 84
    #define ENDLESS 1
    #define POWER_OF_TWO(i) (1 << i)
    #define LINEBREAK '\n'
    #define ABS(x) ((x < 0) ? (0 - x) : (x))
    #define ISD(X) ('0' <= X && X <= '9')
    #define ISNOTD(X) (X < '0' || '9' < X)
    #define ITC(X) (X + '0')
    #define CTI(X) (X - '0')
    #define XOR(A, B) ((A || B) && !(A && B))
    #define STRLAST(X) (X[my_strlen(X) - 1])
    #define DUP(X) (my_strdup(X))
    #define STI(X) (my_str_to_int(X))
    #define STD(X) (my_str_to_double(X))
    #define ITS(X) (my_int_to_str(X))
    #define LEN(X) (my_strlen(X))
    #define REV(X) (my_revstr(X))

void my_putchar(char);
int my_putstr(char const *);
void my_putint(long int);
void my_putdouble(double number, int powerof10);
char *my_revstr(char *);
char *my_strcpy(char *destination, char const *copied);
char *my_strdup(char const *);
int my_strlen(char const *);
int my_str_to_int(char *);
double my_str_to_double(char *);
char *my_int_to_str(int);

#endif
