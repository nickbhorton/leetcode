#include <iostream>
#include <string>
using std::string;
class Solution
{
public:
    int romanToInt(string s)
    {
        int val{};
        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case 'I':
                if (i != s.size() - 1 && s[i + 1] == 'V') {
                    val += 4;
                    i++;
                } else if (i != s.size() - 1 && s[i + 1] == 'X') {
                    val += 9;
                    i++;
                } else {
                    val++;
                }
                break;
            case 'V':
                val += 5;
                break;
            case 'X':
                if (i != s.size() - 1 && s[i + 1] == 'L') {
                    val += 40;
                    i++;
                } else if (i != s.size() - 1 && s[i + 1] == 'C') {
                    val += 90;
                    i++;
                } else {
                    val += 10;
                }
                break;
            case 'L':
                val += 50;
                break;
            case 'C':
                if (i != s.size() - 1 && s[i + 1] == 'D') {
                    val += 400;
                    i++;
                } else if (i != s.size() - 1 && s[i + 1] == 'M') {
                    val += 900;
                    i++;
                } else {
                    val += 100;
                }
                break;
            case 'D':
                val += 500;
                break;
            case 'M':
                val += 1000;
                break;
            default:
                break;
            }
        }
        return val;
    }
};

int main()
{
    Solution s{};
    std::cout << (s.romanToInt("III") == 3) << "\n";
    std::cout << (s.romanToInt("IV") == 4) << "\n";
    std::cout << (s.romanToInt("V") == 5) << "\n";
}
