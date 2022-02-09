#include <cstdint>
#include <iostream>

int32_t const run(int32_t const n)
{
    for (auto i = n; i != 0; i -= 1) {
        for (auto j = n - i; j != 0; j -= 1) {
            for (auto k = n - i - j; k != 0; k -= 1) {
                if (k * k + j * j == i * i && k + j + i == n) {
                    return k * j * i;
                }
            }
        }
    }

    return 0;
}

int main()
{
    std::cout << "Special Pythagorean triplet: " << run(1000) << '\n';
}
