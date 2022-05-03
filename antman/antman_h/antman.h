/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-antman-cyprien.nguyen-van-vien
** File description:
** antman.h
*/

#pragma once
    #define ER_MSG_SYNTAX "syntax error\n"
    #define ER_MSG_UNKNOW "unknown file\n"
    #define ER_MSG_UNREAD "unreadable file\n"

    #include "../../include/my.h"
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

typedef struct bytecomp {
    int size;
    bool bit[8];
} bytecomp;

typedef struct treepath {
    int size;
    bool path[100];
} treepath;

typedef struct bitpath {
    int size;
    bool path[100];
} bitpath;

typedef struct chardict {
    int size;
    char *key;
    int *nbr;
    bitpath *path;
} chardict;

int antman(int ac, char **av);
chardict *chardict_create(int size);
chardict *chardict_create_empty(void);
void chardict_free(chardict *);
void compress(char const *, chardict *);
void count_chars(char const *, chardict *dict, int start);
bool file_exists(char const *);
bool file_readable(char const *);
void generate_tree(chardict *);
void my_putstr3(char *, char *, char *);
int writerror(char const *);
