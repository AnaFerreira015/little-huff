#include <stdio.h>
#include <stdlib.h>
#include "../libs/compress.h"
#include "../libs/huffman_tree.h"

void get_trash_size(NODE_TREE *tree, int height, int *trash_size) {
    if(!isEmptyTree(tree)) {
        if(isLeaf(tree)) {
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

void print_byte(int bytes[], int pos) {
    int i;
    for(i = 7; i >= 0; i--) {
        if(is_bit_i_set(bytes[pos], i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}

// escreve o lixo e o tamanho da árvore
void write_byte_to_file(FILE *compressedFile, int bytes[], int pos){
    fprintf(compressedFile, "%c", bytes[pos]);
}

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile) {
    U_BYTE character, byteFile = 0;;
    int i, colHash = 0;
    
    while (fscanf(file, "%c", &character) != EOF)
    {
        // o for abaixo é para o byte, não para um array
        for(i = 7; i >= 0; i--) { // começa em 7 para indicar a posição do bit (ver como calcula de binario para decimal)
            if(hash_table->matriz[character][colHash] != '\0') {
                // só seta o bit se ele for 1
                if(hash_table->matriz[character][colHash] != '0') {
                    byteFile = set_bit(byteFile, i);
                    colHash++;
                }
                // se o bit for 0, como a matriz já ta zerada, não precisa alterar
                else {
                    colHash++;
                }
            }
            else {
                colHash = 0;
            }
        }
        fprintf(compressedFile, "%c", byteFile);
        byteFile = 0;
        fclose(compressedFile);
    }
    
}