#include <cstdint>
#include <iostream>
#include <string>

struct BigInt {
public:
    std::string m_n {};

    BigInt(std::string initial = "0")
        : m_n(initial)
    {
    }

    uint8_t const operator[](size_t i)
    {
        return char_to_int(m_n[i]);
    }

    void const operator+=(BigInt const& rhs)
    {
        uint8_t carry = 0;

        for (size_t i = rhs.m_n.size(); i != 0; i -= 1) {
            carry += char_to_int(m_n[i - 1]) + char_to_int(rhs.m_n[i - 1]);

            m_n[i - 1] = int_to_char(carry % 10);
            carry /= 10;
        }

        if (carry)
            m_n = std::to_string(carry).append(m_n);
    }

private:
    inline int8_t const char_to_int(char const c) { return c - '0'; }
    inline char const int_to_char(int8_t const i) { return i + '0'; }
};

uint32_t const run(uint32_t const power)
{
    BigInt result("2");

    for (size_t i = 0; i != power - 1; i += 1)
        result += result;

    uint32_t sum = 0;
    for (size_t i = 0; i != result.m_n.size(); i += 1)
        sum += result[i];

    return sum;
}

int main()
{
    // https://projecteuler.net/problem=16
    // What is the sum of the digits of the number 2^1000?
    std::cout << "Power digit sum: " << run(1000) << '\n';
}
