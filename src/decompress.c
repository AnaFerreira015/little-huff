#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/huffman_tree.h"
#include "../libs/decompress.h"
#include "../libs/compress.h"

void decompress(int trash, int sizeTree, FILE *compressed, NODE_TREE *node, U_BYTE *input_file)
{

    U_BYTE out_file[MAX_SIZE],character;
    FILE *decompress_file = fopen(out_file, "w"); 
    int i;
    int size = 0;
    while (fscanf(compressed, "%c", &character) != EOF)
    {
        // printf("size %d\n", size);
        size++;
    }
    printf("size %d\n", size);
    
    // NODE_TREE *tree = node;
    // while (fscanf(compressed, "%c", &character) != EOF)
    // {
    //     for (i = 7; i >= 0; i--)
    //     {
    //         if(isLeaf(tree))
    //         {
    //             printf("%c\n", tree->character);
    //             fprintf(decompress_file, "%c", tree->character);
    //             tree = node;
    //         }
    //         if(is_bit_i_set(character,i))
    //         {
    //             // printf("aqui\n");
    //             tree = tree->right;
    //         }
    //         else
    //         {
    //             tree = tree->left;
    //         }
    //     }
    // }
    
    // fclose(decompress_file);

}

NODE_TREE *create_tree_preorder(NODE_TREE *node_tree, FILE *compressed)
{
    U_BYTE character;
    fscanf(compressed, "%c", &character);

    if (character == '*')
    {
        node_tree = create_node();
        node_tree->character = '*';
        node_tree->left = create_tree_preorder(node_tree->left, compressed);
        node_tree->right = create_tree_preorder(node_tree->right, compressed);
    }
    else
    {
        if (character == '\\')
        {
            fscanf(compressed, "%c", &character);
        }
        node_tree = create_node();
        node_tree->character = character;
    }
    return node_tree;
}

void start_decompress(FILE *compressed, U_BYTE *input_file)
{
    U_BYTE character;

    int trash, sizeTree = 0, a[1], bytes[2] = {0};

    fscanf(compressed, "%c", &character);

    printf("\nObtendo tamanho do lixo..\n\n");
    trash = character >> 5;
    bytes[0] = trash;

    fscanf(compressed, "%c", &character);
    bytes[1] = character;
    printf("Obtendo tamanho da árvore..\n\n");
    sizeTree = bytes[0] << 3;
    sizeTree = sizeTree << 5;
    sizeTree |= bytes[1];

    bytes[1] = sizeTree;

    // print_byte(bytes, 0);
    // printf(" ");
    // print_byte(bytes, 1);
    // printf("\n\n");

    NODE_TREE *node = create_node();
    printf("Montando árvore...\n\n");
    node = create_tree_preorder(node, compressed);

    // print_pre_order(node);
    printf("Iniciando descompressão...\n\n");
    decompress(trash, sizeTree, compressed, node, input_file );
}