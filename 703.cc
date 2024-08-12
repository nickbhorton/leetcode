#include <iostream>
#include <vector>

using std::vector;

/*
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
[8, 5, 4, 2] looking at the 3rd largest element
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
*/

// From constraint on nums[i]
int constexpr Empty = -10001;

class KthLargest
{
public:
    std::vector<int> stream;
    KthLargest(int k, vector<int>& nums) : stream(k, Empty)
    {
        for (int i = 0; i < k; i++) {
            int max{Empty};
            int max_index{-1};
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] > max) {
                    max = nums[j];
                    max_index = j;
                }
            }
            if (max_index != -1) {
                nums[max_index] = Empty;
                stream[i] = max;
            }
        }
    }

    // need to do a binary search and insert
    int add(int val)
    {
        int kth = stream[stream.size() - 1];
        if (val < kth) {
            return kth;
        }
        int left = 0;
        int right = stream.size() - 1;
        int mid = stream.size() / 2;
        while (left < right) {
            if (val > stream[mid]) {
                right = mid;
                mid = left + (right - left) / 2;
            } else if (val < stream[mid]) {
                left = mid + 1;
                mid = left + (right - left) / 2;
            } else {
                left = mid;
                right = mid;
            }
        }
        stream.insert(stream.begin() + mid, val);
        stream.pop_back();
        return stream[stream.size() - 1];
    }
};

int main()
{
    std::vector<int> nums = {};
    int k = 1;
    KthLargest* obj = new KthLargest(k, nums);
    std::cout << obj->add(-3) << "\n";
    std::cout << obj->add(-2) << "\n";
    std::cout << obj->add(-4) << "\n";
    std::cout << obj->add(0) << "\n";
    std::cout << obj->add(4) << "\n";
}
