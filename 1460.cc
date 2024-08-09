#include <iostream>
#include <map>
#include <vector>

using std::vector;

class Solution
{
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        std::map<int, unsigned int> d_target{};
        for (auto const& val : target) {
            if (d_target.contains(val)) {
                d_target[val] += 1;
            } else {
                d_target.insert({val, 1});
            }
        }
        std::map<int, unsigned int> d_arr{};
        for (auto const& val : arr) {
            if (!d_target.contains(val)) {
                return false;
            } else {
                if (d_arr.contains(val)) {
                    d_arr[val]++;
                } else {
                    d_arr.insert({val, 1});
                }
            }
        }
        for (auto i = d_target.begin(); i != d_target.end(); i++) {
            if (d_arr[i->first] != i->second) {
                return false;
            }
        }
        return true;
    }
};

int main() { std::cout << "hello world\n"; }
