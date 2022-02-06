#include <iostream>

int32_t run(int32_t n)
{
    for (int32_t i = n;; ++i) {
        for (int32_t j = n; j != 0; --j) {
            if (i % j != 0) {
                break;
            } else if (j == 1) {
                return i;
            }
        }
    }
}

int main()
{
    std::cout << "Smallest multiple: " << run(20) << '\n';
}
