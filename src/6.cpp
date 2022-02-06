#include <cstdint>
#include <iostream>

int32_t run(int32_t n)
{
    int32_t sum = 0;
    int32_t sum_of_squares = 0;

    for (int32_t i = 1; i != n + 1; ++i) {
        sum_of_squares += i * i;
        sum += i;
    }

    return (sum * sum) - sum_of_squares;
}

int main()
{
    std::cout << "Sum square difference: " << run(100) << '\n';
}
