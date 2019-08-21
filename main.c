#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "./src/frequency.c"
#include "./src/priority_queue.c"
#include "./src/huffman_tree.c"
#include "./src/hash.c"
#include "./src/compress.c"

/**
 * @define ANSI_COLOR_RESET
 * 
 * @discussion Returns to the default print color
*/
#define ANSI_COLOR_RESET "\033[0;0m"
/**
 * @define ANSI_COLOR_LIGHT_MAGENTA
 * 
 * @discussion Inserts magenta light color into terminal
*/
#define ANSI_COLOR_LIGHT_MAGENTA "\033[1;95m"
/**
 * @define ANSI_COLOR_GREEN
 * 
 * @discussion Inserts green color into terminal
*/
#define ANSI_COLOR_GREEN "\033[1;32m"
/**
 * @define ANSI_COLOR_RED
 * 
 * @discussion Inserts red color into terminal
*/
#define ANSI_COLOR_RED "\033[0;31m"

/**
 * @define MAX_SIZE
 * 
 * @discussion Maximum array size
*/
#define MAX_SIZE 256

/**
 * @typedef BYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_BYTE;

int main()
{
    printf(ANSI_COLOR_LIGHT_MAGENTA "\n==============================================\n");
    printf("\n\tWELCOME TO LITTLE HUFF\n");
    printf(ANSI_COLOR_LIGHT_MAGENTA "\n==============================================\n");
    printf(ANSI_COLOR_RESET);

    int opt, i;

    while (1)
    {
        printf("Choose an Option\n");
        printf("1. Compress\n");
        printf("2. Decompress\n");
        printf("3. Exit\n");
        scanf("%d", &opt);

        char file_name[MAX_SIZE];

        switch (opt)
        {
        case 1:
        {
            int freq[MAX_SIZE];
            printf("FILE: ");
            scanf("%s", file_name);
            printf("\n");

            printf("THE FILE %s IS OPENED\n", file_name);
            /** Opens the file in binary read mode */
            FILE *file = fopen(file_name, "rb");

            create_frequency_array(file, freq);

            // printf(ANSI_COLOR_RED "\nPrinting frequency array: \n");
            // printf(ANSI_COLOR_RESET);

            // printing_frequency_array(freq);

            PRIORITY_QUEUE *pq_frequency = enqueue_f_array(freq);
            NODE_TREE *tree = NULL;
            
            // printf(ANSI_COLOR_RED "\nPrinting priority queue: \n");
            // printing_pq(pq_frequency);
            
            tree = build_node(pq_frequency);
            printf("PRE ORDER\n");
            print_pre_order(tree);
            printf(ANSI_COLOR_RESET);
            
            HASH_TABLE *hash = creating_hash_table();
            
            U_BYTE bit_sequency[MAX_SIZE], tree_preorder[513];
            initialize_string(bit_sequency, 0);

            walking_in_the_tree(hash, tree, 0, bit_sequency);
            
            print_hash(hash);

            int size = 0, trash_size = 0;
            size_tree_and_preorder(tree, &size, tree_preorder);
            tree_preorder[size] = '\0';

            int bytes[2] = {0}; // bytes[0] -> lixo e bytes[1] -> tamanho da árvore
            get_trash_size(tree, 0, &trash_size);
            trash_size = 8 - (trash_size % 8);
            printf("trash %d\n", trash_size);

            bytes[0] = trash_size << 5;
            bytes[0] |= size >> 8;
            bytes[1] = size;
            int i;
            // for(i = 7; i >= 0; i--) {
            //     if(is_bit_i_set(bytes[0], i)) {
            //         printf("1");
            //     }
            //     else {
            //         printf("0");
            //     }
            // }
            // printf(" ");
            // for(i = 7; i >= 0; i--) {
            //     if(is_bit_i_set(bytes[1], i)) {
            //         printf("1");
            //     }
            //     else {
            //         printf("0");
            //     }
            // }
            // printf("\n");
            printf("preorder %s\n", tree_preorder);
            
            U_BYTE character;

            FILE *compressedFile = fopen("compressed.huff", "wb");
            fprintf(compressedFile, "%c", bytes[0]);
            fprintf(compressedFile, "%c", bytes[1]);
            fprintf(compressedFile, "%s", tree_preorder);
            // matriz[character][i]
            int j = 0;
            U_BYTE byteFile = 0;
            while(fscanf(file, "%c", &character) != EOF) {
                // for(i = 0; ) {
                for(i = 7; i >= 0; i--) {
                    // fprintf(compressedFile, "%c", hash->matriz[character][i])
                    // for(j = 0; hash->matriz[character][j] != '\0'; j++) {
                    if(hash->matriz[character][j] != '\0'){
                        if(hash->matriz[character][j] != '0') {
                            byteFile = set_bit(byteFile, i);
                            j++;
                        }
                        else{
                            j++;
                        }
                    }
                    else {
                        fscanf(file, "%c", &character);
                        j = 0;
                        if(hash->matriz[character][j] != '0') {
                            byteFile = set_bit(byteFile, i);
                            j++;
                        }
                        else {
                            j++;
                        }
                    }
                    // }
                }
                fprintf(compressedFile, "%c", byteFile);
                byteFile = 0;
                while(hash->matriz[character][j] != '\0'){
                    if(hash->matriz[character][j] != '0') {
                        byteFile = set_bit(byteFile, i);
                        j++;
                    }
                    else{
                        j++;
                    }    
                }
            }

            break;
        }

        case 2:
            break;

        case 3:
            return 0;
            break;

        default:
            printf("\nInvalid option! Try again: \n\n");
            break;
        }
    }

    return 0;
}
