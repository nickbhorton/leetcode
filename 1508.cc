#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        std::vector<int> a{};
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum{};
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                a.push_back(sum);
            }
        }
        std::sort(a.begin(), a.end());
        int result{};
        for (int i = left - 1; i < right; i++) {
            result += a[i];
        }
        return result;
    }
};

int main()
{
    Solution s{};
    std::vector<int> v{1, 2, 3, 4};
    std::cout << s.rangeSum(v, 4, 1, 5) << "\n";
};
