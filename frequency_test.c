#include "frequency.c"
#include "CUnit/Basic.h"

void frequency_test() {
    CU_ASSERT_EQUAL(create_frequency_array("test-frequency"), "test-frequency");
}

int main()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = NULL;

    // Add a suite to the repository
    pSuite = CU_add_suite("frequency_test_suite", "test-frequency", 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "frequency_test", frequency_test)){
        CU_cleanup_registry();
        return CU_get_error();
    }

   // Sets the basic run mode, CU_BRM will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);

   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}