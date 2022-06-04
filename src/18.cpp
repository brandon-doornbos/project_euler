#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

uint32_t const run(std::string const input)
{
    std::vector<std::vector<uint8_t>> rows {};

    std::vector<uint8_t> col {};
    for (size_t i = 0, row = 0; i <= input.size(); i += 2, row -= 1) {
        uint32_t num = std::atoi(input.substr(i, 2).c_str());
        col.push_back(num);

        if (row == 0) {
            row = col.size() + 1;
            rows.push_back(col);
            col = std::vector<uint8_t> {};
        }
    }

    uint32_t best = 0;

    for (size_t i = 0; i != (size_t)std::pow(2, rows.size()); i += 1) {
        size_t j = i;
        size_t col = 0, row = 1;
        uint32_t sum = rows[0][0];

        while (row != rows.size()) {
            if ((j & 1) == 1)
                col += 1;
            sum += rows[row][col];
            row += 1;
            j >>= 1;
        }

        if (sum > best)
            best = sum;
    }

    return best;
}

int main()
{
    // https://projecteuler.net/problem=18
    // By starting at the top of the triangle below and moving to adjacent numbers on the row below, find the maximum total:
    std::cout << "Maximum path sum I: " << run(std::string("759564174782183587102004824765190123750334880277730763679965042806167092414126568340807033414872334732371694295371446525439152975114701133287773177839681757917152381714914358502729486366046889536730731669874031046298272309709873933853600423"))
              << '\n';
}
