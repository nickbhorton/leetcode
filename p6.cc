#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        std::string result{};
        for (int i = 0; i < s.length(); i++){
            result += s[(i*4)%s.length()];
        }
        return result;
    }
};

int main() {
    Solution s{};
    std::cout << s.convert("0123456", 3) << "\n";
}