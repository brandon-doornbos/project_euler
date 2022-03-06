#include <cstdint>
#include <iostream>
#include <vector>

uint64_t const run(int32_t const dim)
{
    // count vertices, not edges
    int32_t const max = dim + 1;
    std::vector<std::vector<uint64_t>> grid(max, std::vector<uint64_t>(max));

    // filling far-right and far-bottom sides with a 1, meaning only 1 possible path from here
    for (auto i = 0; i < max; i += 1) {
        grid[i][max - 1] = 1;
        grid[max - 1][i] = 1;
    }

    // propagate back to top-left by adding the amount of possible paths to the right and bottom
    for (auto i = max - 2; i >= 0; i -= 1)
        for (auto j = max - 2; j >= 0; j -= 1)
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];

    return grid[0][0];
}

int main()
{
    // https://projecteuler.net/problem=15
    // Starting in the top left corner, and only being able to move to the right and down,
    // how many routes are there to the bottom right corner through a 20×20 grid?
    std::cout << "Lattice paths: " << run(20) << '\n';
}
