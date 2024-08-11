#include <iostream>
#include <vector>

using std::vector;

class Solution
{

    enum class Direction { Right, Down, Left, Up };

public:
    bool contains(std::vector<std::vector<int>> const& mat, int x, int y)
    {
        for (auto const& pair : mat) {
            if (pair[0] == x && pair[1] == y) {
                return true;
            }
        }
        return false;
    }
    vector<vector<int>>
    spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int to_visit{rows * cols};
        std::vector<std::vector<int>> pairs{{{rStart, cStart}}};
        Direction dir = Direction::Right;
        while (pairs.size() != to_visit) {
            int x = pairs[pairs.size() - 1][0];
            int y = pairs[pairs.size() - 1][1];
            std::cout << x << "," << y << "|";
            switch (dir) {
            case Direction::Right:
                if (x < cols - 1 && !contains(pairs, x + 1, y)) {
                    pairs.push_back({x + 1, y});
                }
                dir = Direction::Down;
                break;
            case Direction::Down:
                if (y < rows - 1 && !contains(pairs, x, y + 1)) {
                    pairs.push_back({x, y + 1});
                }
                dir = Direction::Left;
                break;
            case Direction::Left:
                if (x > 0 && !contains(pairs, x - 1, y)) {
                    pairs.push_back({x - 1, y});
                }
                dir = Direction::Up;
                break;
            case Direction::Up:
                if (y > 0 && !contains(pairs, x, y - 1)) {
                    pairs.push_back({x, y - 1});
                }
                dir = Direction::Right;
                break;
            }
        }
        return pairs;
    }
};

int main()
{
    Solution s{};
    auto v = s.spiralMatrixIII(5, 6, 1, 4);
    for (auto const& pair : v) {
        std::cout << pair[0] << "," << pair[1] << "|";
    }
}
