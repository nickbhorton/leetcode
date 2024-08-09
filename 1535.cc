#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int getWinner(vector<int>& arr, int k)
    {
        int max{arr[0]};
        int beats{};
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << "\n";
            if (arr[i] > max) {
                max = arr[i];
            }
            for (int j = i + 1; j < arr.size();) {
                if (arr[i] > arr[j]) {
                    beats++;
                    if (beats == k) {
                        return arr[i];
                    }
                    j += 1;
                } else {
                    i += beats - 1;
                    beats = 1;
                    if (k == 1) {
                        return arr[j];
                    }
                    break;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution s{};
    std::vector<int> v{1, 25, 35, 70, 68, 42};
    std::cout << s.getWinner(v, 4) << "\n";
}
