#include <algorithm>
#include <vector>
using std::vector;
class Solution
{
public:
    int heightChecker(vector<int>& heights)
    {
        std::vector<int> expected{heights};
        std::sort(expected.begin(), expected.end());
        int diffs{};
        for (size_t i = 0; i < expected.size(); i++) {
            if (expected[i] != heights[i]) {
                diffs++;
            }
        }
        return diffs;
    }
};
