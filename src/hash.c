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

void put_in_hash(HASH_TABLE *hash_table, U_BYTE character, char bit_sequency[], int index)
{
    hash_table->table[index]->character = character;
    hash_table->table[index]->binary_code = bit_sequency;
}

HASH_TABLE *walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree)
{
    int i = 0, index = 0;
    U_BYTE bit_sequency[MAX_SIZE] = 0;

    while (tree != NULL)
    {
        if (isLeaf(tree))
        {
            put_in_hash(hash_table, tree->character, bit_sequency, index++);
            
            return;
        }
        bit_sequency[i] = "0";
        walking_in_the_tree(hash_table, tree->left);

        bit_sequency[i] = "1";
        walking_in_the_tree(hash_table, tree->right);
        i++; //Corrigir esse indice
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
