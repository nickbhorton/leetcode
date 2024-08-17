#include <iostream>
#include <vector>
using std::vector;

/*
Each array is sorted in assending order.

You can pick to integers from two seperate arrays.
*/
class Solution
{
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int const m{static_cast<int>(arrays.size())};
        int dist1;
        {
            int minimum{10001};
            size_t min_i{};
            for (size_t i = 0; i < m; i++) {
                if (arrays[i][0] < minimum) {
                    minimum = arrays[i][0];
                    min_i = i;
                }
            }
            int maximum{-10001};
            for (size_t i = 0; i < m; i++) {
                if (arrays[i][arrays[i].size() - 1] > maximum && i != min_i) {
                    maximum = arrays[i][arrays[i].size() - 1];
                }
            }
            dist1 = std::abs(maximum - minimum);
        }
        int dist2;
        {
            int maximum{-10001};
            size_t max_i{};
            for (size_t i = 0; i < m; i++) {
                if (arrays[i][arrays[i].size() - 1] > maximum) {
                    maximum = arrays[i][arrays[i].size() - 1];
                    max_i = i;
                }
            }
            int minimum{10001};
            for (size_t i = 0; i < m; i++) {
                if (arrays[i][0] < minimum && max_i != i) {
                    minimum = arrays[i][0];
                }
            }
            dist2 = std::abs(maximum - minimum);
        }
        // std::cout << dist1 << " " << dist2 << "\n";
        return dist1 > dist2 ? dist1 : dist2;
    }
};

int main()
{
    Solution s{};
    std::vector<std::vector<int>> arrays1{{{1, 2, 3}, {4, 5}, {1, 2, 3}}};
    std::cout << s.maxDistance(arrays1) << "\n";
    std::vector<std::vector<int>> arrays2{};
    arrays2.push_back({1});
    arrays2.push_back({1});
    std::cout << s.maxDistance(arrays2) << "\n";
    std::vector<std::vector<int>> arrays3{{1, 10}, {3, 4}};
    std::cout << s.maxDistance(arrays3) << "\n";
    std::vector<std::vector<int>> arrays4{{-2}, {-3, -2, 1}};
    std::cout << s.maxDistance(arrays4) << "\n";
}
