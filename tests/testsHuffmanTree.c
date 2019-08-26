#include <CUnit/Basic.h>
#include <stdlib.h>
#include "../src/priority_queue.c"
#include "../src/huffman_tree.c"

void create_node_test()
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->frequency = 0;
    node_tree->left = NULL;
    node_tree->right = NULL;
    node_tree->next = NULL;

    CU_ASSERT(node_tree != NULL);
    CU_ASSERT_EQUAL(node_tree->frequency,0);
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
    if (NULL == CU_add_test(pSuite, "test - 1", create_node_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    return 0;
}