#ifndef _COMPRESS_
#define _COMPRESS_

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

/** @discussion Recebe a árvore de Huffman, um ponteiro para o tamanho dela e outro para o tamanho do lixo
 * @discussion Calcula o tamanho da árvore e do lixo
 * 
 * @param tree A árvore de Huffman
 * @param height Irá armazenar o tamanho da árvore
 * @param trash_size Irá armazenar o tamanho do lixo na árvore
 */
extern void get_trash_size(NODE_TREE *tree, int height, int *trash_size);

extern int is_bit_i_set(U_BYTE c, int i);

extern U_BYTE set_bit(U_BYTE c, int i);

/** @discussion Recebe um array de bytes e o índice, e imprime os bits (cada byte)
 * 
 * @param bytes um array de bytes
 * @param pos O índice do array indicando o byte
 * 
 * @result A impressão do byte (bit a bit)
 */
extern void print_byte(int bytes[], int pos);

/** @discussion Recebe o arquivo vai ser comprimido, o array de bytes e a posição do byte no array
 * 
 * @param compressedFile O arquivo que vai ser comprimido
 * @param bytes O array que contém os bytes do lixo e do tamanho da árvore
 * @param pos O índice do array indicando o byte
 * 
 * @result A escrita dos bytes do lixo e do tamanho da árvore no arquivo
 */
// extern void write_byte_to_file(FILE *compressedFile, int bytes[], int pos);

/** @discussion Recebe o arquivo informado, a hash_table com os bits e o arquivo que vai ser comprimido
 * 
 * @param file O arquivo foi informado para ser comprimido
 * @param hash_table A hash table com os bits nas posições de seus respectivos caracteres
 * @param compressedFile O arquivo comprimido
 * 
 * @result Os bytes escritos no arquivo
 */
extern void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile);

#endif