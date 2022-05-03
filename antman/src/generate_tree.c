/*
** EPITECH PROJECT, 2021
** generate_tree.c
** File description:
** you could for sure use seeds instead
*/

#include "antman.h"

int find_optimized_sep(chardict *dict, int first, int last)
{
    int best = (last + first + 1) / 2;

    return best;
}

int generate_tree_join(chardict *dict, bitpath path, int first, int last)
{
    int size = 0;
    int sep = 0;

    if (first < last) {
        sep = find_optimized_sep(dict, first, last);
        path.size += 1;
        path.path[path.size - 1] = 0;
        size += generate_tree_join(dict, path, first, sep - 1);
        path.path[path.size - 1] = 1;
        size += generate_tree_join(dict, path, sep, last);
    } else {
        size = path.size;
        dict->path[first].size = path.size;
        for (int i = 0; i < path.size; i++)
            dict->path[first].path[i] = path.path[i];
    }
    return size;
}

void generate_tree(chardict *dict)
{
    int size = 0;
    bitpath path = {0, {0}};

    for (int i = 0; i < dict->size; i++)
        if (dict->nbr[i] > 0)
            size++;
    generate_tree_join(dict, path, 0, size - 1);
    return;
}
