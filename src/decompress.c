#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/huffman_tree.h"
#include "../libs/decompress.h"
#include "../libs/compress.h"

typedef unsigned char U_BYTE;

typedef struct NODE
{
    U_BYTE character;
    int frequency;
    struct NODE *left;
    struct NODE *right;
    struct NODE *next;
} NODE;

NODE *create_node_decompress()
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->frequency = 0;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}


NODE *create_tree_preorder(NODE *node, FILE *compressed)
{
    U_BYTE character;
    fscanf(compressed, "%c", &character);

    if (character == '*')
    {
        node = create_node_decompress();
        node->character = '*';
        node->left = create_tree_preorder(node->left, compressed);
        node->right = create_tree_preorder(node->right, compressed);
    }
    else
    {
        if (character == '\\')
        {
            fscanf(compressed, "%c", &character);
        }
        node = create_node_decompress();
        node->character = character;
    }
    return node;
}

void start_decompress(FILE *compressed, U_BYTE *input_file, U_BYTE *type)
{
    U_BYTE character;

    int trash = 0, sizeTree = 0, aux2 = 0, a[1], bytes[2] = {0}, i;

    fscanf(compressed, "%c", &character);

    printf("\nObtendo tamanho do lixo..\n\n");
    trash = character >> 5;

    printf("Obtendo tamanho da árvore..\n\n");
    sizeTree = (character << 3) & (0xFF);
    sizeTree = sizeTree << 5;

    fscanf(compressed, "%c", &character);
    sizeTree |= character;

    NODE *node = create_node_decompress();
    printf("Montando árvore...\n\n");
    node = create_tree_preorder(node, compressed);
    // print_pre_order(node);
    printf("Iniciando descompressão...\n\n");

    U_BYTE out_file[MAX_SIZE];
    strcpy(out_file, "descompactado.");
    strcat(out_file, type);

    U_BYTE aux = 0;

    FILE *decompress_file = fopen(out_file, "wb");
    int size = 0;

    while (fscanf(compressed, "%c", &character) != EOF)
    {
        size++;
    }
    // printf("size %d\n", size);

    rewind(compressed);
    fseeko(compressed, 2 + sizeTree, SEEK_SET);

    NODE *tree = node;
    while (size > 0)
    {
        fscanf(compressed, "%c", &character);
        if (size != 1)
        {
            for (i = 7; i >= 0; i--)
            {
                if (is_bit_i_set(character, i))
                {
                    tree = tree->right;
                }
                else
                {
                    tree = tree->left;
                }
                if (tree->left == NULL && tree->right == NULL)
                {
                    fprintf(decompress_file, "%c", tree->character);
                    tree = node;
                }
            }
        }
        else
        {
            for (i = 7; i >= trash; i--)
            {
                if (is_bit_i_set(character, i))
                {
                    tree = tree->right;
                }
                else
                {
                    tree = tree->left;
                }
                if (tree->left == NULL && tree->right == NULL)
                {
                    fprintf(decompress_file, "%c", tree->character);
                    tree = node;
                }
            }
        }
        size--;
    }

    fclose(compressed);
    fclose(decompress_file);
}