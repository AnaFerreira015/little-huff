#include <CUnit/Basic.h>
#include "../src/priority_queue.c"

void enqueue_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    int array[3] = {2, 5, 7};

    enqueue(pq, 'x', 2);
    enqueue(pq, 'y', 5);
    enqueue(pq, 'z', 7);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, array[0]);
}

void queue_empty_test()
{
    PRIORITY_QUEUE *pq;
    CU_ASSERT(pq != NULL);
}

void dequeue_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    int array[4] = {1, 2, 3, 4};

    enqueue(pq, 'x', 6);
    enqueue(pq, 'y', 3);
    enqueue(pq, 'z', 4);
    dequeue(pq);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, array[3]);
}

void minimum_test()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));

    enqueue(pq, 'x', 6);
    enqueue(pq, 'y', 11);
    enqueue(pq, 'z', 4);

    int i, min = 0;
    for (i = 0; i < pq->head->frequency; ++i)
    {
        if (pq->head->frequency > min)
        {
            min = pq->head->frequency;
            pq->head->frequency = min;
        }
    }

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(min, 4);
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
    if (NULL == CU_add_test(pSuite, "test - 4", minimum_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
}
