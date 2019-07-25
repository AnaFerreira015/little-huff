#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"

/**
 * @discussion Creates a new node for later addition to the huffman tree.
 * 
 * @result The new node created
 */
NODE_TREE *create_node()
{
    NODE_TREE *node = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node->frequency = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
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
    NODE_TREE *huffman_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    huffman_tree->left = node1;
    huffman_tree->right = node2;
    huffman_tree->frequency = node1->frequency + node2->frequency;
    huffman_tree->character = '*';

    return huffman_tree;
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