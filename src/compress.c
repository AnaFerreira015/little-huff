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

// escreve o lixo e o tamanho da árvore
void write_byte_to_file(FILE *compressedFile, int bytes[], int pos)
{
    fprintf(compressedFile, "%c", bytes[pos]);
}

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile)
{
    U_BYTE character;
    int i, j = 0, size = 0;
    U_BYTE byteFile = 0;
    while (fscanf(file, "%c", &character) != EOF)
    {
        while(hash_table->matriz[character][j] != '\0') {
            size++;
            j++;
        }
        j = 0;
        printf("aqui %c %d\n", character, size);
        for (i = 7; i >= 0; i--)
        {
            if (hash_table->matriz[character][j] != '\0')
            {
                if (hash_table->matriz[character][j] != '0')
                {
                    byteFile = set_bit(byteFile, i);
                    j++;
                }
                else
                {
                    j++;
                }
            }
            else
            {

            }
        }
        fprintf(compressedFile, "%c", byteFile);
        byteFile = 0;
    }
    int a[1];
    a[0] = byteFile;
    print_byte(a, 0);
}