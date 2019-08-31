#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

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

/**
 * @discussion The function receives a file and returns an array with the frequency of each byte in the file 
 *
 * @param file File read from main.c
 * @param freq The array for frequency 
 */
extern void create_frequency_array(FILE *file, int freq[]);

/**
 * @discussion Receive an array already created and display what's in it
 * 
 * @param array A frequency array
 */
extern void printing_frequency_array(int *array);

#endif
