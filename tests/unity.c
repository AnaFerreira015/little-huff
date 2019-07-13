#include <CUnit/Basic.h>
#include "../src/priority_queue.c"

void creating_element_test()
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->character = 'x';
    new->frequency = 6;
    new->next = NULL;

    NODE *test = creating_element('x', 6);
    CU_ASSERT(test != NULL);
    CU_ASSERT_EQUAL(new->frequency, test->frequency);
    CU_ASSERT_EQUAL(new->character, test->character);
    CU_ASSERT_PTR_EQUAL(new->next, test->next);
}

void enqueue_test()
{
    priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
    int array[3] = {1, 5, 7};

    enqueue(pq, 'x', 2);
    enqueue(pq, 'y', 5);
    enqueue(pq, 'z', 7);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, array[2]);
}

void queue_empty_test()
{
    priority_queue *pq;
    CU_ASSERT(pq != NULL);
}

void dequeue_test()
{
    priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
    int array[4] = {1, 2, 3, 4};

    enqueue(pq, 'x', 6);
    enqueue(pq, 'y', 3);
    enqueue(pq, 'z', 4);
    dequeue(pq);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, array[3]);
}

void maximum_test()
{
    priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));

    enqueue(pq, 'x', 6);
    enqueue(pq, 'y', 11);
    enqueue(pq, 'z', 4);

    int i, max = 0;
    for (i = 0; i < pq->head->frequency; ++i)
    {
        if (pq->head->frequency > max)
        {
            max = pq->head->frequency;
            pq->head->frequency = max;
        }
    }

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(max, 11);
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
    if (NULL == CU_add_test(pSuite, "test - 1", creating_element_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 2", enqueue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 3", queue_empty_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", dequeue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", maximum_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
}
