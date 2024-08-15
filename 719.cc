#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using std::vector;

/*
Distance between two ints a and b is the absolute difference between a and b
10 - 6 = 4 = 4
6 - 10 = -4 = 4
Its like the distance between 6 and 10 on the numberline is 4

find the kth smallest distance among all the pairs

How many pairs are there?
If we have a array length of 4
|a - b| = |b - a|
a^2 + b^2 - 2ab = b^2 + a^2 -2ab
Therefor (1 2) and (2 1) is not different
So given the length of the array n
we have n choose 2
n!/(2(n-2)!) =
(n(n-1))/2
(n^2 - n)/2 number of pairs. Which is not extreme.
Are largest array is 10,000 which would be
49,995,000 which to store an array or sort it is much to large.

Another substative problem is that k can be any number from 1 to n*(n-1)/2. This
makes me think that there has to be some process to get the kth distance without
storing them all. Also the topics are two pointer / sorting / binary search so
this makes sense too.

The array is sorted
1 2 3 4 = 1
^ ^
There are choices we can make either
1. move the second pointer up one.
1 2 3 4 = 2
^   ^
2 or move both up one
1 2 3 4 = 1
  ^ ^
Option 1 is guarenteed to find a greater or equal diff
Option 2 is mathematically scary atm

But if out array is stored we have these difference streams of sorted arrays
1 2 3 4 5 6 7 8 9 10
$ ^ ^ ^ ^ ^ ^ ^ ^ ^
1 2 3 4 5 6 7 8 9

1 2 3 4 5 6 7 8 9 10
  $ ^ ^ ^ ^ ^ ^ ^ ^
1 2 3 4 5 6 7 8

1 2 3 4 5 6 7 8 9 10
    $ ^ ^ ^ ^ ^ ^ ^
1 2 3 4 5 6 7

1 2 3 4 5 6 7 8 9 10
      $ ^ ^ ^ ^ ^ ^
1 2 3 4 5 6

1 2 3 4 5 6 7 8 9 10
        $ ^ ^ ^ ^ ^
1 2 3 4 5

1 2 3 4 5 6 7 8 9 10
          $ ^ ^ ^ ^
1 2 3 4

1 2 3 4 5 6 7 8 9 10
            $ ^ ^ ^
1 2 3

1 2 3 4 5 6 7 8 9 10
              $ ^ ^
1 2

1 2 3 4 5 6 7 8 9 10
                $ ^
1

With a length of 10 we have 10 - 1 arrays starting with a length of 9 and ending
with a length of 2


*/

void printv(std::vector<std::pair<int, std::pair<size_t, size_t>>> const& v)
{
    for (auto const& [diff, ipair] : v) {
        std::cout << "(" << std::get<0>(ipair) << " " << std::get<1>(ipair)
                  << ")  " << diff << "\n";
    }
}

std::pair<size_t, int>
smallest(std::vector<std::pair<int, std::pair<size_t, size_t>>> const& v)
{
    int smallest{INT_MAX};
    size_t result{0};
    size_t j{0};
    for (auto const& [diff, ipair] : v) {
        if (diff < smallest) {
            smallest = diff;
            result = j;
        }
        j++;
    }
    return {result, smallest};
}

class Solution
{
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::pair<int, std::pair<size_t, size_t>>> working_sets{};
        for (size_t i = 0; i < nums.size() - 1; i++) {
            working_sets.push_back({nums[i + 1] - nums[i], {i, i + 1}});
        }
        int kc{1};
        int n{static_cast<int>(nums.size())};
        int maxn = ((n * (n - 1)) / 2) - (n - 1);
        std::cout << maxn << "\n";
        while (kc < maxn) {
            printv(working_sets);
            std::cout << "\n";
            auto const [i, smallest_diff] = smallest(working_sets);
            if (kc == k) {
                return smallest_diff;
            }
            std::get<1>(std::get<1>(working_sets[i]))++;
            std::get<0>(working_sets[i]) =
                nums[std::get<1>(std::get<1>(working_sets[i]))] -
                nums[std::get<0>(std::get<1>(working_sets[i]))];
            kc++;
        }
        std::vector<int> leftovers{};
        for (auto const& [diff, ipair] : working_sets) {
            leftovers.push_back(diff);
        }
        std::sort(leftovers.begin(), leftovers.end());
        for (auto const& val : leftovers) {
            std::cout << val << " ";
        }
        std::cout << "\n" << k - kc - 1 << "\n";
        return leftovers[k - kc - 1];
    }
};
int main()
{
    Solution s{};
    std::vector<int> nums{1, 3, 1};
    std::cout << s.smallestDistancePair(nums, 1) << "\n";
}
