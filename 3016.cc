#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int letters[26]{};
        for (auto const& c : word) {
            ++letters[c - 'a'];
        }
        std::sort(letters, letters + 26, std::greater<int>());
        int result{};
        int weight{1};
        for (int i = 0; i < 26 && letters[i] != 0; i++) {
            if (i > 0 && i % 8 == 0) {
                weight++;
            }
            result += weight * letters[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.minimumPushes("abcdee") << "\n";
}
