/**
 * @file btree.c
 * @author Amit Bajar
 * @brief interface implementation for a simple (d,2d) b tree holding integer keys as values
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief makes an empty b tree with d <= children <= 2d except for the root.
 * Time complexity: O(1)
 * @return empty b tree
*/
BTree* btree_make(int d) {
    BTreeNode *root = malloc(sizeof(BTreeNode));
    root->d = d;
    root->children = malloc(2*d*sizeof(BTreeNode));
    root->keys = malloc((2*d-1)*sizeof(int));
    BTree* btree = malloc(sizeof(BTree));
    btree->root = root;

    return btree;
}

void btree_destroy_rec(BTreeNode *node) {
    for (int i = 0; i < 2*node->d; ++i) {
        btree_destroy_rec(node->children+i);
        free(node->d);
        free(node->keys);
    }
}

void btree_destroy(BTree *tree) {
    btree_destroy_rec(tree->root);
    free(tree);
}