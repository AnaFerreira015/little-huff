#include <stdio.h>
#include <stdlib.h>
#include "../libs/priority_queue.h"

/** @discussion Checks if queue is empty
 * 
 * @param pq A priority queue
 * 
 * @result true (1) or false (0)
 */
int isEmpty(PRIORITY_QUEUE *pq)
{
    return (pq->head == NULL);
}

/** @discussion Creates a new cell for the priority queue and returns it
 * 
 * @param character Each character of the file 
 * @param frequency Its respective character frequency
 * 
 * @result A pointer to new node
 */
NODE *creating_element(char character, int frequency)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->next = NULL;

    return new_node;
}

/**
 * @discussion You receive a cell from the priority queue and the data to add to it
 *             Add the parameter data in the queue
 * 
 * @param pq A priority queue
 * @param character Each character of the file
 * @param frequency Character frequency
 */
void enqueue(PRIORITY_QUEUE *pq, char character, int frequency)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->character = character;
    new_node->frequency = frequency;
    // new_node->next = NULL;    

    if ((isEmpty(pq)) || (frequency < pq->head->frequency))
    {
        new_node->next = pq->head;
        pq->head = new_node;
    }
    else
    {
        NODE *current = pq->head;
        while ((current->next != NULL) && (current->next->frequency < frequency))
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

/** @discussion Line each character and frequency of the array
 * 
 * @param frequency_array A frequency array
 * 
 * @result A priority queue with frequency
 */
PRIORITY_QUEUE *enqueue_f_array(int frequency_array[])
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));

    int i;

    for (i = 0; i < 256; i++)
    {
        if (frequency_array[i])
        {
            enqueue(pq, i, frequency_array[i]);
        }
    }
    return pq;
}

/**
 * @discussion Receives a cell from the priority queue and removes it from the queue
 *             Returns the value taken
 * 
 * @param pq A priority queue
 * 
 * @result The pointer to node dequeued
 */
NODE *dequeue(PRIORITY_QUEUE *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority queue underflow\n");
        return NULL;
    }
    else
    {
        NODE *new_node = pq->head;
        pq->head = pq->head->next;
        new_node->next = NULL;
        return new_node;
    }
}

/** @discussion Receives a priority queue and returns the highest value (frequency) of the queue
 * 
 * @param pq A priority queue
 * 
 * @result The max value
 */
int minimum(PRIORITY_QUEUE *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority queue underflow\n");
        return -1;
    }
    else
    {
        return pq->head->frequency;
    }
}

/** @discussion Returns the value of the head (start)
 * 
 * @param pq A priority queue
 * 
 * @result The node of head
 */
NODE *peek(PRIORITY_QUEUE *pq)
{
    return pq->head;
}

/** @discussion Prints all priority queue data 
 * 
 * @param pq A priority queue
 */
void printing_pq(PRIORITY_QUEUE *pq)
{
    PRIORITY_QUEUE *pq_temp = pq;
    // printf("%c\n", pq_temp->head->character);
    while (pq_temp->head != NULL)
    {
        printf("%c (%d)\n", pq_temp->head->character, pq_temp->head->frequency);
        pq_temp->head = pq_temp->head->next;
    }
    printf("\n");
}