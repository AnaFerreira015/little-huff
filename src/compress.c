#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/compress.h"
#include "../libs/huffman_tree.h"

void get_trash_size(NODE_TREE *tree, int height, U_CHAR *trash_size)
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

int is_bit_i_set(U_CHAR c, int i)
{
    U_CHAR mask = 1 << i;

    return mask & c;
}

U_CHAR set_bit(U_CHAR c, int i)
{
    U_CHAR mask = 1 << i;

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
    printf("\n");
}

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile, lli sizetree)
{
    U_CHAR character, byteFile = 0;
    int a[1];
    int i, j = 0, size = 0, amount = 0, byte_size = 7;

    rewind(compressedFile);
    printf("antes de escrever\n");
    fseek(compressedFile, 2 + sizetree, SEEK_SET);
    while (fscanf(file, "%c", &character) != EOF)
    // while (!feof(file))
    {
        // printf("lendo os caracteres\n");
        j = 0;
        // printf("aqui %c %d\n", character, size);
        while (hash_table->matriz[character][j] != (U_CHAR *)'\0')
        {
            // printf("ch %c     size %d\n\n", character, i);
            
            if (hash_table->matriz[character][j] != (U_CHAR *)'0')
            {
                byteFile = set_bit(byteFile, byte_size);
                // printf("\tEU: 1   ");
                // a[0] = byteFile;
                // print_byte(a, 0);
                amount++;
                byte_size--;
                j++;
            }
            else
            {
                //   printf("\tEU dnv: 0   ");
                //   a[0] = byteFile;
                //     print_byte(a, 0);
                amount++;
                byte_size--;
                j++;
            }
            
            if (amount == 8)
            {
                // printf("completou 1 byte\n");
                // a[0] = byteFile;
                // print_byte(a, 0);
                fprintf(compressedFile, "%c", byteFile);
                byteFile = 0;
                byte_size = 7;
                amount = 0;
            }
        }
    }
    printf("acabou a compressao\n");
    if (amount != 0){
        fprintf(compressedFile, "%c", byteFile);
    }
    // a[0] = byteFile;
    // print_byte(a, 0);
    fclose(compressedFile);
}