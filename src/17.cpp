#include <array>
#include <cstdint>
#include <iostream>
#include <string>

const std::array<std::string, 10> Units {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

const std::array<std::string, 10> Tens {
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

const std::array<std::string, 10> Teens {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

inline int8_t const char_to_int(char const c) { return c - '0'; }

uint32_t const run(uint32_t const number)
{
    uint64_t sum = 0;

    for (uint32_t i = 1; i <= number; i += 1) {
        if (i == 1000) {
            sum += 11;
            continue;
        }

        std::string num = std::to_string(i);

        if (num.size() == 3) {
            sum += Units[char_to_int(num[0])].size();
            sum += std::string("hundred").size();

            if (num[1] != '0' || num[2] != '0')
                sum += std::string("and").size();
        }

        if (num.size() > 1) {
            if (num[num.size() - 2] == '1') {
                sum += Teens[char_to_int(num[num.size() - 1])].size();
                continue;
            }

            sum += Tens[char_to_int(num[num.size() - 2])].size();
        }

        sum += Units[char_to_int(num[num.size() - 1])].size();
    }

    return sum;
}

int main()
{
    // https://projecteuler.net/problem=17
    // If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
    std::cout << "Number letter counts: " << run(1000) << '\n';
}
