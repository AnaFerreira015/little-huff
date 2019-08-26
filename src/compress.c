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
// void write_byte_to_file(FILE *compressedFile, int bytes[], int pos)
// {
//     fprintf(compressedFile, "%c", bytes[pos]);
// }

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile, int trash_size)
{
    U_BYTE character, byteFile = 0;
    int a[1];
    int i, j = 0, size = 0, amount = 0, rest_size = 7;
// fscanf(file, "%c", &character) != EOF
    while (fread(&character, sizeof(U_BYTE),1,file) == 1)
    {
        while(hash_table->matriz[character][j] != '\0') 
        {
            size++;
            j++;
        }
        j = 0;
        // printf("aqui %c %d\n", character, size);
        for (i = size; i >= 0; i--)
        {
            // printf("ch %c     size %d\n\n", character, i);
            if (hash_table->matriz[character][j] != '\0')
            {
                if (hash_table->matriz[character][j] != '0')
                {
                
                    // printf("\tEU: 1   ");
                    byteFile = set_bit(byteFile, rest_size);
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
                // a[0] = byteFile;
                // print_byte(a, 0);
                // printf("\n");
                // fprintf(compressedFile, "%c", byteFile);
                fwrite(&byteFile, sizeof(U_BYTE),1,compressedFile);
                byteFile = 0;
                rest_size = 7;
                amount = 0;
            }
            
        }
        
    }
    // printf("saiu\n");
    // a[0] = byteFile;
    // print_byte(a, 0);
    //  printf("\nLIsho %d\nRest: %d\n", trash_size,rest_size);
    // rest_size = 8 - trash_size;
    // printf("amount %d\n",amount);
    // printf("Rest: %d\n", rest_size);
    // byteFile = set_bit(byteFile, trash_size);
    // fprintf(compressedFile, "%c", byteFile);
    fwrite(&byteFile, sizeof(U_BYTE),1,compressedFile);
    // int a[1];
    // a[0] = byteFile;
    // print_byte(a, 0);
    fclose(compressedFile);
}