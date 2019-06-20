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

/** Checks if queue is empty */
int isEmpty(priority_queue *PQ);

/** Creates a new cell for the priority queue and returns it */
NODE *creating_element(char character, int frequency);

/**
 * - You receive a cell from the priority queue and the data to add to it
 * - Add the parameter data in the queue
 */
void enqueue(priority_queue *PQ, char character, int frequency);
/**
 * - Receives a cell from the priority queue and removes it from the queue
 * - Returns the value taken
 */
NODE *dequeue(priority_queue *PQ);

/** Receives a priority queue and returns the highest value (frequency) of the queue */
int maximum(priority_queue *PQ);

/** Returns the value of the head (start) */
int peek(priority_queue *PQ);

#endif