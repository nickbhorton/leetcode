#include <cmath>
#include <iostream>
class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 1) {
            return 0;
        }
        int bitsize = std::ceil(std::log2(num));
        return (~(((unsigned int)num) << (32 - bitsize))) >> (32 - bitsize);
    }
};

int main()
{
    Solution s{};
    std::cout << s.findComplement(5) << "\n";
    std::cout << s.findComplement(1) << "\n";
    /// 1010 -> 0101 5
    std::cout << s.findComplement(10) << "\n";
    /// 10 -> 01 1
    std::cout << s.findComplement(2) << "\n";
}
