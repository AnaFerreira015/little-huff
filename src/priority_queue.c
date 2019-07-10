#include <stdio.h>
#include <stdlib.h>
#include "../libs/priority_queue.h"

/** Checks if queue is empty
 * @param a priority queue
 */
int isEmpty(priority_queue *PQ)
{
    return (PQ->head == NULL);
}

/** Creates a new cell for the priority queue and returns it
 * @param each character of the file and its respective frequency
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
 * - You receive a cell from the priority queue and the data to add to it
 * - Add the parameter data in the queue
 * @param a priority queue, each character of the file and its frequency
 */
void enqueue(priority_queue *PQ, char character, int frequency)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->character = character;
    new_node->frequency = frequency;

    if ((isEmpty(PQ)) || (frequency > PQ->head->frequency))
    {
        new_node->next = PQ->head;
        PQ->head = new_node;
    }
    else
    {
        NODE *current = PQ->head;
        while ((current->next != NULL) && (current->next->frequency > frequency))
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

/** Line each character and frequency of the array
 * @param a frequency array
 */
priority_queue *enqueue_f_array(int frequency_array[]) {
    priority_queue *PQ = (priority_queue*)malloc(sizeof(priority_queue));
    
    int i;
    
    for(i = 0; i < 256; i++) {
        if(frequency_array[i]){
            enqueue(PQ, i, frequency_array[i]);
        }
    }
    return PQ;
}

/**
 * - Receives a cell from the priority queue and removes it from the queue
 * - Returns the value taken
 * @param a priority queue
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

/** Receives a priority queue and returns the highest value (frequency) of the queue
 * @param a priority queue
 */
int maximum(priority_queue *PQ)
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

/** Returns the value of the head (start)
 * @param a priority queue
 */
NODE *peek(priority_queue *PQ)
{
    return PQ->head;
}

/** Prints all priority queue data 
 * @param a priority queue
 */
void printing_pq(priority_queue *PQ)
{
    priority_queue *PQ_temp = PQ;
    // printf("%c\n", PQ_temp->head->character);
    while(PQ_temp->head != NULL) 
    {
        printf("%c (%d)\n", PQ_temp->head->character, PQ_temp->head->frequency);
        PQ_temp->head = PQ_temp->head->next;
    }
    printf("\n");
}