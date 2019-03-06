#include <gtest/gtest.h>
#include <isbn-13.h>

TEST(ISBN13, A)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 7, 6, 5, 7, 2, 7, 8, 1 };

    const auto result = isbn13(numbers);

    EXPECT_EQ(result, 2);
}

TEST(ISBN13, B)
{
    const uint8_t numbers[] = { 9, 7, 8, 3, 8, 3, 1, 2, 0, 4, 3, 4 };

    const auto result = isbn13(numbers);

    EXPECT_EQ(result, 2);
}
