#include <iostream>
#include <string>
using std::string;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int len{};
        bool start{false};
        for (size_t i = 0; i < s.size(); i++) {
            if (s[s.size() - 1 - i] != ' ' && !len) {
                len++;
            } else if (s[s.size() - 1 - i] == ' ' && len) {
                break;
            } else if (len) {
                len++;
            }
        }
        return len;
    }
};
int main()
{
    Solution s{};
    std::cout << s.lengthOfLastWord("    world   k   ") << "\n";
}
