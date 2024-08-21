#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    bool helper(
        std::vector<int> const piles,
        int front_i,
        int back_i,
        int alice_score,
        int bob_score,
        bool alice_turn
    )
    {
        if (front_i > back_i) {
            std::cout << alice_score << " " << bob_score << "\n";
            return alice_score > bob_score;
        } else {
            if (alice_turn) {
                return helper(
                           piles,
                           front_i + 1,
                           back_i,
                           alice_score + piles[front_i],
                           bob_score,
                           false
                       ) ||
                       helper(
                           piles,
                           front_i,
                           back_i - 1,
                           alice_score + piles[back_i],
                           bob_score,
                           false
                       );
            } else {
                return helper(
                           piles,
                           front_i + 1,
                           back_i,
                           alice_score,
                           bob_score + piles[front_i],
                           true
                       ) ||
                       helper(
                           piles,
                           front_i,
                           back_i - 1,
                           alice_score,
                           bob_score + piles[back_i],
                           true
                       );
            }
        }
    }
    bool stoneGame(vector<int>& piles)
    {
        return helper(piles, 0, piles.size() - 1, 0, 0, true);
    }
};
int main()
{
    Solution s{};
    std::vector<int> piles1{5, 3, 4, 5};
    std::cout << s.stoneGame(piles1) << "\n";
}
