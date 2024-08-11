#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    bool isMagicSquare(
        std::vector<std::vector<int>> const& grid,
        size_t row,
        size_t col
    )
    {
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                for (size_t a = 0; a < 3; a++) {
                    for (size_t b = 0; b < 3; b++) {
                        if (i != a && j != b &&
                            grid[row + i][col + j] == grid[row + a][col + b]) {
                            return false;
                        }
                    }
                }
                switch (grid[i][j]) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    break;
                default:
                    return false;
                }
            }
        }

        int checked_sum{-1};
        for (size_t i = 0; i < 3; i++) {
            int rsum{};
            int csum{};
            for (size_t j = 0; j < 3; j++) {
                // std::cout << row + i << " " << col + j << "\n";
                rsum += grid[row + i][col + j];
                // std::cout << row + j << " " << col + i << "\n";
                csum += grid[row + j][col + i];
            }
            if (checked_sum == -1) {
                checked_sum = rsum;
            }

            if (checked_sum != rsum) {
                return false;
            }
            if (checked_sum != csum) {
                return false;
            }
        }
        int d_sum{};
        for (size_t i = 0; i < 3; i++) {
            d_sum += grid[row + i][col + i];
        }
        if (d_sum != checked_sum) {
            return false;
        }
        int dd_sum{};
        for (size_t i = 0; i < 3; i++) {
            dd_sum += grid[row + i][col + (2 - i)];
        }
        if (dd_sum != checked_sum) {
            return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int magic_squares{};
        for (size_t i = 0; i < grid.size() - 2; i++) {
            for (size_t j = 0; j < grid[0].size() - 2; j++) {
                std::cout << i << " " << j;
                if (isMagicSquare(grid, i, j)) {
                    std::cout << " yes\n";
                    magic_squares++;
                } else {
                    std::cout << " no\n";
                }
            }
        }
        return magic_squares;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid = {{{10, 3, 5}, {1, 6, 11}, {7, 9, 2}}};
    std::cout << s.numMagicSquaresInside(grid) << "\n";
}
