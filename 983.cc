// DP for beginers 1
#include <climits>
#include <iostream>
#include <vector>

using std::vector;

/*
One day passes are in costs[0]
7 day passes are in costs[1]
30 day passes are in costs[2]
Days is in increasing order
Mimimize costs for trips

Recursive aproach / brute force
Im thinking at each day we attempt to buy each pass type and then realize the
concequces of the pass type.
*/

class Solution
{
public:
    int helper(
        std::vector<int> const& days,
        size_t days_index,
        std::vector<int> const& costs,
        int current_cost,
        int depth
    )
    {
        if (days_index == days.size()) {
            for (int p = 0; p < depth; p++) {
                std::cout << "    ";
            }
            std::cout << "result: " << current_cost << "\n";
            return current_cost;
        }
        int min_cost{INT_MAX};
        for (size_t i = 0; i < costs.size(); i++) {
            size_t current_days_index{days_index};
            int day_pass_bought = days[current_days_index];
            int days_active{};
            for (int p = 0; p < depth; p++) {
                std::cout << "    ";
            }
            switch (i) {
            case 0:
                std::cout << "picked 1 day pass\n";
                days_active = 1;
                break;
            case 1:
                std::cout << "picked 7 day pass\n";
                days_active = 7;
                break;
            case 2:
                std::cout << "picked 30 day pass\n";
                days_active = 30;
                break;
            }
            while (days[current_days_index] < day_pass_bought + days_active &&
                   current_days_index < days.size()) {
                current_days_index++;
            }
            int new_cost = helper(
                days,
                current_days_index,
                costs,
                current_cost + costs[i],
                depth + 1
            );
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
        return min_cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        return helper(days, 0, costs, 0, 0);
    }
};
int main()
{
    Solution s{};
    std::vector<int> days1{1, 4, 6, 7, 8, 20};
    std::vector<int> costs1{2, 7, 15};
    std::cout << (11 == s.mincostTickets(days1, costs1)) << "\n";
    std::vector<int> days2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::cout << (17 == s.mincostTickets(days2, costs1)) << "\n";
}
