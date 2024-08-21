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
        std::vector<int> const& costs,
        int current_day,
        int cost,
        int depth,
        std::vector<int>& mem
    )
    {
        for (int i = 0; i < depth; i++) {
            std::cout << "    ";
        }
        std::cout << current_day << "\n";
        if (mem[current_day]) {
            for (int i = 0; i < depth; i++) {
                std::cout << "    ";
            }
            std::cout << "mem: day=" << current_day << " : " << mem[current_day]
                      << "\n";
            return mem[current_day];
        } else if (current_day > days[days.size() - 1]) {
            for (int i = 0; i < depth; i++) {
                std::cout << "    ";
            }
            std::cout << "trip complete: " << cost << "\n";
            return cost;
        } else {
            size_t i{0};
            while (current_day > days[i]) {
                i++;
            }
            current_day = days[i];
            int c1 = helper(
                days,
                costs,
                current_day + 1,
                cost + costs[0],
                depth + 1,
                mem
            );
            int c7 = helper(
                days,
                costs,
                current_day + 7,
                cost + costs[1],
                depth + 1,
                mem
            );
            int c30 = helper(
                days,
                costs,
                current_day + 30,
                cost + costs[2],
                depth + 1,
                mem
            );
            int result = std::min(c1, std::min(c7, c30));
            mem[current_day] = result;
            for (int i = 0; i < depth; i++) {
                std::cout << "    ";
            }
            std::cout << "min of " << c1 << " " << c7 << " " << c30 << " is "
                      << result << "\n";
            return result;
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        std::vector<int> mem(357, 0);
        return helper(days, costs, 0, 0, 0, mem);
    }
};
int main()
{
    Solution s{};
    std::vector<int> costs1{2, 7, 15};
    std::vector<int> costs2{3, 13, 45};
    std::vector<int> days1{1, 4, 6, 7, 8, 20};
    std::vector<int> days2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> days3{1, 5, 7, 10};
    std::vector<int> days4{
        1,
        4,
        6,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        20,
        21,
        22,
        23,
        27,
        28
    };
    // std::cout << (11 == s.mincostTickets(days1, costs1)) << "\n";
    // std::cout << (17 == s.mincostTickets(days2, costs1)) << "\n";
    // std::cout << (8 == s.mincostTickets(days3, costs1)) << "\n";
    std::cout << s.mincostTickets(days4, costs2) << "\n";
}
