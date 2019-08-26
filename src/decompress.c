#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"


NODE_TREE *creating_tree(NODE_TREE *node, FILE *compress)
{
    U_BYTE character;
    fscanf(compress, "%c", &character);

    if(character == '*')//se for um pai cria um no e chama a recursao
    {
        node = create_node();
        node->character = '*';
        node->character = character;
        creating_tree(node->left, compress);
        creating_tree(node->right, compress);
    }
    else // é um caracter
    {
        if(character == '\\') //escape
        {
            fscanf(compress,"%c",&character); //verifico se o proximo caracter é * ou \
            creating_tree(node, compress); //crio o
        }
    }
    
}