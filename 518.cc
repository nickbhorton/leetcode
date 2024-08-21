#include <climits>
#include <iostream>
#include <vector>
using std::vector;
/*
At every given choice we can either pick
*/
class Solution
{
public:
    int helper(int amount, vector<int> const& coins, int prev)
    {
        if (amount < 0) {
            return 0;
        } else if (amount == 0) {
            return 1;
        } else {
            int sum{};
            for (auto const& coin : coins) {
                if (coin <= prev) {
                    sum += helper(amount - coin, coins, coin);
                }
            }
            return sum;
        }
    }
    int change(int amount, vector<int>& coins)
    {
        std::vector<int> dp(amount, -1);
        return helper(amount, coins, INT_MAX);
    }
};

int main()
{
    Solution s{};
    std::vector<int> coins1{1, 2, 5};
    std::vector<int> coins2{2};
    std::vector<int> coins3{10};
    std::cout << s.change(5, coins1) << "\n";
    std::cout << s.change(3, coins2) << "\n";
    std::cout << s.change(10, coins3) << "\n";
}
