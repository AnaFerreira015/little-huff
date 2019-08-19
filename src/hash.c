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

void put_in_hash(HASH_TABLE *hash_table, U_BYTE character, U_BYTE bit_sequency[], int index)
{    
    int i;
    for (i = 0; i < index; i++) {
        hash_table->table[(int)character]->binary_code[index][i] = bit_sequency;
    }
    hash_table->table[(int)character]->binary_code[index][i] = '\0';
}

void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_BYTE bit_sequency[])
{
    if (isLeaf(tree))
    {
        put_in_hash(hash_table, tree->character, bit_sequency, i++);

        return;
    }
    bit_sequency[i] = '0';
    walking_in_the_tree(hash_table, tree->left, i++, bit_sequency);

    bit_sequency[i] = '1';
    walking_in_the_tree(hash_table, tree->right, i++, bit_sequency);
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
    int i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (hash->table[i] != NULL)
        {
            printf("%c %s", hash->table[i]->character, hash->table[i]->binary_code);
        }
    }
}