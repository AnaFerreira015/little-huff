#include <stdio.h>
#include <stdlib.h>
#include "../libs/hash.h"
#include "../libs/huffman_tree.h"

/**
 * @define MAX_SIZE
 * 
 * @discussion Maximum array size
*/
#define MAX_SIZE 256

/** @discussion Inicializa a hash table com espaços vazios
 * 
 * @result Uma hash table
 */
HASH_TABLE *creating_hash_table()
{
    HASH_TABLE *new_hash_table = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));

    int i, j;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            new_hash_table->matriz[i][j] = (U_BYTE*)' ';
        }
    }
    return new_hash_table;
}

/** @discussion Recebe a árvore de Huffman, um ponteiro para o tamanho dela e outro para o tamanho do lixo
 * 
 * @param tree A árvore de Huffman
 * @param height Irá armazenar o tamanho da árvore
 * @param trash_size Irá armazenar o tamanho do lixo na árvore
 * 
 */
void put_in_hash(HASH_TABLE *hash_table, U_BYTE character, int index, U_BYTE bit_sequency[])
{
    int i;
    for (i = 0; i < index; i++)
    {
        hash_table->matriz[character][i] = (U_BYTE)bit_sequency[i];
    }
    hash_table->matriz[character][i] = '\0';
}

void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_BYTE bit_sequency[])
{
    if(isEmptyTree(tree)) 
    {
        return;
    }
    if (isLeaf(tree))
    {
         unsigned char *aux = (unsigned char*) malloc(sizeof(unsigned char));
      aux = tree->character;
        put_in_hash(hash_table, *aux, i, bit_sequency);
        return;
    }
    bit_sequency[i] = '0';
    walking_in_the_tree(hash_table, tree->left, i + 1, bit_sequency);

    bit_sequency[i] = '1';
    walking_in_the_tree(hash_table, tree->right, i + 1, bit_sequency);
}

void print_hash(HASH_TABLE *hash)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (hash->matriz[i][0] != (U_BYTE)' ')
        {
            printf("%c: ", i);
            for (j = 0; j < MAX_SIZE; j++)
            {
                printf("%c", (U_BYTE*)hash->matriz[i][j]);
            }
            printf("\n");
        }
    }
}