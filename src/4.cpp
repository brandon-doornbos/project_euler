#include <cmath>
#include <iostream>
#include <string>

int32_t run(int32_t n1, int32_t n2)
{
    int32_t largest = 0;

    for (int32_t i = std::pow(10, n1) - 1; i != 0; --i) {
        for (int32_t j = std::pow(10, n2) - 1; j != 0; --j) {
            std::string result = std::to_string(i * j);
            std::string result_rev = std::string(result.rbegin(), result.rend());

            if (result == result_rev) {
                int32_t result_int = atoll(result.c_str());
                if (result_int > largest)
                    largest = result_int;
            }
        }
    }

    return largest;
}

int main()
{
    std::cout << "Largest palindrome product: " << run(3, 3) << '\n';
}
