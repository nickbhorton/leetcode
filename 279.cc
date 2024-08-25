#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
/*
This dp problem fails at 48
The right answer is 16 + 16 + 16
*/

void printdp(std::vector<int> const& dp)
{
    for (size_t i = 0; i < dp.size(); i++) {
        std::cout << i << ": " << dp[i] << " ";
    }
    std::cout << "\n";
}

class Solution
{
public:
    int helper2(int target, std::vector<int>& dp)
    {
        if (target == 1) {
            return 1;
        } else if (target == 0) {
            return 0;
        } else if (dp[target] != -1) {
            return dp[target];
        } else {
            int max_sqrt = std::floor(std::sqrt(target));
            int min_count{10001};
            for (int i = max_sqrt; i != 0; i--) {
                int new_count = 1 + helper2(target - (i * i), dp);
                if (new_count < min_count) {
                    min_count = new_count;
                }
            }
            dp[target] = min_count;
            return min_count;
        }
    }
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, -1);
        return helper2(n, dp);
    }
};

int main()
{
    Solution s{};
    std::cout << s.numSquares(48) << "\n";
}
