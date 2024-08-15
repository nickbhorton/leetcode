#include <iostream>
#include <string>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string xs{std::to_string(x)};
        int limit = xs.size() % 2 ? xs.size() / 2 + 1 : xs.size() / 2;
        for (int i = 0; i < limit; i++) {
            if (xs[i] != xs[xs.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s{};
    std::cout << s.isPalindrome(121) << "\n";
    std::cout << s.isPalindrome(11) << "\n";
    std::cout << s.isPalindrome(12) << "\n";
    std::cout << s.isPalindrome(122) << "\n";
}
