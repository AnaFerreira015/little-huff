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
    return (pq->size == 0);
}

PRIORITY_QUEUE *createEmptyQueue()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    pq->head = NULL;
    pq->size = 0;
    return pq;
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
    if (pq->size == 0)
    {
        pq->size++;
        aux->next = pq->head;
        pq->head = aux;
    }
    else
    {
        pq->size++;
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

NODE_TREE *build_node_tree(U_BYTE character, int frequency, NODE_TREE *left, NODE_TREE *right)
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->character = character;
    node_tree->frequency = frequency;
    node_tree->next = NULL;
    node_tree->left = left;
    node_tree->right = right;

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
    pq->head = NULL;
    NODE_TREE *node_tree;
    int i;

    for (i = 0; i < 256; i++)
    {
        if (frequency_array[i])
        {
            node_tree = build_node_tree(i, frequency_array[i], NULL, NULL);
            enqueue(pq, node_tree);
        }
    }
    // printing_pq(pq);
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
    NODE_TREE *head = pq->head;
    pq->head = pq->head->next;
    pq->size--;
    return head;
    // printf("oi\n");
    // NODE_TREE *current = pq->head;
    //     printf("pq->head == NULL %d\n", pq->head == NULL);
    // // printf("pq->head->frequency: %d", pq->head == NULL);
    // NODE_TREE *prev = NULL;
    // while (current != NULL && !(current->character == ))
    // {
    //     printf("AQUI DENTRO\n");
    //     prev = current;
    //     current = current->next;
    // }
    // if (prev != NULL)
    // {
    //     printf("current == NULL == %d\n", current == NULL);
    //     prev->next = current->next;
    // }
    // else
    // {
    //     pq->head = current->next;
    // }
    // pq->size--;
    // current->next = NULL;
    // return current;
}

/** @discussion Prints all priority queue data 
 * 
 * @param pq A priority queue
 */
void printing_pq(PRIORITY_QUEUE *pq)
{
    NODE_TREE *node = pq->head;

    while (node != NULL)
    {
        printf("%c (%d)\n", node->character, node->frequency);
        node = node->next;
    }
    printf("\n");
}