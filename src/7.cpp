#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

inline int32_t const val_to_idx(int32_t val) { return val - 1; }
inline int32_t const idx_to_val(int32_t idx) { return idx + 1; }

int32_t const run(int32_t const n)
{
    // start with primes to 100 and keep increasing until you reach the appropriate amount of primes
    int32_t max = 100;
    int32_t multiplier = 2;

    // the first index (0) of the vector is value 1, i.e. the first prime (2) is at index 1
    std::vector<bool> numbers;

    while (true) {
        numbers = std::vector<bool>(max);
        numbers[0] = true;

        for (auto i = 2; i < sqrt(max); i += 1)
            if (!numbers[val_to_idx(i)])
                for (auto j = i * i; j < max; j += i) {
                    numbers[val_to_idx(j)] = true;
                }

        int32_t prime_amt = 0;
        for (auto i = 0; i != max; i += 1) {
            if (!numbers[i])
                prime_amt += 1;

            if (prime_amt == n)
                return idx_to_val(i);
        }

        max *= multiplier;
    }
}

int main()
{
    std::cout << "10001st prime: " << run(10001) << '\n';
}
