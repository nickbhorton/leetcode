#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        std::map<std::string, int> s{};
        int unique{};
        for (auto const& str : arr) {
            if (!s.contains(str)) {
                s.insert({str, 1});
                unique++;
            } else {
                s[str]++;
            }
        }
        if (unique < k) {
            return "";
        }

        unique = 0;
        for (auto const& str : arr) {
            if (s[str] == 1) {
                unique++;
                if (unique == k) {
                    return str;
                }
            }
        }
        return "";
    }
};

int main()
{
    Solution s{};
    std::vector<std::string> v{"d", "b", "c", "b", "c", "a"};
    std::cout << s.kthDistinct(v, 2) << "\n";
}
