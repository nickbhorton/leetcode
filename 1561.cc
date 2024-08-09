#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        int sum = 0;
        std::sort(piles.begin(), piles.end());
        for (int i = 0; i < n; i++){
            piles.pop_back();
            sum += piles.back();
            piles.pop_back();
        }
        return sum;
    }
};

int main() {
    std::vector<int> piles = {2,4,1,2,7,8};
    Solution s{};
    std::cout << s.maxCoins(piles) << "\n";
}