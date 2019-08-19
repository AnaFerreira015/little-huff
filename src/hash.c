#include <stdio.h>
#include <stdlib.h>
#include "../libs/hash.h"
#include "../libs/huffman_tree.h"

#define MAX_SIZE 256

HASH_TABLE *creating_hash_table()
{
    HASH_TABLE *new_hash_table = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));

    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        new_hash_table->table[i] = NULL;
    }

    return new_hash_table;
}

void put_in_hash(HASH_TABLE *hash_table, U_BYTE character, int index, U_BYTE bit_sequency[])
{    
    int i;
        // printf("index %d\n", index);
        // printf("aqui %c: %d\n", character, (int)character);
    for (i = 0; i < index; i++) {
        hash_table->table[character]->binary_code[character][i] = bit_sequency[i];
        // printf("oi\n");
    }
    hash_table->table[character]->binary_code[character][i] = '\0';
}

void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_BYTE bit_sequency[])
{
    if (isLeaf(tree))
    {
        put_in_hash(hash_table, tree->character, i, bit_sequency);

        return;
    }
    bit_sequency[i] = '0';
    walking_in_the_tree(hash_table, tree->left, i+1, bit_sequency);

    bit_sequency[i] = '1';
    walking_in_the_tree(hash_table, tree->right, i+1, bit_sequency);
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

void print_hash(HASH_TABLE *hash)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%c: ", i);
        if (hash->table[i] != NULL)
        {
            for(j = 0; j < MAX_SIZE; j++) {
                printf("%c", hash->table[i]->binary_code[i][j]);
            }
        }
        printf("\n");
    }
}