#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

inline int32_t const val_to_idx(int32_t val) { return val - 1; }
inline int32_t const idx_to_val(int32_t idx) { return idx + 1; }

int64_t const run(int32_t const n)
{
    std::vector<bool> primes(n);
    primes[val_to_idx(1)] = true;

    for (int32_t i = 2; i <= sqrt(n); i += 1)
        if (!primes[val_to_idx(i)])
            for (int32_t j = i * i; j <= n; j += i)
                primes[val_to_idx(j)] = true;

    int64_t sum = 0;
    for (int32_t i = 0; i != n - 1; i += 1)
        if (!primes[i])
            sum += idx_to_val(i);

    return sum;
}

int main()
{
    std::cout << "Summation of primes: " << run(2000000) << '\n';
}
