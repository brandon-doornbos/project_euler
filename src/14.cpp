#include <cstdint>
#include <iostream>
#include <unordered_map>

struct Number {
    int32_t value;
    int32_t term_amt;
};

int32_t const run(int32_t max)
{
    std::unordered_map<int32_t, int32_t> terms {};
    terms[1] = 1;
    Number best {};

    for (auto i = 1; i < max; i += 1) {
        uint64_t number = i;
        int32_t term_amt = 0;

        while (true) {
            if (terms.contains(number)) {
                term_amt += terms[number];
                terms[i] = term_amt;
                if (term_amt > best.term_amt) {
                    best = {
                        i,
                        term_amt
                    };
                }
                break;
            } else {
                if (number % 2 == 0) {
                    number /= 2;
                } else {
                    number = number * 3 + 1;
                }

                term_amt += 1;
            }
        }
    }

    return best.value;
}

int main()
{
    // https://projecteuler.net/problem=14
    // Which starting number, under one million, produces the longest chain?
    std::cout << "Longest Collatz sequence: " << run(1000000) << '\n';
}
