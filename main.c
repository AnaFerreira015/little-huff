#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "./src/frequency.c"
#include "./src/priority_queue.c"
#include "./src/huffman_tree.c"

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

            create_frequency_array(file_name, freq);

            // printf(ANSI_COLOR_RED "\nPrinting frequency array: \n");
            // printf(ANSI_COLOR_RESET);

            // printing_frequency_array(freq);

            PRIORITY_QUEUE *pq_frequency = enqueue_f_array(freq);
            PRIORITY_QUEUE *pq_teste = NULL;

            // printf(ANSI_COLOR_RED "\nPrinting priority queue: \n");
            // printf(ANSI_COLOR_RESET);
            // printing_pq(pq_frequency);
            // desinfileira 2
            // soma a frequência
            // cria um novo nó com a soma e enfileira de novo

            NODE_TREE *node_tree = NULL;
            NODE_TREE *tree = NULL;
            // printf("ANTES DO FOR\n");
            // printing_pq(pq_frequency);

            // printf("DEPOIS DA BUILD\n");
            // printing_pq(pq_frequency);
            for(i = 0; i < MAX_SIZE; i++) {
                if(freq[i]) {
                    node_tree = create_node();
                    node_tree->frequency = freq[i];
                    node_tree->character = (U_BYTE)i;
                    // enqueue(pq_frequency, node_tree);
                }
            }

            
            printf("DEPOIS DA BUILD\n");
            printing_pq(pq_frequency);
            

            tree = build_node(pq_frequency);
            printf("PRE ORDER\n");
            print_pre_order(tree);
            // NODE_TREE *aux = node_tree->left;
            // printf("teste %c (%d)\n", aux->left->character, aux->left->frequency);

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
