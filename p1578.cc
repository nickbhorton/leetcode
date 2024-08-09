#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minimum_time {0};
        int left {0};
        int right {1};
        while (right < colors.size()){
            char previous_char {colors[left]};
            char current_char {colors[right]};
            std::cout << "left: " << left << "->" << colors[left] << " " << neededTime[left] << "\n";
            std::cout << "right: " << right << "->" << colors[right] << " " << neededTime[right] << "\n";
            if (current_char == previous_char){
                if (neededTime[left] < neededTime[right]){
                    minimum_time += neededTime[left];
                    std::cout << "add: " << neededTime[left] << "\n";
                    left = right;
                    ++right;
                }
                else {
                    minimum_time += neededTime[right];
                    std::cout << "add: " << neededTime[right] << "\n";
                    ++right;
                }
            }
            else {
                left = right;
                ++right;
            }
        }
        std::cout << left << "\n";
        return minimum_time;
    }
};

int main() {
    std::vector<int> needed_time = {1,3,6,5,4,5,4,4,2,8,3,10,6,6};
    std::string colors = "aaaaaaaaaaaaaa";
    Solution sol{};
    std::cout << sol.minCost(colors, needed_time) << "\n";
}