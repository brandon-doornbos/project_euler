#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

inline int32_t const val_to_idx(int32_t val) { return val - 1; }
inline int32_t const idx_to_val(int32_t idx) { return idx + 1; }

std::vector<int32_t> const get_primes(int32_t const max)
{
    std::vector<bool> primes(max);
    primes[val_to_idx(1)] = true;

    for (int32_t i = 2; i <= sqrt(max); i += 1)
        if (!primes[val_to_idx(i)])
            for (int32_t j = i * i; j <= max; j += i)
                primes[val_to_idx(j)] = true;

    std::vector<int32_t> prime_values;
    for (int32_t i = 0; i != max - 1; i += 1)
        if (!primes[i])
            prime_values.push_back(idx_to_val(i));

    return prime_values;
}

int32_t const run(int32_t n)
{
    int32_t prime_max = 100000;
    auto primes = get_primes(prime_max);

    for (auto i = 2;; i += 1) {
        auto tri = 0;
        for (auto j = 1; j <= i; j += 1)
            tri += j;

        // prime factorization (https://www.mathsisfun.com/prime-factorization.html)
        std::unordered_map<int32_t, int32_t> factors;
        auto num = tri;
        bool done = false;
        while (!done) {
            // bool next = false;
            for (auto prime : primes) {
                if (num == prime) {
                    factors[prime] += 1;
                    done = true;
                    break;
                } else if (num % prime == 0) {
                    factors[prime] += 1;
                    num /= prime;
                    // next = true;
                    break;
                }
            }
            // FIXME: Figure out why this gets increased way to often and how to only do it when necessary
            // if there were not enough primes, get more and retry
            // if (!next) {
            //     prime_max *= 2;
            //     primes = get_primes(prime_max);
            // }
        }

        // get the divisor count (https://www.themathdoctors.org/counting-divisors-of-a-number/)
        auto divisors = 0;
        for (auto it : factors) {
            if (!divisors) {
                divisors = it.second + 1;
            } else {
                divisors *= it.second + 1;
            }

            if (divisors > n)
                return tri;
        }
    }

    return -1;
}

int main()
{
    // https://projecteuler.net/problem=12
    std::cout << "Highly divisible triangular number: " << run(500) << '\n';
}
