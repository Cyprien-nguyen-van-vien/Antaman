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

typedef struct treehuff treehuff;
typedef struct towrite towrite;

typedef struct towrite {
    int queue;
    char value;
    towrite *next;
} towrite;

typedef struct byteread {
    int read;
    int size;
    int index;
    bool bit[8];
    char value;
    char const *string;
} byteread;

typedef struct bitpath {
    int size;
    bool path[100];
} bitpath;

typedef struct treehuff {
    bool isleaf;
    char leaf;
    treehuff *to0;
    treehuff *to1;
} treehuff;

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
void count_chars(char const *, chardict *dict, int start);
void decompress(char const *, chardict *, size_t bytes);
bool file_exists(char const *);
bool file_readable(char const *);
treehuff *generate_tree(chardict *);
int get_linebreak_index(char const *);
void my_putstr3(char *, char *, char *);
int towrite_delete_last(towrite *, bool printbefore, bool everything);
towrite *towrite_generate(int queue);
void treehuff_free(treehuff *);
int writerror(char const *);
