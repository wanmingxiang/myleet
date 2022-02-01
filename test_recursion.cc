#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <iostream>
#include <vector>

using namespace testing;
using namespace std;

// 1 1 2 3 5 8 13
// f(n) = f(n-1) + f(n-2)
// f(1) = 1
// f(2) = 1

uint32_t fibonacci(uint32_t n)
{
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

TEST(recursion, fibonacci)
{
    ASSERT_EQ(fibonacci(3), (uint32_t)2);
    ASSERT_EQ(fibonacci(4), (uint32_t)3);
    ASSERT_EQ(fibonacci(5), (uint32_t)5);
    ASSERT_EQ(fibonacci(6), (uint32_t)8);
}

// f(n) = 1 + 2 + 3 + 4 + ... + n
// f(n) = f(n - 1) + n
// f(1) = 1
//
int calc_sum(int n)
{
    if (n == 1) {
        return 1;
    }
    return calc_sum(n - 1) + n;
}

TEST(recursion, sum)
{
    ASSERT_EQ(calc_sum(100), 5050);
}

// 前N项到和
// 1 3 4 9 3 2 1 10
// f(arr, n) = f(arr, n-1) + n
// f(arr, 0) = arr[0]
int sum_n(int arr[], int n)
{
    if (n == 0) {
        return arr[0];
    }
    return sum_n(arr,n - 1) + arr[n];
}

TEST(recursion, sum_n)
{
    int arr[] = {1,2,3,4,5,6,7,8};
    ASSERT_EQ(sum_n(arr, 6), 28);
}

int max_n(int arr[], int n)
{
    if (n == 0) {
        return arr[0];
    }
    return max_n(arr, n-1) > arr[n] ? max_n(arr, n-1) : arr[n];
}

TEST(recursion, max_n) 
{
    int arr[] = {32,3,4,2,3,9,2,9};
    ASSERT_EQ(max_n(arr, 7), 32);

}
