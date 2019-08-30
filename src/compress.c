#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/compress.h"
#include "../libs/huffman_tree.h"

void get_trash_size(NODE_TREE *tree, int height, int *trash_size)
{
    if (!isEmptyTree(tree))
    {
        if (isLeaf(tree))
        {
            *trash_size += tree->frequency * height;
            height += 1;
        }
        get_trash_size(tree->left, height + 1, trash_size);
        get_trash_size(tree->right, height + 1, trash_size);
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

void print_byte(int bytes[], int pos)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        if (is_bit_i_set(bytes[pos], i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile)
{
    U_BYTE character, byteFile = 0;
    int a[1];
    int i, j = 0, size = 0, amount = 0, rest_size = 7;

    while (fscanf(file, "%c", &character) != EOF)
    {
        while(hash_table->matriz[character][j] != (U_BYTE*)'\0') 
        {
            size++;
            j++;
        }
        j = 0;
        // printf("aqui %c %d\n", character, size);
        for (i = size; i >= 0; i--)
        {
            // printf("ch %c     size %d\n\n", character, i);
            if (hash_table->matriz[character][j] != (U_BYTE*)'\0')
            {
                if (hash_table->matriz[character][j] != (U_BYTE*)'0')
                {
                    byteFile = set_bit(byteFile, rest_size);
                    // printf("\tEU: 1   ");
                    // a[0] = byteFile;
                    // print_byte(a, 0);
                    amount++;
                    rest_size--;
                    j++;
                }
                else
                {
                //   printf("\tEU dnv: 0   ");
                //   a[0] = byteFile;
                //     print_byte(a, 0);
                    amount++;
                    rest_size--;
                    j++;
                }
            }
            
            if(amount == 8) 
            {
                fprintf(compressedFile, "%c", byteFile);
                byteFile = 0;
                rest_size = 7;
                amount = 0;
            }
            
        }
        
    }
    fprintf(compressedFile, "%c", byteFile);

    a[0] = byteFile;
    print_byte(a, 0);
    fclose(compressedFile);
}