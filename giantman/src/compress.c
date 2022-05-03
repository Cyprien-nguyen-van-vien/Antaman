/*
** EPITECH PROJECT, 2021
** compress.c
** File description:
** hydrolic
*/

#include "antman.h"

byteread *byteread_read_next(byteread *read)
{
    int size = read->size;
    int reading = read->index + 1;
    unsigned int value = read->string[reading];

    read->value = value;
    read->index = reading;
    read->read = 0;
    for (int i = 0; i < size; i++) {
        read->bit[i] = value % 2;
        value /= 2;
    }
    return read;
}

towrite *decompress_isleaf(towrite *wrid, treehuff **pbranch, treehuff *tree)
{
    treehuff *branch = *pbranch;
    towrite *link = NULL;
    char value = branch->leaf;

    if (!branch->isleaf)
        return wrid;
    if (wrid != NULL)
        link = towrite_generate(wrid->queue - 1);
    else
        link = towrite_generate(-1);
    link->value = value;
    link->next = wrid;
    if (link->queue < 0)
        towrite_delete_last(link, true, false);
    *pbranch = tree;
    return link;
}

int decompress_write_put(byteread *read, towrite *writed, int size)
{
    if (read->read >= read->size) {
        if (read->index - 1 > size) {
            towrite_delete_last(writed, true, false);
            towrite_delete_last(writed, false, true);
            return 1;
        }
        byteread_read_next(read);
    }
    return 0;
}

void decompress_write(treehuff *tree, byteread *read, size_t bytes)
{
    int size = bytes - 4;
    int i = read->index - 1;
    towrite *writed = towrite_generate(read->string[size + 3] - '0');
    treehuff *branch = tree;

    byteread_read_next(read);
    while (ENDLESS) {
        if (branch->isleaf)
            i++;
        writed = decompress_isleaf(writed, &branch, tree);
        if (decompress_write_put(read, writed, size))
            return;
        if (read->bit[read->read] == 0)
            branch = branch->to0;
        else
            branch = branch->to1;
        read->read += 1;
    }
}

void decompress(char const *inp, chardict *dict, size_t bytes)
{
    int sep = get_linebreak_index(inp);
    byteread *read = NULL;
    treehuff *tree = NULL;

    read = malloc(sizeof(byteread));
    read->index = sep + 1;
    read->size = 8;
    read->read = read->size;
    read->value = inp[0];
    read->string = inp;
    for (int i = 0; i < read->size; i++)
        read->bit[i] = 0;
    tree = generate_tree(dict);
    decompress_write(tree, read, bytes);
    treehuff_free(tree);
    free(read);
}
