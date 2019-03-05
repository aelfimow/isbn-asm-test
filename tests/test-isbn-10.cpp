#include <gtest/gtest.h>
#include <isbn-10.h>

TEST(ISBN10, A)
{
    const uint8_t numbers[] = { 3, 8, 6, 6, 8, 0, 1, 9, 2 };

    const auto result = isbn10(numbers);

    EXPECT_EQ(result, 0);
}

TEST(ISBN10, B)
{
    const uint8_t numbers[] = { 3, 6, 8, 0, 0, 8, 7, 8, 3 };

    const auto result = isbn10(numbers);

    EXPECT_EQ(result, 7);
}
