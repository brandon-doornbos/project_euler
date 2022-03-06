#include <cstdint>
#include <iostream>
#include <vector>

int32_t const run(int32_t max)
{
    std::vector<int32_t> terms(max);
    terms[1] = 1;
    int32_t best_number = -1;
    int32_t best_term_amt = 0;

    for (auto i = 2; i < max; i += 1) {
        uint64_t number = i;

        for (int32_t term_amt = 0;; term_amt += 1) {
            if (number < (uint64_t)max && terms[number]) {
                term_amt += terms[number];
                terms[i] = term_amt;
                if (term_amt > best_term_amt) {
                    best_number = i;
                    best_term_amt = term_amt;
                }
                break;
            } else {
                if (number % 2 == 0) {
                    number /= 2;
                } else {
                    number = number * 3 + 1;
                }
            }
        }
    }

    return best_number;
}

int main()
{
    // https://projecteuler.net/problem=14
    // Which starting number, under one million, produces the longest chain?
    std::cout << "Longest Collatz sequence: " << run(1000000) << '\n';
}
