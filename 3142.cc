#include <vector>
using std::vector;

class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>>& grid)
    {
        for (size_t i = 1; i < grid[0].size(); i++) {
            if (grid[0][i] == grid[0][i - 1]) {
                return false;
            }
        }
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 1; j < grid[i].size(); j++) {
                if (grid[j][i] == grid[j - 1][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
