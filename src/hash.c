#include <stdio.h>
#include <stdlib.h>
#include "../libs/hash.h"

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

HASH_TABLE *put(HASH_TABLE *hash_table, uSHORT binary_code, uBYTE symbol, int i)
{
    ELEMENT *element = (ELEMENT *)malloc(sizeof(ELEMENT));
    element->binary_code = binary_code;
    element->frequency = i;

    hash_table->table[symbol] = element;

    return hash_table;
}

int is_bit_i_set(uBYTE c, int i)
{
    uBYTE mask = 1 << i;

    return mask & c;
}

uBYTE set_bit(uBYTE c, int i)
{
    uBYTE mask = 1 << i;

    return mask | c;
}

int main()
{
    return 0;
}