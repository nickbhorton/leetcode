#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {  
        constexpr int a_ascii = 0x61;
        std::vector<int> s_set{};
        s_set.resize(26);
        std::vector<int> t_set{};
        t_set.resize(26);
        for (const auto& c : s) {
            s_set[c - a_ascii]++;
        }
        for (const auto& c : t) {
            t_set[c - a_ascii]++;
        }
        // for (const auto& c : s_set) {
        //     std::cout << c << " ";
        // }
        // std::cout << "\n";
        // for (const auto& c : t_set) {
        //     std::cout << c << " ";
        // }
        // std::cout << "\n";
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            // if (s_set[i] - t_set[i] != 0) {
                // std::cout << s_set[i] - t_set[i] << " ";
                sum += std::abs(s_set[i] - t_set[i]);
            // }
        }
        // std::cout << "\n";
        // std::cout << sum/2 << "\n";

        return sum/2;
    }
};

int main() {
    Solution s{};
    std::cout << s.minSteps("anagram", "mangaar") << "\n";
}