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
            // printf("MAIN\n");
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
            // for(i = 0; i < MAX_SIZE; i++) {
            //     if(freq[i]) {
            //         node_tree = create_node();
            //         node_tree->frequency = freq[i];
            //         node_tree->character = (U_BYTE)i;
            //         // enqueue(pq_frequency, node_tree);
            //     }
            // }

            
            // printf("DEPOIS DA BUILD\n");
            // printing_pq(pq_frequency);
            // printf("%c %d", pq_frequency->head->next->character, pq_frequency->head->next->frequency);

            
            tree = build_node(pq_frequency);
            printf("PRE ORDER\n");
            print_pre_order(tree);
            // printf("tree char %c\ttree freq %d\n", tree->character, tree->frequency);
            
            // printf("left char %c\nleft freq %d\n", tree->left->character, tree->left->frequency);
            // printf("left left char %c\tleft left freq %d\n", tree->left->left->character, tree->left->left->frequency);
            
            // printf("left right char %c\tleft right freq %d\n", tree->left->right->character, tree->left->right->frequency);

            // printf("right char %c\tright freq %d\n", tree->right->character, tree->right->frequency);
            // printf("right left char %c\tright left freq %d\n", tree->right->left->character, tree->right->left->frequency);
            // printf("right left left char %c\tright left left freq %d\n", tree->right->left->left->character, tree->right->left->left->frequency);
            // printf("right left left left char %c\tright left left left freq %d\n", tree->right->left->left->left->character, tree->right->left->left->left->frequency);

            // printf("right left left right char %c\tright left left right freq %d\n", tree->right->left->left->right->character, tree->right->left->left->right->frequency);

            // printf("right left right char %c\tright left right freq %d\n", tree->right->left->right->character, tree->right->left->right->frequency);
            // printf("right right char %c\tright right freq %d\n", tree->right->right->character, tree->right->right->frequency);
            // printf("%c\t%d\n", tree->character, tree->frequency);
            
            // printf("%c\n%d\n", tree->left->character, tree->left->frequency);
            // printf("%c\t%d\n", tree->left->left->character, tree->left->left->frequency);
            
            // printf("%c\t%d\n", tree->left->right->character, tree->left->right->frequency);

            // printf("%c\t%d\n", tree->right->character, tree->right->frequency);
            // printf("%c\t%d\n", tree->right->left->character, tree->right->left->frequency);
            // printf("%c\t%d\n", tree->right->left->left->character, tree->right->left->left->frequency);
            // printf("%c\t%d\n", tree->right->left->left->left->character, tree->right->left->left->left->frequency);

            // printf("%c\t%d\n", tree->right->left->left->right->character, tree->right->left->left->right->frequency);

            // printf("%c\t%d\n", tree->right->left->right->character, tree->right->left->right->frequency);
            // printf("%c\t%d\n", tree->right->right->character, tree->right->right->frequency);

            // AAAAAAAAAA
            // // printf(ANSI_COLOR_RED "1\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->character);

            // // printf(ANSI_COLOR_RED "2\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->left->character);
            // // printf(ANSI_COLOR_RED "3\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->left->left->character);
            // // printf(ANSI_COLOR_RED "4\n");
            // // printf(ANSI_COLOR_RESET);
            
            // // printf(ANSI_COLOR_RED "5\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->left->right->character);

            // // printf(ANSI_COLOR_RED "6\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->character);
            // // printf(ANSI_COLOR_RED "7\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->left->character);
            // // printf(ANSI_COLOR_RED "8\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->left->left->character);
            // // printf(ANSI_COLOR_RED "9\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->left->left->left->character);

            // // printf(ANSI_COLOR_RED "10\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->left->left->right->character);

            // // printf(ANSI_COLOR_RED "11\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c\n", tree->right->left->right->character);
            // // printf(ANSI_COLOR_RED "12\n");
            // // printf(ANSI_COLOR_RESET);
            // // printf("%c", tree->right->right->character);

            // print_pre_order(node_tree);
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
