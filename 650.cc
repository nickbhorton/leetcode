/*

a 0
aa is copy then paste 2
aaa is copy then paste then paste 3
aaaa is copy then paste then copy then paste or copy paste paste paste
aaaaa is copy paste paste paste paste 5

aaaaaa copy paste copy paste paste 5
copy paste paste copy paste 5
1 5
2 4
3 3
aaaaaaaa
1 7
2 6
3 5
4 4
2 2 4
1 1 2 4
copy paste copy paste copy paste

2 copys in a row does nothing


*/
#include <iostream>
#include <string>
class Solution
{
public:
    int execute_steps(std::string const& str)
    {
        int screen = 1;
        int chamber = 0;
        for (auto const& c : str) {
            if (c == 'c') {
                chamber = screen;
            } else {
                screen += chamber;
            }
        }
        return screen;
    }
    int minSteps(int n) {}
};

int main()
{
    Solution s{};
    std::cout << s.execute_steps("c") << "\n";
}
