#include <iostream>

int32_t run(int32_t n)
{
    int32_t sum = 0;
    int32_t i = 1;
    int32_t j = 2;

    while (i < n) {
        if (i % 2 == 0) {
            sum += i;
        }

        int32_t temp = j;
        j += i;
        i = temp;
    }

    return sum;
}

int main()
{
    std::cout << "Even Fibonacci numbers: " << run(4000000) << '\n';
}
