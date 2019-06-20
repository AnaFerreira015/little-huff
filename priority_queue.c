#include <stdio.h>
#include <stdlib.h>
#include "libs/priority_queue.h"

/** Checks if queue is empty */
int isEmpty(priority_queue *PQ)
{
    return (PQ->head == NULL);
}

/** Creates a new cell for the priority queue and returns it */
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

/**
 * - Receives a cell from the priority queue and removes it from the queue
 * - Returns the value taken
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

/** Receives a priority queue and returns the highest value (frequency) of the queue */
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

/** Returns the value of the head (start) */
int peek(priority_queue *PQ)
{
    return PQ->head;
}

int main()
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));

    return 0;
}