#include <cstdint>
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t n_mut = n;
        uint32_t one = 1;
        int one_count = 0;
        for (int i = 0; i < 32; i++){
            if (n_mut & one){
                ++one_count;
            }
            n_mut >>= 1;
        }
        return one_count;
    }
};

int main() {
    Solution s {};
    std::cout << s.hammingWeight(8) << "\n";
}   