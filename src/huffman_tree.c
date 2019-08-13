#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"
#include "../libs/priority_queue.h"

/**
 * @discussion Creates a new node for later addition to the huffman tree.
 * 
 * @result The new node created
 */
NODE_TREE *create_node()
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->frequency = 0;
    node_tree->character = ' ';
    node_tree->left = NULL;
    node_tree->right = NULL;
    node_tree->next = NULL;

    return node_tree;
}

NODE_TREE *associate_nodes(NODE_TREE *node) {
    NODE_TREE *node_tree = create_node();

    node_tree->character = node->character;
    node_tree->frequency = node->frequency;

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
    NODE_TREE *node_huff = (NODE_TREE*)malloc(sizeof(NODE_TREE));

    // NODE_TREE *node_tree1 = associate_nodes(node1);
    // NODE_TREE *node_tree2 = associate_nodes(node2);

    node_huff->left = node1;
    node_huff->right = node2;
    node_huff->character = '*';
    node_huff->frequency = node1->frequency + node2->frequency;

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

NODE_TREE *build_node(PRIORITY_QUEUE *pq) {
    // int t;
    NODE_TREE *node_huff = NULL;
    while (pq->head->next != NULL)
    {
    // printf("\ntraste\n");
        // printf("aaaaa\n");
        NODE_TREE *node1 = dequeue(pq);
        NODE_TREE *node2 = dequeue(pq);

        node_huff = huffman_create_node(node1, node2);

        enqueue(pq, node_huff);
        // printf("debug\n");
        // pq->head = pq->head->next;
        // scanf("%d", &t);
        
    }
    NODE_TREE *test = dequeue(pq);
    // printf("teste dequeue\n");

    return test;
}

int isEmty(NODE_TREE *node_tree) {
    return (node_tree == NULL);
}

void print_pre_order(NODE_TREE *node_tree) {
    if(node_tree != NULL) {
        // printf("%c (%d)\n", node_tree->character, node_tree->frequency);
        print_pre_order(node_tree->left);
        print_pre_order(node_tree->right);
    }
}
