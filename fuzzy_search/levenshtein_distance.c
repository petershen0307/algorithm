#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX2(a, b) (a > b) ? a : b
#define ARRAY_REAL_SIZE(type, str_len) sizeof(type) * str_len + 1
#define ARRAY_LOGIC_SIZE(str_len) str_len + 1

void print_2d(int **target, int const d1_len, int const d2_len)
{
    for (int i = 0; i < d1_len; ++i)
    {
        for (int j = 0; j < d2_len; ++j)
        {
            printf("%d ", target[i][j]);
        }
        printf("\n");
    }
}

int min3(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int calc_distance(char const *str1, char const *str2)
{
    int const len_str1 = strlen(str1);
    int const len_str2 = strlen(str2);
    int **result;
    result = (int **)malloc(ARRAY_REAL_SIZE(int*, len_str1));
    for (int i = 0; i < len_str1 + 1; ++i)
    {
        result[i] = (int *)malloc(ARRAY_REAL_SIZE(int, len_str2));
        memset(result[i], 0, ARRAY_REAL_SIZE(int, len_str2));
    }

    // initial result[0][j] and result[i][0]
    int const max_len = MAX2(ARRAY_LOGIC_SIZE(len_str1), ARRAY_LOGIC_SIZE(len_str2));
    for (int c = 0; c < max_len; ++c)
    {
        if (c < ARRAY_LOGIC_SIZE(len_str1))
        {
            result[c][0] = c;
        }
        if (c < ARRAY_LOGIC_SIZE(len_str2))
        {
            result[0][c] = c;
        }
    }

    for (int i = 1; i <= len_str1; ++i)
    {
        for (int j = 1; j <= len_str2; ++j)
        {
            int cost = 0;
            if (str1[i-1] != str2[j-1])
            {
                cost = 1;
            }
            printf("%d:%c, %d:%c\n", i-1, str1[i-1], j-1, str2[j-1]);
            printf("cost:%d\n", cost);
            printf("result[%d][%d]:%d\n", i-1, j, result[i-1][j]);
            printf("result[%d][%d]:%d\n", i, j-1, result[i][j-1]);
            printf("result[%d][%d]:%d\n", i-1, j-1, result[i-1][j-1]);
            result[i][j] = min3(result[i-1][j], result[i][j-1], result[i-1][j-1]) + cost;
            printf("result[%d][%d]:%d\n", i, j, result[i][j]);
        }
    }
    print_2d(result, ARRAY_LOGIC_SIZE(len_str1), ARRAY_LOGIC_SIZE(len_str2));
    return result[len_str1][len_str2];
}
