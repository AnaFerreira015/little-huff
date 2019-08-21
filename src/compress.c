#include <stdio.h>
#include <stdlib.h>
#include "../libs/compress.h"
#include "../libs/huffman_tree.h"

void get_trash_size(NODE_TREE *tree, int height, int *trash_size) {
    if(!isEmptyTree(tree)) {
        if(isLeaf(tree)) {
            *trash_size += tree->frequency * height;
            height += 1;
        }
        get_trash_size(tree->left, height + 1, trash_size);
        get_trash_size(tree->right, height + 1, trash_size);
    }
}

int is_bit_i_set(U_BYTE c, int i)
{
    U_BYTE mask = 1 << i;

    return mask & c;
}

U_BYTE set_bit(U_BYTE c, int i)
{
    U_BYTE mask = 1 << i;

    return mask | c;
}