#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "./src/frequency.c"
#include "./src/priority_queue.c"
#include "./src/huffman_tree.c"
#include "./src/hash.c"
#include "./src/compress.c"
#include "./src/decompress.c"

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
 * @define ASCII_SIZE
 * 
 * @discussion Maximum array size
*/
#define ASCII_SIZE 256

/**
 * @typedef BYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_CHAR;
typedef long long int lli;

void run()
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

        char file_name[ASCII_SIZE];

        switch (opt)
        {
        case 1:
        {
            int freq[ASCII_SIZE] = {0};
            printf("FILE: ");
            scanf("%s", file_name);
            printf("\n");

            printf("THE FILE %s IS OPENED\n\n", file_name);
            /** Opens the file in binary read mode */
            FILE *file = fopen(file_name, "rb");

            if (file == NULL)
            {
                printf("Arquivo vazio..\n\n");
                break;
            }

            printf("Calculando frequencia do arquivo...\n\n");
            create_frequency_array(file, freq);

            PRIORITY_QUEUE *pq_frequency = createEmptyQueue();
            pq_frequency = enqueue_f_array(freq);

            NODE_TREE *tree = build_node(pq_frequency);

            HASH_TABLE *hash = creating_hash_table();

            U_CHAR bit_sequency[ASCII_SIZE];
            memset(bit_sequency, 0, ASCII_SIZE);

            walking_in_the_tree(hash, tree, 0, bit_sequency);
            // print_hash(hash);

            lli size = 0;
            U_CHAR trash_size = 0;

            size_tree_and_preorder(tree, &size);

            int bytes[2] = {0};                   // bytes[0] -> lixo e bytes[1] -> tamanho da árvore
            get_trash_size(tree, 0, &trash_size); // o valor trash_size agora é o tamanho total de bits do arquivo
            trash_size = 8 - (trash_size % 8);

            if (trash_size == 8)
            {
                trash_size = 0;
            }

            bytes[0] = trash_size << 5;
            bytes[0] |= size >> 8;
            bytes[1] = size;

            FILE *compressedFile = fopen("compressed.huff", "wb");

            fprintf(compressedFile, "%c", bytes[0]);
            fprintf(compressedFile, "%c", bytes[1]);

            put_tree(tree, compressedFile);

            printf("Aguarde um momento...\n\n");
            rewind(file);
            write_to_file(file, hash, compressedFile, size);
            fclose(file);
            break;
        }

        case 2:
            printf("Digite o nome do arquivo (ex.: arquivo.huff):\n");
            U_CHAR array[ASCII_SIZE], type[15];
            scanf("%s", array);

            printf("\n\nDigite o tipo do arquivo (ex.: txt):\n");
            scanf("%s", type);

            FILE *compressedFile = fopen(array, "rb");
            if (compressedFile == NULL)
            {
                printf("Arquivo não encontrado\n");
                break;
            }

            rewind(compressedFile);
            start_decompress(compressedFile, type);

            break;

        case 3:
            return;
            break;

        default:
            printf("\nInvalid option! Try again: \n\n");
            break;
        }
    }

    return;
}
