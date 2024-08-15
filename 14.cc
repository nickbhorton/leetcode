#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        std::string longest_prefex = strs[0];
        for (auto const& str : strs) {
            int stoped{-1};
            for (size_t i = 0; i < longest_prefex.size(); i++) {
                if (str.size() == i) {
                    stoped = i;
                } else {
                    if (str[i] != longest_prefex[i]) {
                        stoped = i;
                    }
                }
                if (stoped != -1) {
                    longest_prefex = longest_prefex.substr(0, stoped);
                }
            }
        }
        return longest_prefex;
    }
};
int main()
{
    Solution s{};
    std::vector<std::string> strs{"flower", "flow", "flight"};
    std::vector<std::string> strs2{"dog", "racecar", "car"};
    std::cout << s.longestCommonPrefix(strs) << "\n";
    std::cout << s.longestCommonPrefix(strs2) << "\n";
}
