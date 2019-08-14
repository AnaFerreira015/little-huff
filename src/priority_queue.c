#include <stdio.h>
#include <stdlib.h>
#include "../libs/priority_queue.h"
#include "../libs/huffman_tree.h"

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

/**
 * @discussion You receive a cell from the priority queue and the data to add to it
 *             Add the parameter data in the queue
 * 
 * @param pq A priority queue
 * @param character Each character of the file
 * @param frequency Character frequency
 */
void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree)
{
    NODE_TREE *aux = node_tree;
    if (isEmpty(pq))
    {
        aux->next = pq->head;
        pq->head = aux;
    }
    else
    {
        NODE_TREE *current = pq->head;
        NODE_TREE *previous = NULL;
        while ((current != NULL) && (current->frequency < aux->frequency))
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            aux->next = pq->head;
            pq->head = aux;
            return;
        }
        previous->next = aux;
        aux->next = current;
    }
}

NODE_TREE *build_node_tree(char character, int frequency)
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->character = character;
    node_tree->frequency = frequency;
    node_tree->next = NULL;
    node_tree->left = NULL;
    node_tree->right = NULL;

    return node_tree;
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
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));

    int i;

    for (i = 0; i < 256; i++)
    {
        if (frequency_array[i])
        {
            node_tree = build_node_tree(i, frequency_array[i]);
            // enfileirar
            enqueue(pq, node_tree);
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
NODE_TREE *dequeue(PRIORITY_QUEUE *pq)
{
    if (!isEmpty(pq))
    {
        NODE_TREE *new_node = pq->head;
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
    if (!isEmpty(pq))
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
NODE_TREE *peek(PRIORITY_QUEUE *pq)
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

    while (pq_temp->head != NULL)
    {
        printf("%c (%d)\n", pq_temp->head->character, pq_temp->head->frequency);
        pq_temp->head = pq_temp->head->next;
    }
    printf("\n");
}