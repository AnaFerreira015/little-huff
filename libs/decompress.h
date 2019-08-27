#ifndef _DECOMPRESS_
#define _DECOMPRESS_

#include "./huffman_tree.h"

/**
 * @define MAX_SIZE
 * 
 * @discussion Maximum array size
*/
#define MAX_SIZE 256

/**
 * @typedef U_BYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_BYTE;

extern NODE_TREE *creating_tree(NODE_TREE *node, FILE *compress);

#endif 