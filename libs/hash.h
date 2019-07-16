#ifndef _HASH_
#define _HASH_

#define MAX_SIZE 256

typedef unsigned char uBYTE;
typedef unsigned short uSHORT;

typedef struct ELEMENT
{
    uSHORT binary_code; // codigo binário na tabela ASCII
    int frequency;
} ELEMENT;

typedef struct HASH_TABLE
{
    ELEMENT *table[MAX_SIZE];
} HASH_TABLE;

extern HASH_TABLE *creating_hash_table();

extern HASH_TABLE *put(HASH_TABLE *hash_table, uSHORT binary_code, uBYTE symbol, int i);

extern int is_bit_i_set(uBYTE c, int i);

extern uBYTE set_bit(uBYTE c, int i);

#endif