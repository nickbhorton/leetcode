#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
using std::vector;

/*
 * The two smaller side lengths have to be greater than the longest side length
 * assuming we have three side length a, b, and c where a <= b <= c
 * a + b > c to form a triangle
 */

template <typename T>
auto operator<<(std::ostream& os, std::vector<T> const& v) -> std::ostream&
{
    for (auto const& e : v) {
        os << e << " ";
    }
    return os;
}

class Solution
{
    bool is_triangle(int a, int b, int c) { return a + b > c; }

public:
    int largestPerimeter(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        std::cout << nums << "\n";
        size_t const n = nums.size();
        for (size_t c = 0; c < n - 2; c++) {
            size_t b = c + 1;
            size_t a = c + 2;
            std::cout << nums[a] << " " << nums[b] << " " << nums[c] << " "
                      << is_triangle(nums[a], nums[b], nums[c]) << "\n";
            if (is_triangle(nums[a], nums[b], nums[c])) {
                return nums[a] + nums[b] + nums[c];
            }
        }
        return 0;
    }
};

int main()
{
    Solution s{};
    std::vector<int> nums1{1, 2, 1, 10};
    std::vector<int> nums2{2, 1, 2};
    std::cout << s.largestPerimeter(nums1) << "\n";
    std::cout << s.largestPerimeter(nums2) << "\n";
}
