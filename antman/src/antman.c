/*
** EPITECH PROJECT, 2021
** antman.c
** File description:
** From tiny...
*/

#include "antman.h"

char *file_read(char const *path)
{
    int fd = 0;
    char *file = NULL;
    struct stat info;

    if (!file_exists(path))
        return NULL;
    fd = open(path, O_RDONLY);
    stat(path, &info);
    file = malloc(sizeof(char) * (info.st_size + 1));
    read(fd, file, info.st_size);
    file[info.st_size] = '\0';
    close(fd);
    return file;
}

int antman_compression(char *inp)
{
    chardict *dict = chardict_create(LEN(inp));

    count_chars(inp, dict, 0);
    for (int i = 0; i < dict->size; i++) {
        if (dict->nbr[i] > 0 && dict->key[i] == '\n')
            my_putstr("\\\\");
        if (dict->nbr[i] > 0 && dict->key[i] != '\n')
            my_putchar(dict->key[i]);
    }
    my_putchar(LINEBREAK);
    compress(inp, dict);
    chardict_free(dict);
    free(inp);
    return EXIT;
}

int antman(int ac, char **av)
{
    char *inp = NULL;

    if (ac != 3)
        return writerror(ER_MSG_SYNTAX);
    if (!file_exists(av[1]))
        return writerror(ER_MSG_UNKNOW);
    if (!file_readable(av[1]))
        return writerror(ER_MSG_UNREAD);
    if (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3')
        return writerror(ER_MSG_SYNTAX);
    if (av[2][1] != '\0')
        return writerror(ER_MSG_SYNTAX);
    inp = file_read(av[1]);
    return antman_compression(inp);
}
