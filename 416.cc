#include <cstdint>
#include <vector>
using std::vector;

/*
return true if nums can be partitioned into two equal sum sets.

my first though is if we take the sum of the whole nums array then we just have
to find all the sums it is possible to make and subtract it from the full sum.
Then if the leftover is equal to the sum of the nums picked then we win.

*/

class Solution
{
public:
    bool
    get(size_t index, uint64_t set1, uint64_t set2, uint64_t set3, uint8_t set4)
    {
        if (index <= 64) {
            return set1 & (1 << index);
        } else if (index <= 128) {
            return set2 & (1 << (index - 64));
        } else if (index <= 192) {
            return set3 & (1 << (index - 128));
        } else {
            return set4 & (1 << (index - 192));
        }
    }
    void
    set(size_t index,
        uint64_t& set1,
        uint64_t& set2,
        uint64_t& set3,
        uint8_t& set4)
    {
        if (index <= 64) {
            set1 = set1 | (1 << index);
        } else if (index <= 128) {
            set2 = set2 | (1 << (index - 64));
        } else if (index <= 192) {
            set3 = set3 | (1 << (index - 128));
        } else {
            set4 = set4 | (1 << (index - 192));
        }
    }

    bool helper(
        std::vector<int> const& nums,
        int target,
        uint64_t set1,
        uint64_t set2,
        uint64_t set3,
        uint8_t set4
    )
    {
    }

    bool canPartition(vector<int>& nums)
    {
        int full_sum{};
        for (auto const& n : nums) {
            full_sum += n;
        }
        // if its odd this wont work
        if (full_sum % 2 == 1) {
            return false;
        }
        // This is the sum we have to hit with some permutation of nums elements
        int const target{full_sum / 2};
        size_t const n = nums.size();
        return helper(nums, target, 0, 0, 0, 0);
    }
};
