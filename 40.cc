#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using std::vector;

/*
Given an array of number and a target number. Find all UNIQUE combinations that
sum to the target.

max length of candidates is 100 so to check if one number sums up to target
its 100 then to check if any two numbers sum up to target its 100 * 99 = 9900

100!/99! = 100!/(100-n)!

This seems like it will be to long to calcuate by loops and brute force.

Example 1:
[10,1,2,7,6,1,5] target 8
First remove 10
[1,2,7,6,1,5]
{[0(1)], 1}
    {[0(1), 1(2)], 3}
    {[0(1), 2(7)], 8} CHECK
    {[0(1), 3(6)], 7}
    {[0(1), 4(1)], 2}
    {[0(1), 5(5)], 6}

{[1(2)], 2}
    {[1(2), 0(1)], 3} DUPLICATE

{[2(7)], 7}
{[3(6)], 6}
{[4(1)], 1}
{[5(5)], 5}

this stratagy will not only duplicate sums but also duplicate tree branches
which is very bad

to show this better im going to make up an example
[1,1,1] target 2
[] z
0  1 a
    0 1  2 ANS d
    0 2  2 ANS f
1  1 b
    1 0  2 DUP d
    1 2  2 ANS e
2  1 c
    2 0  2 DUP f
    2 1  2 DUP e

        z
   /    |    \
  a     b     c
 / \   / \   / \
d   f d   e f   e

      z
   /  |  \
  b   c   a
 / \ / \ / \
d   e   f   d
[0]
[1]
[2]
[0 1]
[0 2]
[1 2]
[0 1 2]

To avoid duplicates we at each depth all we need n number of indexs
[1 1 1]
 0
[1 1 1]
   1
[1 1 1]
     2
[1 1 1]
 0 1
[1 1 1]
 0   2
[1 1 1]
   1 2
[1 1 1]
 0 1 2

0
can we add another number | yes
    0 1
    can we add another number | yes
        0 1 2
        can we add another number | no
        can we increment the last number | no
    can we increment the last number | yes
        0 2
        can we add another number | no
        can we increment the last number | no
can we increment the last number | yes
    1
    can we add another number | yes
        1 2
        can we add another number | no
        can we increment the last number | no
    can we increment the last nubmer | yes
        2
        can we add another number | no
        can we increment the last number | no

So we made 3 answers with 3 duplicates

*/

static void printv(std::vector<int> const& v)
{
    for (auto const& val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
static void printvv(std::vector<std::vector<int>> const& v)
{
    for (auto const& val : v) {
        printv(val);
    }
}

class Solution
{
public:
    void helper(
        std::vector<int>& is,
        int max,
        std::vector<std::vector<int>>& result,
        std::vector<int> const& canadates,
        int target
    )
    {
        printv(is);
        int sum{};
        for (auto const& i : is) {
            sum += canadates[i];
        }
        if (sum == target) {
            std::vector<int> additions{};
            for (auto const& i : is) {
                additions.push_back(canadates[i]);
            }
            std::sort(additions.begin(), additions.end());
            bool already_found{false};
            for (auto const& r : result) {
                bool breaked = false;
                if (r.size() != additions.size()) {
                    continue;
                }
                for (size_t i = 0; i < r.size(); i++) {
                    if (r[i] != additions[i]) {
                        breaked = true;
                        break;
                    }
                }
                if (!breaked) {
                    already_found = true;
                    break;
                }
            }
            if (!already_found) {
                result.push_back(additions);
            }
        }

        if (is.size() <= max && is[is.size() - 1] < max && sum < target) {
            is.push_back(is[is.size() - 1] + 1);
            helper(is, max, result, canadates, target);
            is.pop_back();
        }
        if (is[is.size() - 1] < max) {
            is[is.size() - 1]++;
            helper(is, max, result, canadates, target);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result{};
        std::map<int, int> dups{};
        std::vector<int> real_cadiadates{};
        for (auto const& c : candidates) {
            if (c < target && dups[c] < target) {
                real_cadiadates.push_back(c);
                dups[c]++;
            } else if (c == target && result.size() == 0) {
                result.push_back({c});
            }
        }
        if (real_cadiadates.size() == 0) {
            return {};
        }
        std::vector<int> is{0};
        helper(is, real_cadiadates.size() - 1, result, real_cadiadates, target);
        return result;
    }
};

int main()
{
    Solution s{};
    std::vector<int> v{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printvv(s.combinationSum2(v, 30));
}
