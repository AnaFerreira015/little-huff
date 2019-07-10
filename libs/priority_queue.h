#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

typedef struct NODE
{
    char character;
    int frequency;
    struct NODE *next;
} NODE;

typedef struct priority_queue
{
    NODE *head;
} priority_queue;

/** Checks if queue is empty
 * @param a priority queue
 */
extern int isEmpty(priority_queue *PQ);

/** Creates a new cell for the priority queue and returns it
 * @param each character of the file and its respective frequency
 */
extern NODE *creating_element(char character, int frequency);

/**
 * - You receive a cell from the priority queue and the data to add to it
 * - Add the parameter data in the queue
 * @param a priority queue, each character of the file and its frequency
 */
extern void enqueue(priority_queue *PQ, char character, int frequency);

/** Line each character and frequency of the array
 * @param a frequency array
 */
extern priority_queue *enqueue_f_array(int frequency_array[]);

/**
 * - Receives a cell from the priority queue and removes it from the queue
 * - Returns the value taken
 * @param a priority queue
 */
extern NODE *dequeue(priority_queue *PQ);

/** Receives a priority queue and returns the highest value (frequency) of the queue
 * @param a priority queue
 */
extern int maximum(priority_queue *PQ);

/** Returns the value of the head (start)
 * @param a priority queue
 */
extern NODE *peek(priority_queue *PQ);

/** Prints all priority queue data 
 * @param a priority queue
 */
extern void printing_pq(priority_queue *PQ);

#endif
