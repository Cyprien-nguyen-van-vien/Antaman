/*
** EPITECH PROJECT, 2021
** antman.c
** File description:
** From tiny...
*/

#include "antman.h"

char *file_read(char const *path, struct stat *info)
{
    int fd = 0;
    char *file = NULL;

    if (!file_exists(path))
        return NULL;
    fd = open(path, O_RDONLY);
    stat(path, info);
    file = malloc(sizeof(char) * (info->st_size + 1));
    read(fd, file, info->st_size);
    file[info->st_size] = '\0';
    close(fd);
    return file;
}

int get_linebreak_index(char const *str)
{
    int i = 0;
    int linebreaks = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        if (str[i] == '\\' && str[i + 1] == '\\') {
            linebreaks += 1;
            i++;
        }
        i++;
    }
    if (str[i] == '\n')
        return i - linebreaks;
    return -1;
}

chardict *input_in_dict(chardict *dict, char const *inp)
{
    int breaks = 0;
    int size = dict->size;

    for (int i = 0; i < size; i++) {
        if (inp[i + breaks] == '\\' && inp[i + breaks + 1] == '\\') {
            dict->key[i] = '\n';
            breaks++;
        } else {
            dict->key[i] = inp[i + breaks];
        }
    }
}

int giantman_decompression(char *inp, size_t bytes)
{
    int length = LEN(inp);
    int sep = get_linebreak_index(inp);
    chardict *dict = chardict_create(sep);

    input_in_dict(dict, inp);
    decompress(inp, dict, bytes);
    chardict_free(dict);
    free(inp);
    return EXIT;
}

int antman(int ac, char **av)
{
    struct stat bytes;
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
    inp = file_read(av[1], &bytes);
    return giantman_decompression(inp, bytes.st_size);
}
