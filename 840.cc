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
    std::vector<std::vector<int>> grid = {
        {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}}
    };
    std::cout << s.numMagicSquaresInside(grid) << "\n";
}
