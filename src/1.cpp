#include <iostream>

int32_t run(int32_t n)
{
    int32_t sum = 0;

    for (int32_t i = 3; i < n; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    std::cout << "Multiples of 3 or 5: " << run(1000) << '\n';
}
