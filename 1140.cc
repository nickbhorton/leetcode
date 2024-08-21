#include <iostream>
#include <vector>
using std::vector;
/*
A goes first with M = 1
1 <= X <= 2M
pick an X
grab X piles
M = max(M, X)
Find maximum stones that alice can get
*/
class Solution
{
public:
    // returns alice final score
    int take_stones(
        vector<int>& piles,
        size_t piles_start,
        int a_score,
        int b_score,
        bool a_turn,
        int m
    )
    {
        if (piles_start > piles.size() - 1) {
            std::cout << "A: " << a_score << " B: " << b_score << "\n";
            return a_score;
        }
        int max_score{};
        if (a_turn) {
            for (int takes = 1;
                 takes <= 2 * m && piles_start + takes <= piles.size();
                 takes++) {
                int score{};
                for (int i = piles_start;
                     i < piles_start + takes && i < piles.size();
                     i++) {
                    score += piles[i];
                }
                std::cout << "A takes " << takes << " piles with score of "
                          << score << "\n";
                int other_a_score = take_stones(
                    piles,
                    piles_start + takes,
                    a_score + score,
                    b_score,
                    false,
                    std::max(takes, m)
                );
                if (other_a_score > max_score) {
                    max_score = other_a_score;
                }
            }
        } else {
            int score{};
            int takes{std::min((int)piles.size() - (int)piles_start, 2 * m)};
            for (int i = piles_start;
                 i < piles_start + takes && i < piles.size();
                 i++) {
                score += piles[i];
            }
            std::cout << "B takes " << takes << " piles with score of " << score
                      << "\n";
            int other_a_score = take_stones(
                piles,
                piles_start + takes,
                a_score,
                b_score + score,
                true,
                std::max(takes, m)
            );
            if (other_a_score > max_score) {
                max_score = other_a_score;
            }
        }
        return max_score;
    }
    int stoneGameII(vector<int>& piles)
    {
        return take_stones(piles, 0, 0, 0, true, 1);
    }
};
int main()
{
    Solution s{};
    std::vector<int> piles1{2, 7, 9, 4, 4};
    std::vector<int> piles2{1, 2, 3, 4, 5, 100};
    std::cout << s.stoneGameII(piles1) << "\n\n";
    std::cout << s.stoneGameII(piles2) << "\n";
}
