#include <iostream>
#include <gtest/gtest.h>
#include <isbn-13.h>

static uint8_t golden_isbn13(const uint8_t *numbers)
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

    const auto golden_result = golden_isbn13(numbers);
    EXPECT_EQ(golden_result, 8);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 8);
}

TEST(ISBN13, B)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 8, 3, 1, 2, 0, 4, 3, 4 };

    const auto golden_result = golden_isbn13(numbers);
    EXPECT_EQ(golden_result, 2);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 2);
}

TEST(ISBN13, C)
{
    const uint8_t numbers[] = { 9, 7, 8, 1, 4, 3, 5, 1, 2, 2, 9, 6 };

    const auto golden_result = golden_isbn13(numbers);
    EXPECT_EQ(golden_result, 3);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 3);
}

TEST(ISBN13, D)
{
    const uint8_t n1[] = { 9, 7, 8, 1, 4, 3, 5, 1, 2, 2, 9, 6 };
    const uint8_t n2[] = { 9, 7, 8, 3, 8, 3, 1, 2, 0, 4, 3, 4 };
    const uint8_t n3[] = { 9, 7, 8, 3, 7, 6, 5, 7, 2, 7, 8, 1 };

    const auto gr1 = golden_isbn13(n1);
    const auto gr2 = golden_isbn13(n2);
    const auto gr3 = golden_isbn13(n3);

    const auto r1 = isbn13(n1);
    const auto r2 = isbn13(n2);
    const auto r3 = isbn13(n3);

    EXPECT_EQ(gr1, 3);
    EXPECT_EQ(gr2, 2);
    EXPECT_EQ(gr3, 8);

    EXPECT_EQ(r1, 3);
    EXPECT_EQ(r2, 2);
    EXPECT_EQ(r3, 8);
}

TEST(ISBN13, E)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 6, 4, 2, 3, 7, 7, 1, 3 };

    const auto golden_result = golden_isbn13(numbers);
    EXPECT_EQ(golden_result, 6);

    const auto result = isbn13(numbers);
    EXPECT_EQ(result, 6);
}
