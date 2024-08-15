#include <stack>
#include <string>
using std::string;
class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> cstack{};
        char popped{};
        for (auto const& c : s) {
            switch (c) {
            case '(':
            case '{':
            case '[':
                cstack.push(c);
                break;
            case ')':
                if (cstack.empty()) {
                    return false;
                }
                popped = cstack.top();
                cstack.pop();
                if (popped != '(') {
                    return false;
                }
                break;
            case '}':
                if (cstack.empty()) {
                    return false;
                }
                popped = cstack.top();
                cstack.pop();
                if (popped != '{') {
                    return false;
                }
                break;
            case ']':
                if (cstack.empty()) {
                    return false;
                }
                popped = cstack.top();
                cstack.pop();
                if (popped != '[') {
                    return false;
                }
                break;
            }
        }
        return cstack.empty();
    }
};
