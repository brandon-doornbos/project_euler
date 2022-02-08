#include <cstdint>
#include <iostream>

int32_t const run(int32_t n)
{
    for (int32_t i = n;; i += n) {
        for (int32_t j = n - 1; j != 0; j -= 1) {
            if (i % j != 0) {
                break;
            } else if (j == 3) {
                return i;
            }
        }
    }
}

int main()
{
    std::cout << "Smallest multiple: " << run(20) << '\n';
}
