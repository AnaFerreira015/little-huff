#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

#define MAX_SIZE 256

/**
 * - Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char BYTE;

/**
 * The function receives an array, its size and an index, and returns an array initialized with 0's
 */
extern void initialize_array(int *array, int size, int i);

/**
* The function receives the file name and returns an array with the frequency of each byte in the file
 */
extern int *create_frequency_array(char arq[]);

/**
 * Receive an array already created and display what's in it
 */
extern void printing_frequency_array(int *array);

#endif
