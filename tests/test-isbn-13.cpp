#include <iostream>
#include <gtest/gtest.h>
#include <isbn-13.h>

static uint8_t golden_isb13(const uint8_t *numbers)
{
    size_t sum1 = 0;

    sum1 += numbers[0];
    sum1 += numbers[2];
    sum1 += numbers[4];
    sum1 += numbers[6];
    sum1 += numbers[8];
    sum1 += numbers[10];

    size_t sum2 = 0;

    sum2 += numbers[1];
    sum2 += numbers[3];
    sum2 += numbers[5];
    sum2 += numbers[7];
    sum2 += numbers[9];
    sum2 += numbers[11];

    size_t sum = sum1 + (3 * sum2);

    size_t r = sum % 10;

    size_t result = (10 - r) % 10;

    return static_cast<uint8_t>(result);
}

TEST(ISBN13, A)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 7, 6, 5, 7, 2, 7, 8, 1 };

    const auto golden_result = golden_isb13(numbers);
    EXPECT_EQ(golden_result, 8);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 8);
}

TEST(ISBN13, B)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 8, 3, 1, 2, 0, 4, 3, 4 };

    const auto golden_result = golden_isb13(numbers);
    EXPECT_EQ(golden_result, 2);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 2);
}
