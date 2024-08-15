#include <vector>
using std::vector;

/*
We have a circular array of numbers you cannot break into two adjacent houses on
the same night.
*/
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int sum1{};
        int sum2{};
        for (size_t i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                sum1 += nums[i];
            } else {
                sum2 += nums[i];
            }
        }
        if (nums.size() % 2 == 1) {
            sum1 -= nums[nums.size() - 1];
        }
        return sum1 > sum2 ? sum1 : sum2;
    }
};

int main() {
}
