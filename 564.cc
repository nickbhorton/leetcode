#include <cstdint>
#include <iostream>
#include <string>
using std::string;

/*

Return the closest integer palindrome
123
3 letters
313
121
222

There are a lot of options
Naive approach would be to check the numbers in order and see if they are
palindromes.

Naive approach seems to not fail except that it is not fast enough for large
numbers. This makes sense.
This is where it fails

807045053224792883
807045053 224792883
18 digits
there are two ways to make a number a new palindrome. Change its first half to
match the second half or vice versa.

Obviously the only option is to change the second half because that is where the
closest numbers will be.

The second approach was just to make the number palindromic by changing the
lower half. However this does not work with

1: number of digits in answer != number of digits in n
Example 10 and 11
2: numbers that are already palindromic
Example 88 77 66

*/

class Solution
{
public:
    bool is_palindrome(int64_t num)
    {
        std::string s = std::to_string(num);
        if (s.size() % 2 == 1) {
            // odd
            int checks = (s.size() - 1) / 2;
            for (size_t i = 0; i < checks; i++) {
                if (s[i] != s[s.size() - 1 - i]) {
                    return false;
                }
            }
        } else {
            // even
            int checks = (s.size()) / 2;
            for (size_t i = 0; i < checks; i++) {
                if (s[i] != s[s.size() - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool print_second_half_problems(std::string s)
    {
        if (s.size() % 2 == 1) {
            // odd
            int checks = (s.size() - 1) / 2;
            for (size_t i = 0; i < checks; i++) {
                if (s[i] != s[s.size() - 1 - i]) {
                    return false;
                }
            }
        } else {
            // even
            int checks = (s.size()) / 2;
            std::cout << s << "\n";
            for (int i = 0; i < checks; i++) {
                std::cout << " ";
            }
            for (size_t i = 0; i < checks; i++) {
                if (s[i] != s[s.size() - 1 - i]) {
                    std::cout << "x";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
        return true;
    }
    string nearestPalindromic(string n)
    {
        std::string s = n;
        if (n == "10") {
            return "9";
        }
        if (s.size() == 1) {
            return std::to_string(std::stoll(n) - 1);
        }
        int checks{};
        if (s.size() % 2 == 1) {
            // odd
            checks = (s.size() - 1) / 2;
        } else {
            // even
            checks = (s.size()) / 2;
        }
        for (size_t i = 0; i < checks; i++) {
            s[s.size() - 1 - i] = s[i];
        }
        return s;
    }
};

int main()
{
    Solution s{};
    /*
    testing that is_palindrome is correct
    std::cout << s.is_palindrome(1);
    std::cout << s.is_palindrome(121);
    std::cout << s.is_palindrome(12321);
    std::cout << s.is_palindrome(1234321);
    std::cout << s.is_palindrome(11);
    std::cout << s.is_palindrome(1221);
    std::cout << s.is_palindrome(123321);
    std::cout << s.is_palindrome(12344321);
    std::cout << s.is_palindrome(12);
    std::cout << s.is_palindrome(123);
    std::cout << "\n";
    */
    std::cout << s.nearestPalindromic("123") << "\n";
    std::cout << s.nearestPalindromic("1") << "\n";
    std::cout << s.nearestPalindromic("807045053224792883") << "\n";
}
