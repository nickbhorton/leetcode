#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int const n = nums.size();
        int split_count{};
        int bot{nums[0]};
        int top{};
        for (int i = 1; i < n; i++) {
            top += nums[i];
        }
        if (bot >= top) {
            split_count++;
        }
        for (int i = 1; i < n - 1; i++) {
            bot += nums[i];
            top -= nums[i];
            if (bot >= top) {
                split_count++;
            }
        }
        return split_count;
    }
};

int main()
{
    Solution s{};
    std::vector<int> nums1{10, 4, -8, 7};
    std::vector<int> nums2{2, 3, 1, 0};
    std::cout << s.waysToSplitArray(nums1) << "\n";
    std::cout << s.waysToSplitArray(nums2) << "\n";
}
