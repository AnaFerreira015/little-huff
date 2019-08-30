#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

typedef struct NODE_TREE NODE_TREE;

/**
 * @typedef PRIORITY_QUEUE
 * 
 * @discussion Properties of PRIORITY_QUEUE (head) are stored in this structure
 * 
 * @field head Pointer to the first node in the queue
*/
typedef struct PRIORITY_QUEUE
{
    NODE_TREE *head;
    int size;
} PRIORITY_QUEUE;

/** @discussion Checks if queue is empty
 * 
 * @param pq A priority queue
 * 
 * @result true (1) or false (0)
 */
extern int isEmpty(PRIORITY_QUEUE *pq);

/**
 * @discussion You receive a cell from the priority queue and the data to add to it
 *             Add the parameter data in the queue
 * 
 * @param pq A priority queue
 * @param character Each character of the file
 * @param frequency Character frequency
 */
extern void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree);

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
extern NODE_TREE *dequeue(PRIORITY_QUEUE *pq);

/** @discussion Prints all priority queue data 
 * 
 * @param pq A priority queue
 */
extern void printing_pq(PRIORITY_QUEUE *pq);

#endif
