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

            printf("THE FILE %s IS OPENED\n", file_name);
            /** Opens the file in binary read mode */
            FILE *file = fopen(file_name, "rb");

            printf("Calculando frequencia do arquivo...\n");
            create_frequency_array(file, freq);

            // printf(ANSI_COLOR_RED "\nPrinting frequency array: \n");
            // printf(ANSI_COLOR_RESET);

            // printing_frequency_array(freq);

            PRIORITY_QUEUE *pq_frequency = createEmptyQueue();
            pq_frequency = enqueue_f_array(freq);

            // printf(ANSI_COLOR_RED "\nPrinting priority queue: \n");
            // printf(ANSI_COLOR_RESET);
            // printing_pq(pq_frequency);
            // printing_pq(pq_frequency);

            NODE_TREE *tree = build_node(pq_frequency);
            // printf("PRE ORDER\n");
            // print_pre_order(tree);
            // printf(ANSI_COLOR_RESET);
            HASH_TABLE *hash = creating_hash_table();


            U_CHAR bit_sequency[ASCII_SIZE], tree_preorder[514];
            memset(bit_sequency, 0, ASCII_SIZE);
            // printf("depois do memset\n");

            walking_in_the_tree(hash, tree, 0, bit_sequency);
            // printf("depois da hash\n");
            print_hash(hash);

            lli size = 0;
            U_CHAR trash_size = 0;

            // printf("antes do tamanho da arvore\n");
            size_tree_and_preorder(tree, &size, tree_preorder);
            // printf("SIZE TREE: %lld\n",size);
            tree_preorder[size] = '\0';

            int bytes[2] = {0}; // bytes[0] -> lixo e bytes[1] -> tamanho da árvore
            // printf("antes do tamanho do lixo\n");
            get_trash_size(tree, 0, &trash_size);// o valor trash_size agora é o tamanho total de bits do arquivo
            trash_size = 8 - (trash_size % 8);

            if (trash_size == 8)
            {
                trash_size = 0;
            }
            printf("trash dps do if: %d\n", trash_size);
            bytes[0] = trash_size << 5;
            bytes[0] |= size >> 8;
            bytes[1] = size;
            printf("trash %d\n", trash_size);
            printf("SIZE TREE: %lld\n", size);

            print_byte(bytes, 0);
            printf(" ");
            print_byte(bytes, 1);
            printf("\n");
            printf("preorder %s\n", tree_preorder);

            FILE *compressedFile = fopen("compressed.huff", "wb");
            printf("abriu o arquivo\n");

            fprintf(compressedFile, "%c", bytes[0]);
            printf("escreveu o byte[0]\n");
            fprintf(compressedFile, "%c", bytes[1]);
            printf("escreveu o byte[1]\n");
            printf("arvore huff preordem: %s\n", tree_preorder);
            // fprintf(compressedFile, "%s", tree_preorder);
            put_tree(tree, compressedFile);
            printf("escreveu a arvore\n");

            rewind(file);
            // printf("dps do rewind\n");
            write_to_file(file, hash, compressedFile, size);
            printf("depois de escrever\n");
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
