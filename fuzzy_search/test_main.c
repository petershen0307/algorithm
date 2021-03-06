#include <stdio.h>
#include <assert.h>

#include "levenshtein_distance.h"
#include "minunit.h"

static char * all_tests();
static char *  test_calc_distance();

int assert_run = 0;
int tests_run = 0;

int main()
{
    char *result = all_tests();
    if (result != 0)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("ALL TESTS PASSED\n");
    }
    printf("Assert run: %d\n", assert_run);
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}

static char * all_tests()
{
    mu_run_test(test_calc_distance);
    return 0;
}

static char * test_calc_distance()
{
    mu_assert("error, calc_distance(\"abc\", \"abc\") != 0", calc_distance("abc", "abc") == 0);
    mu_assert("error, calc_distance(\"abcd\", \"abc\") != 1", calc_distance("abcd", "abc") == 1);
    mu_assert("error, calc_distance(\"abc\", \"abcd\") != 1", calc_distance("abc", "abcd") == 1);
    mu_assert("error, calc_distance(\"abc\", \"12345\") != 8", calc_distance("abc", "12345") == 5);
    mu_assert("error, calc_distance(\"sitting\", \"kitten\") != 3", calc_distance("sitting", "kitten") == 3);
    mu_assert("error, calc_distance(\"\", \"kitten\") != 6", calc_distance("", "kitten") == 6);
    mu_assert("error, calc_distance(\"what\", \"water\") != 6", calc_distance("what", "water") == 3);
    return 0;
}
