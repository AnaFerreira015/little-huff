#ifndef _FREQUENCY_H_
#define _FREQUENCY_H_

/**
 * @define MAX_SIZE
 * 
 * @discussion Maximum array size
*/
#define MAX_SIZE 256

/**
 * @typedef BYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char BYTE;

/**
 * @discussion The function receives an array, its size and an index, and returns an array initialized with 0's
 * 
 * @param array An array
 * @param size The size of array
 * @param i An index
 */
extern void initialize_array(int *array, int size, int i);

/**
 * @discussion The function receives the file name and returns an array with the frequency of each byte in the file 
 *
 * @param arq The name of a file
 * @param freq The array for frequency 
 */
extern void create_frequency_array(char arq[], int freq[]);

/**
 * @discussion Receive an array already created and display what's in it
 * 
 * @param array A frequency array
 */
extern void printing_frequency_array(int *array);

#endif
