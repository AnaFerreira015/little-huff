#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"
#include "../libs/decompress.h"
#include "../libs/compress.h"

NODE_TREE *create_tree_preorder(NODE_TREE *node_tree, FILE *compressed) {
    U_BYTE character;
    fscanf(compressed, "%c", &character);

    if(character == '*') {
        node_tree = create_node();
        node_tree->character = '*';
        create_tree_preorder(node_tree->left, compressed);
        create_tree_preorder(node_tree->right, compressed);
    }
    else {
        if(character == '\\') {
            fscanf(compressed,"%c",&character);
        }
        node_tree = create_node();
        node_tree->character = character;
    }
        return node_tree;
}

void decompress(FILE *compressed) {
    U_BYTE character;
            
    int trash, sizeTree, a[1], bytes[2] = {0};

    fscanf(compressed, "%c", &character);
    // trash = character >> 5; // o lixo está 10100000 e vai ficar 00000101, já que ele ocupa apenas 3 bits
    // // bytes[0] = trash;
    // // print_byte(bytes, 0);
    // // printf("\n");
    // sizeTree = character >> 4; // 10100000 >> 4 = 00001010
    // fscanf(compressed, "%c", &character); // character = 00001011
    // sizeTree |= character; // 00001010 |= 00001011 -> 00001011
    // a[0] = sizeTree;
    // print_byte(a, 0);
    // printf("\n");
    // NODE_TREE *node_tree = create_tree_preorder(node_tree, compressed);
    // print_pre_order(node_tree);
    // printf("%c\n", node_tree->left->character);

    trash = character >> 5;
    bytes[0] = trash;

    sizeTree = character << 3;
    sizeTree >>= 3;
    // sizeTree |= character;
    bytes[1] = sizeTree;

    print_byte(bytes, 0);
    printf(" ");
    print_byte(bytes, 1);
    printf("\n");
}