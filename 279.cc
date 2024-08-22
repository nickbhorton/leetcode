#include <climits>
#include <cmath>
#include <iostream>
class Solution
{
public:
    int helper(int leftover, int count)
    {
        if (leftover == 0) {
            return count;
        } else {
            int max_sqrt = std::floor(std::sqrt(leftover));
            int min_count{INT_MAX};
            for (int i = max_sqrt; i != 0; i--) {
                int new_count = helper(leftover - (i * i), count + 1);
                if (new_count < min_count) {
                    min_count = new_count;
                }
            }
            return min_count;
        }
    }
    int numSquares(int n) { return helper(n, 0); }
};

int main()
{
    Solution s{};
    for (int i = 1; i < 14; i++) {
        std::cout << i << " " << s.numSquares(i) << "\n";
    }
}
