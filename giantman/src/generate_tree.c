/*
** EPITECH PROJECT, 2021
** generate_tree.c
** File description:
** you could for sure use seeds instead
*/

#include "antman.h"

void treehuff_free(treehuff *tree)
{
    if (tree->to0 != NULL)
        treehuff_free(tree->to0);
    if (tree->to1 != NULL)
        treehuff_free(tree->to1);
    free(tree);
}

int find_optimized_sep(int first, int last)
{
    int best = (last + first + 1) / 2;

    return best;
}

treehuff *generate_tree_join(chardict *dict, int first, int last)
{
    int sep = 0;
    treehuff *tree = NULL;

    tree = malloc(sizeof(treehuff));
    tree->to0 = NULL;
    tree->to1 = NULL;
    if (first < last) {
        sep = find_optimized_sep(first, last);
        tree->isleaf = false;
        tree->to0 = generate_tree_join(dict, first, sep - 1);
        tree->to1 = generate_tree_join(dict, sep, last);
    } else {
        tree->isleaf = true;
        tree->leaf = dict->key[first];
    }
    return tree;
}

treehuff *generate_tree(chardict *dict)
{
    int size = dict->size;
    bitpath path = {0, {0}};
    treehuff *tree = generate_tree_join(dict, 0, size - 1);

    return tree;
}
