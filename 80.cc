#include <iostream>
#include <vector>
using std::vector;

int static constexpr Removed = -10001;

/*
1 1 R 2 2 R R 4 R
            i
            j
i = 2
j = 0
*/

void printv(std::vector<int> const& v)
{
    for (auto const& num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int counted_number{nums[0]};
        int count{0};
        int removed_count{0};
        for (auto& num : nums) {
            if (num == counted_number) {
                count++;
            } else {
                count = 1;
                counted_number = num;
            }
            if (count >= 3) {
                num = Removed;
                removed_count++;
            }
        }
        printv(nums);
        int k = (int)nums.size() - removed_count;
        removed_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[nums.size() - 1 - i] == Removed) {
                removed_count++;
                for (int j = 0; j < i; j++) {
                    nums[nums.size() - 1 - i + j] =
                        nums[nums.size() - 1 - i + j + 1];
                }
            }
            printv(nums);
        }
        return k;
    }
};
int main()
{
    Solution s{};
    std::vector<int> nums1{1, 1, 1, 2, 2, 3};
    std::cout << s.removeDuplicates(nums1) << "\n";
    std::vector<int> nums2{0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::cout << s.removeDuplicates(nums2) << "\n";
    std::vector<int> nums3{0, 0, 1, 1, 1, 1, 2, 2, 2, 4};
    std::cout << s.removeDuplicates(nums3) << "\n";
}
