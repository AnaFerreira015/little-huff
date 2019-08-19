#include <CUnit/Basic.h>
#include <stdlib.h>
#include "../src/priority_queue.c"
#include "../src/huffman_tree.c"

void enqueue_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));

    int array[3] = {2, 5, 9};

    CU_ASSERT(pq != NULL);

    node_tree->frequency = 10;
    enqueue(pq, node_tree);
    node_tree->frequency = 9;
    enqueue(pq, node_tree);
    node_tree->frequency = 2;
    enqueue(pq, node_tree);

    CU_ASSERT_EQUAL(node_tree->frequency, array[0]);
}

void queue_empty_test()
{
    PRIORITY_QUEUE *pq;
    CU_ASSERT(pq != NULL);
}

void dequeue_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    int array[5] = {0, 1, 2, 3, 4};

    CU_ASSERT(pq != NULL);

    node_tree->frequency = 4;
    enqueue(pq, node_tree);
    node_tree->frequency = 2;
    enqueue(pq, node_tree);
    node_tree->frequency = 0;
    enqueue(pq, node_tree);
    node_tree->frequency = 1;
    enqueue(pq, node_tree);
    node_tree->frequency = 3;
    enqueue(pq, node_tree);

    dequeue(pq);

    CU_ASSERT_EQUAL(pq->head->frequency, array[3]);
}

void enqueue_frequency_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));

    int i;
    int frequency_array[i];

    for (i = 0; i < 6; i++)
    {
        frequency_array[i] = i;
    }

    for (i = 0; i < 6; i++)
    {
        if (frequency_array[i])
        {
            node_tree = build_node_tree(i, frequency_array[i]);
            enqueue(pq, node_tree);
        }
    }

    CU_ASSERT_EQUAL(node_tree->frequency, 5);
}

int main()
{

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL, pSuite2 = NULL;
    pSuite = CU_add_suite("TEST", 0, 0);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 1", enqueue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 2", queue_empty_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 3", dequeue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", enqueue_frequency_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
}
