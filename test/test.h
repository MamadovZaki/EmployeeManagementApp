#include "../include/utils.h"
#include "../Unity/src/unity.h"

void setUp(void) {}    /* Is run before every test, put unit init calls here. */
void tearDown(void) {} /* Is run after every test, put unit clean-up calls here. */

void test_input_int(void)
{
    printf("\nPlease input 40 to test that func produces 40\n");
    TEST_ASSERT_EQUAL(40, input_int("Please add an integer\n"));

    printf("\nPlease input nothing to test that func produces 0\n");
    TEST_ASSERT_EQUAL(0, input_int("Please add an integer\n"));

    printf("\nPlease input a string to test that func produces 0\n");
    TEST_ASSERT_EQUAL(0, input_int("Please add an integer\n"));

    //printf("\nPlease input a number greater than 10 digits that func produces 0\n");
    //TEST_ASSERT_EQUAL(0, input_int("Please add an integer\n"));
}
