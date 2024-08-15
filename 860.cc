#include <vector>
using std::vector;
class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int fives{};
        int tens{};
        int twenties{};
        for (auto const bill : bills) {
            switch (bill) {
            case 5:
                fives++;
                break;
            case 10:
                if (fives >= 1) {
                    tens++;
                    fives--;
                } else {
                    return false;
                }
                break;
            case 20:
                if (fives >= 1 && tens >= 1) {
                    tens--;
                    fives--;
                    twenties++;
                } else if (fives >= 3) {
                    fives -= 3;
                    twenties++;
                } else {
                    return false;
                    break;
                default:
                    break;
                }
            }
        }
        return true;
    }
};
