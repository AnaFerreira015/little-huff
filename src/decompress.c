#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/huffman_tree.h"
#include "../libs/decompress.h"
#include "../libs/compress.h"

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

void start_decompress(FILE *compressed, U_BYTE *input_file, U_BYTE *type)
{
    U_BYTE character;

    int trash = 0, sizeTree = 0,aux2 = 0, a[1], bytes[2] = {0};
    int i;

    // fscanf(compressed, "%c", &character);      
    // trash = character >> 5;       
    // sizeTree = character << 11;      
    // // 00000000 00000000 00000000 0000101
    
    // sizeTree >>= 3;          
    // fscanf(compressed, "%c", &character);     
    // sizeTree |= character;


    fscanf(compressed, "%c", &character);

    // printf("\nObtendo tamanho do lixo..\n\n");
    trash = character >> 5;

    // printf("Obtendo tamanho da árvore..\n\n");
    sizeTree =(character<<3) & (0xFF);
    sizeTree = sizeTree << 5;

    fscanf(compressed, "%c", &character);
    sizeTree |= character;
  

    NODE_TREE *node = create_node();
    printf("Montando árvore...\n\n");
    node = create_tree_preorder(node, compressed);
    // print_pre_order(node);
    printf("Iniciando descompressão...\n\n");

    U_BYTE out_file[MAX_SIZE];
    strcpy(out_file, "descompactado.");
    strcat(out_file, type);

    U_BYTE aux = 0;

    FILE *decompress_file = fopen(out_file, "w+b"); 
    int size = 0;
    
    while (fscanf(compressed, "%c", &character) != EOF)
    {
        size++;
    }
   
    rewind(compressed);
    fseeko(compressed, 2+sizeTree, SEEK_SET);

    NODE_TREE *tree = node;
    while (fscanf(compressed, "%c", &character) != EOF)
    {
        for (i = 7; i >= 0; i--)
        {
             if(isLeaf(tree))
            {
                fprintf(decompress_file, "%c", tree->character);
                tree = node;
            }
            if(is_bit_i_set(character,i))
            {
                tree = tree->right;
            }
            else
            {
                tree = tree->left;
            }
           
        }
    }


    //   for (i = 7; i >= trash; i--)
    //     {
    //         if(isLeaf(tree))
    //         {
    //             fprintf(decompress_file, "%c", tree->character);
    //             tree = node;
    //         }
    //         if(is_bit_i_set(aux2,i))
    //         {
    //             tree = tree->right;
    //         }
    //         else
    //         {
    //             tree = tree->left;
    //         }
    //     }
  
    fclose(compressed);
    fclose(decompress_file);
    // decompress(trash, sizeTree, compressed, node, input_file );
}