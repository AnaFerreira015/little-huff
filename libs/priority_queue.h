#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

/**
 * @typedef NODE
 * 
 * @discussion All properties of node (character, frequency, ...)
 *             are stored in this structure
 * 
 * @field character Characters stored in the file
 * @field frequency Frequency of each character above
 * @field next Pointer to the next node
*/
typedef struct NODE
{
    char character;
    int frequency;
    struct NODE *next;
} NODE;

/**
 * @typedef PRIORITY_QUEUE
 * 
 * @discussion Properties of PRIORITY_QUEUE (head) are stored in this structure
 * 
 * @field head Pointer to the first node in the queue
*/
typedef struct PRIORITY_QUEUE
{
    NODE *head;
} PRIORITY_QUEUE;

/** @discussion Checks if queue is empty
 * 
 * @param pq A priority queue
 * 
 * @result true (1) or false (0)
 */
extern int isEmpty(PRIORITY_QUEUE *pq);

/** @discussion Creates a new cell for the priority queue and returns it
 * 
 * @param character Each character of the file 
 * @param frequency Its respective character frequency
 * 
 * @result A pointer to new node
 */
extern NODE *creating_element(char character, int frequency);

/**
 * @discussion You receive a cell from the priority queue and the data to add to it
 *             Add the parameter data in the queue
 * 
 * @param pq A priority queue
 * @param character Each character of the file
 * @param frequency Character frequency
 */
extern void enqueue(PRIORITY_QUEUE *pq, char character, int frequency);

/** @discussion Line each character and frequency of the array
 * 
 * @param frequency_array A frequency array
 * 
 * @result A priority queue with frequency
 */
extern PRIORITY_QUEUE *enqueue_f_array(int frequency_array[]);

/**
 * @discussion Receives a cell from the priority queue and removes it from the queue
 *             Returns the value taken
 * 
 * @param pq A priority queue
 * 
 * @result The pointer to node dequeued
 */
extern NODE *dequeue(PRIORITY_QUEUE *pq);

/** @discussion Receives a priority queue and returns the highest value (frequency) of the queue
 * 
 * @param pq A priority queue
 * 
 * @result The max value
 */
extern int minimum(PRIORITY_QUEUE *pq);

/** @discussion Returns the value of the head (start)
 * 
 * @param pq A priority queue
 * 
 * @result The node of head
 */
extern NODE *peek(PRIORITY_QUEUE *pq);

/** @discussion Prints all priority queue data 
 * 
 * @param pq A priority queue
 */
extern void printing_pq(PRIORITY_QUEUE *pq);

#endif
