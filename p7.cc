#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        std::string x_string = std::to_string(abs(x));
        std::reverse(x_string.begin(), x_string.end());
        long x_rev = std::stol(x_string);
        if (x_rev > 2147483647){
            return 0;
        }
        if (x < 0){
            return -x_rev;
        }
        return x_rev;
    }
};

int main() {
    Solution s{};
    std::cout << s.reverse(1534236469) << "\n";
}