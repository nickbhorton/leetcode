#include <iostream>
#include <vector>
using std::vector;

void printv(std::vector<int> const& nums)
{
    for (auto const& num : nums) {
        std::cout << num;
    }
    std::cout << "\n";
}

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        size_t i = 0;
        while (digits[digits.size() - 1 - i] == 9 || i == digits.size()) {
            digits[digits.size() - 1 - i] = 0;
            i++;
        }
        if (i >= digits.size()) {
            digits[0] = 1;
            digits.push_back(0);
        } else {
            digits[digits.size() - 1 - i]++;
        }
        return digits;
    }
};

int main()
{
    Solution s{};
    std::vector<int> d1{9, 9, 9};
    printv(s.plusOne(d1));
    std::vector<int> d2{8, 9, 9};
    printv(s.plusOne(d2));
    std::vector<int> d3{9, 9, 8};
    printv(s.plusOne(d3));
    std::vector<int> d4{9};
    printv(s.plusOne(d4));
}
