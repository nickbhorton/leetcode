// DP for beginers 1
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
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
        int current_min_cost,
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
                std::cout << "picked 30 day pass\n";
                days_active = 30;
                break;
            case 1:
                std::cout << "picked 7 day pass\n";
                days_active = 7;
                break;
            case 2:
                std::cout << "picked 1 day pass\n";
                days_active = 1;
                break;
            }
            while (current_days_index < days.size() &&
                   days[current_days_index] < day_pass_bought + days_active) {
                current_days_index++;
            }
            if (current_cost + costs[i] < min_cost &&
                current_cost + costs[i] < current_min_cost) {
                int new_cost = helper(
                    days,
                    current_days_index,
                    costs,
                    current_cost + costs[i],
                    min_cost < current_min_cost ? min_cost : current_min_cost,
                    depth + 1
                );
                if (new_cost < min_cost) {
                    min_cost = new_cost;
                }
            }
        }
        return min_cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int cost_min{INT_MAX};
        // [days_index, current_cost]
        std::queue<std::tuple<size_t, int>> s{};
        s.push({0, 0});
        while (!s.empty()) {
            auto const [days_index, prev_cost] = s.front();
            s.pop();

            if (days_index == days.size()) {
                if (prev_cost < cost_min) {
                    cost_min = prev_cost;
                }
            } else {
                for (size_t cost_index = 0; cost_index < costs.size();
                     cost_index++) {
                    int new_cost = prev_cost + costs[cost_index];
                    int additional_days =
                        cost_index == 0 ? 1 : (cost_index == 1 ? 7 : 30);
                    if (new_cost < cost_min) {
                        size_t current_days_index = days_index;
                        int day_pass_bought = days[current_days_index];
                        while (current_days_index < days.size() &&
                               days[current_days_index] <
                                   day_pass_bought + additional_days) {
                            current_days_index++;
                        }
                        s.push({current_days_index, new_cost});
                    }
                }
            }
        }
        return cost_min;
    }
};
int main()
{
    Solution s{};
    std::vector<int> costs1{2, 7, 15};
    std::vector<int> days1{1, 4, 6, 7, 8, 20};
    std::vector<int> days2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> days3{1, 5, 7, 10};
    std::cout << (11 == s.mincostTickets(days1, costs1)) << "\n";
    std::cout << (17 == s.mincostTickets(days2, costs1)) << "\n";
    std::cout << s.mincostTickets(days3, costs1) << "\n";
}
