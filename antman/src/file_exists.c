/*
** EPITECH PROJECT, 2021
** file_exists.c
** File description:
** if a file exists
*/

#include "antman.h"

bool file_exists(char const *path)
{
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd <= 0) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

bool file_readable(char const *path)
{
    struct stat info;

    if (!file_exists(path))
        return false;
    stat(path, &info);
    if (info.st_mode & S_IRUSR)
        return true;
    if (info.st_mode & S_IRGRP)
        return true;
    if (info.st_mode & S_IROTH)
        return true;
    return false;
}
