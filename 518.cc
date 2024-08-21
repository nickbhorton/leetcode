#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <unordered_map>
#include <vector>
using std::vector;
/*
At every given choice we can either pick
*/
class Solution
{
public:
    // for the key top 16 bits are amount bottom 16 are index
    uint32_t to_key(size_t index, int amount)
    {
        return (amount << 16) | (index);
    }
    int helper(
        int amount,
        vector<int> const& coins,
        size_t coins_index,
        int depth,
        std::unordered_map<uint32_t, int>& dp
    )
    {
        for (int i = 0; i < depth; i++) {
            std::cout << "    ";
        }
        std::cout << amount << " {";
        std::stringstream ss{};
        for (size_t i = coins_index; i < coins.size(); i++) {
            ss << coins[i] << ",";
        }
        std::cout << ss.str().substr(0, ss.str().size() - 1);
        std::cout << "}\n";
        if (amount < 0) {
            return 0;
        } else if (amount == 0) {
            return 1;
        } else {
            int sum{};
            for (size_t i = coins_index; i < coins.size(); i++) {
                uint32_t key = to_key(i, amount - coins[i]);
                if (dp.contains(key)) {
                    sum += dp[key];
                } else {
                    int new_sub_answer =
                        helper(amount - coins[i], coins, i, depth + 1, dp);
                    dp[key] = new_sub_answer;
                    sum += new_sub_answer;
                }
            }
            return sum;
        }
    }
    int change(int amount, vector<int>& coins)
    {
        std::vector<int> coins_cpy = coins;
        std::reverse(coins_cpy.begin(), coins_cpy.end());
        std::unordered_map<uint32_t, int> dp{};
        return helper(amount, coins_cpy, 0, 0, dp);
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
