#include <gtest/gtest.h>
#include <isbn-10.h>

static uint8_t golden_isbn10(const uint8_t *numbers)
{
    size_t sum = 0;

    auto mult = [](size_t index, uint8_t value) { return (index * static_cast<size_t>(value)); };

    sum += mult(1, numbers[0]);
    sum += mult(2, numbers[1]);
    sum += mult(3, numbers[2]);
    sum += mult(4, numbers[3]);
    sum += mult(5, numbers[4]);
    sum += mult(6, numbers[5]);
    sum += mult(7, numbers[6]);
    sum += mult(8, numbers[7]);
    sum += mult(9, numbers[8]);

    size_t rest = sum % 11;

    return static_cast<uint8_t>(rest);
}

TEST(ISBN10, A)
{
    const uint8_t numbers[] = { 3, 8, 6, 6, 8, 0, 1, 9, 2 };

    const auto golden_result = golden_isbn10(numbers);
    EXPECT_EQ(golden_result, 0);

    const auto result = isbn10(numbers);
    EXPECT_EQ(result, 0);
}

TEST(ISBN10, B)
{
    const uint8_t numbers[] = { 3, 6, 8, 0, 0, 8, 7, 8, 3 };

    const auto golden_result = golden_isbn10(numbers);
    EXPECT_EQ(golden_result, 7);

    const auto result = isbn10(numbers);
    EXPECT_EQ(result, 7);
}
