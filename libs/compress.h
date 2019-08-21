#define MAX_SIZE 256

typedef unsigned char U_BYTE;

extern void get_trash_size(NODE_TREE *tree, int height, int *trash_size);

extern int is_bit_i_set(U_BYTE c, int i);

extern U_BYTE set_bit(U_BYTE c, int i);