#include <stdio.h>
#include <stdlib.h>
#include "../libs/priority_queue.h"

/** @discussion Checks if queue is empty
 * 
 * @param PQ A priority queue
 * 
 * @result true (1) or false (0)
 */
int isEmpty(priority_queue *PQ)
{
    return (PQ->head == NULL);
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
 * @param PQ A priority queue
 * @param character Each character of the file
 * @param frequency Character frequency
 */
void enqueue(priority_queue *PQ, char character, int frequency)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->character = character;
    new_node->frequency = frequency;

    if ((isEmpty(PQ)) || (frequency < PQ->head->frequency))
    {
        new_node->next = PQ->head;
        PQ->head = new_node;
    }
    else
    {
        NODE *current = PQ->head;
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
priority_queue *enqueue_f_array(int frequency_array[])
{
    priority_queue *PQ = (priority_queue *)malloc(sizeof(priority_queue));

    int i;

    for (i = 0; i < 256; i++)
    {
        if (frequency_array[i])
        {
            enqueue(PQ, i, frequency_array[i]);
        }
    }
    return PQ;
}

/**
 * @discussion Receives a cell from the priority queue and removes it from the queue
 *             Returns the value taken
 * 
 * @param PQ A priority queue
 * 
 * @result The pointer to node dequeued
 */
NODE *dequeue(priority_queue *PQ)
{
    if (isEmpty(PQ))
    {
        printf("Priority queue underflow\n");
        return NULL;
    }
    else
    {
        NODE *new_node = PQ->head;
        PQ->head = PQ->head->next;
        new_node->next = NULL;
        return new_node;
    }
}

/** @discussion Receives a priority queue and returns the highest value (frequency) of the queue
 * 
 * @param PQ A priority queue
 * 
 * @result The max value
 */
int minimum(priority_queue *PQ)
{
    if (isEmpty(PQ))
    {
        printf("Priority queue underflow\n");
        return -1;
    }
    else
    {
        return PQ->head->frequency;
    }
}

/** @discussion Returns the value of the head (start)
 * 
 * @param PQ A priority queue
 * 
 * @result The node of head
 */
NODE *peek(priority_queue *PQ)
{
    return PQ->head;
}

/** @discussion Prints all priority queue data 
 * 
 * @param PQ A priority queue
 */
void printing_pq(priority_queue *PQ)
{
    priority_queue *PQ_temp = PQ;
    // printf("%c\n", PQ_temp->head->character);
    while (PQ_temp->head != NULL)
    {
        printf("%c (%d)\n", PQ_temp->head->character, PQ_temp->head->frequency);
        PQ_temp->head = PQ_temp->head->next;
    }
    printf("\n");
}