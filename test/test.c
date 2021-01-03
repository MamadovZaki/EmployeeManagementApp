#include "test.h"

int main(int argc, char const *argv[])
{
    UNITY_BEGIN();
    //printf("---------- Testing input_int() ---------------\n");
    //RUN_TEST(test_input_int);

    printf("\n");

    printf("---------- Testing input_str() ---------------\n");
    RUN_TEST(test_input_str);

    return UNITY_END();
}