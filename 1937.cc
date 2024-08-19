#include <iostream>
#include <vector>
using std::vector;

void printv(std::vector<int> const& v)
{
    for (auto const& num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

/*
m x n matrix
You start with 0 points and want to maximize the number of points you get
picking (r, c) from a row will add points[r][c] must pick one cell from each row
for each adjacent row (r, c1), (r + 1, c2) -> score -= std::abs(c2 - c1)

This is dynamic programming.
So first thing first we need to figure out what the sub problems that are being
repeated are.

Each row decicion after the first one makes 2 changes
1: where you start for the next choice
2: what your new score is

1 2
1 5

 r c
(0 0) 1
(1 0) 1
= 1 + 1 - 0 = 2

(0 0) 1
(1 1) 5
= 1 + 5 - 1 = 5


(0 1) 2
(1 0) 1
= 2 + 1 - 1 = 2

(0 1) 2
(1 1) 5
= 2 + 5 - 0 = 7

1 2 3
1 5 1
3 1 1

r1
c0 = (0 0) 1 | (1 0) 1 -> 1 + 1 - 0 = 2
c0 = (0 1) 2 | (1 0) 1 -> 2 + 1 - 1 = 2
c0 = (0 2) 3 | (1 0) 1 -> 3 + 1 - 2 = 2
   = 2

c1 = (0 0) 1 | (1 1) 5 -> 1 + 5 - 1 = 5
c1 = (0 1) 2 | (1 1) 5 -> 2 + 5 - 0 = 7
c1 = (0 2) 3 | (1 1) 5 -> 3 + 5 - 1 = 7
   = 7

*/
class Solution
{
public:
    std::vector<int> optimals_row(
        vector<vector<int>>& points,
        int top_row_index,
        std::vector<int> const& stored
    )
    {
        int const n = points[top_row_index].size();
        std::vector<int> new_stored(stored.size(), -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int score =
                    stored[j] + points[top_row_index][i] - std::abs(i - j);
                if (score > new_stored[i]) {
                    new_stored[i] = score;
                }
            }
        }
        return new_stored;
    }
    long long maxPoints(vector<vector<int>>& points)
    {
        int score{0};
        int const m{static_cast<int>(points.size())};
        int const n{static_cast<int>(points[0].size())};
        std::vector<int> stored_row(n, 0);
        for (int i = 0; i < n; i++) {
            stored_row[i] = points[m - 1][i];
        }
        // printv(stored_row);
        for (int i = 2; i <= m; i++) {
            stored_row = optimals_row(points, m - i, stored_row);
            // printv(stored_row);
        }
        int rmax = stored_row[0];
        for (auto const num : stored_row) {
            if (num > rmax) {
                rmax = num;
            }
        }
        return rmax;
    }
};
int main()
{
    Solution s{};
    std::vector<std::vector<int>> points1{{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}}};
    std::cout << s.maxPoints(points1) << "\n";
}
