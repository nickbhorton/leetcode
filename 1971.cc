#include <iostream>
#include <vector>
using std::vector;
class Solution
{
public:
    bool in(std::vector<int> const v, int c)
    {
        for (auto const& num : v) {
            if (num == c) {
                return true;
            }
        }
        return false;
    }

    void visit(
        std::vector<int>& visited,
        std::vector<std::vector<int>>& edges,
        int at
    )
    {
        visited.push_back(at);
        for (auto const& edge : edges) {
            auto const& v1 = edge[0];
            auto const& v2 = edge[1];
            if (v1 == at && !in(visited, v2)) {
                visit(visited, edges, v2);
            }
            if (v2 == at && !in(visited, v1)) {
                visit(visited, edges, v1);
            }
        }
    }
    bool
    validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        std::vector<int> visited{};
        visit(visited, edges, source);
        bool result{false};
        for (auto const& v : visited) {
            std::cout << v << " ";
            if (v == destination) {
                result = true;
            }
        }
        std::cout << "\n";
        return result;
    }
};

int main()
{
    Solution s{};
    std::vector<std::vector<int>> edges{{{0, 1}, {1, 2}, {2, 0}}};
    std::cout << s.validPath(3, edges, 0, 2) << "\n";
}
