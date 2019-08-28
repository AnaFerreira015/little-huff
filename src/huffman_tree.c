#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"
#include "../libs/priority_queue.h"

/**
 * @define ANSI_COLOR_RED
 * 
 * @discussion Inserts cyan color into terminal
*/
#define ANSI_COLOR_CYAN "\033[1;36m"

/**
 * @define ANSI_COLOR_RESET
 * 
 * @discussion Returns to the default print color
*/
#define ANSI_COLOR_RESET "\033[0;0m"

/**
 * @discussion Creates a new node for later addition to the huffman tree.
 * 
 * @result The new node created
 */
NODE_TREE *create_node()
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->frequency = 0;
    node_tree->left = NULL;
    node_tree->right = NULL;
    node_tree->next = NULL;
    return node_tree;
}

NODE_TREE *create_node_enqueued(U_BYTE character, int frequency)
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->character = character;
    node_tree->frequency = frequency;
    node_tree->left = NULL;
    node_tree->right = NULL;
    node_tree->next = NULL;
    return node_tree;
}

/**
 * @discussion Receives two nodes and creates a parent node in the tree by adding the '*' symbol
 * 
 * @param node1 The first lowest frequency node in the queue
 * @param node2 The second lowest frequency node in the queue
 * 
 * @result A knot of huffman tree
 */
NODE_TREE *huffman_create_node(NODE_TREE *node1, NODE_TREE *node2)
{
    NODE_TREE *node_huff = (NODE_TREE *)malloc(sizeof(NODE_TREE));

    node_huff->left = node1;
    node_huff->right = node2;
    node_huff->character = '*';
    if (node2 == NULL)
        node_huff->frequency = node1->frequency;
    else
        node_huff->frequency = node1->frequency + node2->frequency;
    node_huff->next = NULL;

    return node_huff;
}

/**
 * @discussion Get two nodes and compare which one is the smallest
 * 
 * @param node1 A queue node
 * @param node2 A queue node
 * 
 * @result True (1) or False (0)
 */
int equate_nodes(NODE_TREE *node1, NODE_TREE *node2)
{
    if (node1->frequency < node2->frequency)
    {
        return 1;
    }
    return 0;
}

NODE_TREE *build_node(PRIORITY_QUEUE *pq)
{
    printf("aqui\n");
    printf("aaa %d\n", (pq->head == NULL));
    printf("teste %c %d\n", pq->head->character, pq->head->frequency);

    NODE_TREE *node_huff = NULL;
    if (pq->head->next == NULL)
    {
        printf("nózinho\n");
        return huffman_create_node(pq->head, NULL);
    }
    while (pq->head->next != NULL)
    {
        printf("while\n");
        NODE_TREE *node1 = dequeue(pq);
        NODE_TREE *node2 = dequeue(pq);

        node_huff = huffman_create_node(node1, node2);

        enqueue(pq, node_huff);
    }
    //  printf("retornou\n");
    // NODE_TREE *node1, *node2;
    // int frequency;

    // while(pq->head->next != NULL) {
    //     node1 = dequeue(pq);
    //     node2 = dequeue(pq);

    //     frequency = (node1->frequency) + (node2->frequency);

    //     NODE_TREE *enqueued = create_node_enqueued('*', frequency);
    //     enqueued->left = node1;
    //     enqueued->right = node2;

    //     enqueue(pq, enqueued);
    // }
    return pq->head;
}

int isEmptyTree(NODE_TREE *node_tree)
{
    return (node_tree == NULL);
}

int isLeaf(NODE_TREE *tree)
{
    return ((tree->left == NULL) && (tree->right == NULL));
}

void print_pre_order(NODE_TREE *node_tree)
{
    if (node_tree != NULL)
    {
        printf(ANSI_COLOR_CYAN "%c\n", node_tree->character);
        print_pre_order(node_tree->left);
        print_pre_order(node_tree->right);
    }
    printf(ANSI_COLOR_RESET);
}

void size_tree_and_preorder(NODE_TREE *tree, int *size, U_BYTE *tree_preorder) 
{
    if(!isEmptyTree(tree)) 
    {
        if(isLeaf(tree)) 
        {
            if(tree->character == '*' || tree->character == '\\') 
            {
                tree_preorder[*size] = '\\';
                *size += 1;
            }       
        }
        tree_preorder[*size] = tree->character;
        *size += 1;      
        size_tree_and_preorder(tree->left, size, tree_preorder);
        size_tree_and_preorder(tree->right, size, tree_preorder);
    }
}