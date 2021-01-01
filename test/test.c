#include "test.h"

int main(int argc, char const *argv[])
{
    UNITY_BEGIN();
    printf("---------- Testing input_int() ---------------\n");
    RUN_TEST(test_input_int);

    return UNITY_END();
}