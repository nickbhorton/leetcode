#include <iostream>
#include <vector>

using std::vector;

/*
 * m x n grid. 1 is land 0 is water.
 * Island: an island is a maximally 4 directinal connected group of ones.
 * We do not want one island in the grid. If there is only one island it is
 * "connected".
 * In one day you can transform a land cell into a water cell.
 * Return the MINUMUM amount of days to disconnect the grid.
 *
 * Really what matters here is how many island we have. If we have two we win.
 * Therefor the answer should almost never be more than 4.
 * 111111111
 * 111111111
 * 111111111
 * 111111111
 *
 * 101111111
 * 011111111
 * 111111111
 * 111111111
 *
 * but makeing sure that this is the minimum is hard.
 *
 * 111
 *
 * 101
 *
 * 010
 * 111
 * 010
 *
 * 010
 * 101
 * 010
 *
 * 11 12
 * 01 01
 */
class Solution
{
public:
    void count_connected_tiles_helper(
        std::vector<std::vector<int>>& grid,
        std::vector<std::pair<int, int>>& visited,
        int value_to_count,
        int row,
        int col
    )
    {
        if (grid[row][col] == value_to_count) {
            std::pair<int, int> new_pair{row, col};
            for (auto const& pair : visited) {
                if (new_pair == pair) {
                    return;
                }
            }
            visited.push_back({row, col});
            if (row != grid.size() - 1) {
                count_connected_tiles_helper(
                    grid,
                    visited,
                    value_to_count,
                    row + 1,
                    col
                );
            }
            if (row != 0) {
                count_connected_tiles_helper(
                    grid,
                    visited,
                    value_to_count,
                    row - 1,
                    col
                );
            }
            if (col != grid[row].size() - 1) {
                count_connected_tiles_helper(
                    grid,
                    visited,
                    value_to_count,
                    row,
                    col + 1
                );
            }
            if (col != 0) {
                count_connected_tiles_helper(
                    grid,
                    visited,
                    value_to_count,
                    row,
                    col - 1
                );
            }
        }
    }

    int
    count_connected_tiles(std::vector<std::vector<int>>& grid, int row, int col)
    {
        std::vector<std::pair<int, int>> visited{};
        int value_visited{grid[row][col]};
        count_connected_tiles_helper(grid, visited, value_visited, row, col);
        return visited.size();
    }

    bool is_connected(vector<vector<int>>& grid)
    {
        int number_ones{};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    number_ones++;
                }
            }
        }
        std::pair<int, int> first_one{-1, -1};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && std::get<0>(first_one) == -1) {
                    first_one = {i, j};
                }
            }
        }
        if (std::get<0>(first_one) == -1) {
            return false;
        }

        int first_one_count = count_connected_tiles(
            grid,
            std::get<0>(first_one),
            std::get<1>(first_one)
        );
        // if there is more than one island then return 0
        if (first_one_count == number_ones) {
            return true;
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid)
    {
        if (!is_connected(grid)) {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    bool connected = is_connected(grid);
                    if (!connected) {
                        return 1;
                    }
                    grid[i][j] = 1;
                } else {
                }
            }
        }
        return 2;
    }
};

int main()
{
    Solution s{};
    std::vector<std::vector<int>> grid = {
        {{1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 0, 1, 1}}
    };
    std::cout << s.minDays(grid) << "\n";
}
