#include <iostream>

int32_t run(uint64_t n)
{
    int32_t factor = 2;
    int32_t lastFactor = 1;

    while (n > 1) {
        if (n % factor == 0) {
            lastFactor = factor;
            n /= factor;
            while (n % factor == 0) {
                n /= factor;
            }
        }
        ++factor;
    }

    return lastFactor;
}

int main()
{
    std::cout << "Largest prime factor: " << run(600851475143) << '\n';
}
