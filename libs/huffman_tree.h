#ifndef _HUFFMAN_TREE_
#define _HUFFMAN_TREE_

/**
 * @typedef uBYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char uBYTE;

/**
 * @typedef NODE_TREE
 * 
 * @discussion All properties of node (character, frequency, ...)
 *             are stored in this structure
 * 
 * @field character Characters stored in the file
 * @field frequency Frequency of each character above
 * @field left Pointer to the left child
 * @field rigth Pointer to the right child
*/
typedef struct NODE_TREE
{
    uBYTE character;
    int frequency;
    struct NODE_TREE *left;
    struct NODE_TREE *right;
} NODE_TREE;

/**
 * @discussion Creates a new node for later addition to the huffman tree.
 * 
 * @result The new node created
 */
extern NODE_TREE *create_node();

/**
 * @discussion Receives two nodes and creates a parent node in the tree by adding the '*' symbol
 * 
 * @param node1 The first lowest frequency node in the queue
 * @param node2 The second lowest frequency node in the queue
 * 
 * @result A knot of huffman tree
 */
extern NODE_TREE *huffman_create_node(NODE_TREE *node1, NODE_TREE *node2);

/**
 * @discussion Get two nodes and compare which one is the smallest
 * 
 * @param node1 A queue node
 * @param node2 A queue node
 * 
 * @result True (1) or False (0)
 */
extern int equate_nodes(NODE_TREE *node1, NODE_TREE *node2);

#endif
