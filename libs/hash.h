#ifndef _HASH_
#define _HASH_

#define MAX_SIZE 256

typedef unsigned char U_BYTE;

typedef struct HASH_TABLE
{
    void *matriz[MAX_SIZE][MAX_SIZE];
} HASH_TABLE;

extern HASH_TABLE *creating_hash_table();

extern void put_in_hash(HASH_TABLE *hash_table, U_BYTE character, int index, U_BYTE bit_sequency[]);

extern int is_bit_i_set(U_BYTE c, int i);

extern U_BYTE set_bit(U_BYTE c, int i);

extern void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_BYTE bit_sequency[]);

#endif