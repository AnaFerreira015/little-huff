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

/** @discussion Creates a new cell for the priority queue and returns it
 * 
 * @param character Each character of the file 
 * @param frequency Its respective character frequency
 * 
 * @result A pointer to new node
 */
NODE_TREE *creating_element(char character, int frequency)
{
    NODE_TREE *new_node = (NODE_TREE *)malloc(sizeof(NODE_TREE));
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
void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree)
{
    // NODE *new_node = (NODE *)malloc(sizeof(NODE));
    // new_node->character = node_tree->character;
    // new_node->frequency = node_tree->frequency;
    // new_node->next = NULL;    

    if ((isEmpty(pq)) || (node_tree->frequency < pq->head->frequency))
    {
        node_tree->next = pq->head;
        pq->head = node_tree;
    }
    else
    {
        NODE_TREE *current = pq->head;
        while ((current->next != NULL) && (current->next->frequency < node_tree->frequency))
        {
            current = current->next;
        }
        node_tree->next = current->next;
        current->next = node_tree;
    }
}

NODE_TREE *build_node_tree(char character, int frequency)
{
    NODE_TREE *node_tree = (NODE_TREE*)malloc(sizeof(NODE_TREE));
    // printf("desgraça\n");
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
    NODE_TREE *node_tree = (NODE_TREE*)malloc(sizeof(NODE_TREE));

    int i;

    for (i = 0; i < 256; i++)
    {
        if (frequency_array[i])
        {
            // printf("desgraça 2\n");
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
    // if (!isEmpty(pq))
    // {
        // printf("teste\n");
        NODE_TREE *new_node = pq->head;
        pq->head = pq->head->next;
        new_node->next = NULL;
        printf("DEQUEUE %c %d\n", new_node->character, new_node->frequency);
        return new_node;
    // }
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
    // printf("%c\n", pq_temp->head->character);
    while (pq_temp->head != NULL)
    {
        printf("%c (%d)\n", pq_temp->head->character, pq_temp->head->frequency);
        pq_temp->head = pq_temp->head->next;
    }
    printf("\n");
}