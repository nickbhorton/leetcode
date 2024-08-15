#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/*
meetings[i] indicates that person meetings[i][0] has a meeting with person
meetings[i][1] at time meetings[i][2]

Person 0 has a secret

At time 0 person zero shares the secret with person firstPerson. Then at every
meeting that has a person with a secret all people at that meeting will know the
secret.

Return a list of people who know the secret after all meetings
*/

class Solution
{
public:
    vector<int>
    findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        std::sort(
            meetings.begin(),
            meetings.end(),
            [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; }
        );
        std::vector<bool> people_who_know(n, false);
        people_who_know[0] = true;
        people_who_know[firstPerson] = true;

        /*
        for (auto const& meeting : meetings) {
            std::cout << meeting[0] << "/" << meeting[1] << " " << meeting[2]
                      << "\n";
        }
        */

        std::vector<int> people_in_meeting_at_t{};
        bool secret{false};
        int t{meetings[0][2]};
        size_t i{};
        while (i < meetings.size()) {
            if (meetings[i][2] == t) {
                people_in_meeting_at_t.push_back(meetings[i][0]);
                // std::cout << "added " << meetings[i][0] << "\n";
                people_in_meeting_at_t.push_back(meetings[i][1]);
                // std::cout << "added " << meetings[i][1] << "\n";
                if (people_who_know[meetings[i][0]] ||
                    people_who_know[meetings[i][1]]) {
                    secret = true;
                    // std::cout << "they know secret\n";
                }
                i++;
            } else {
                if (secret) {
                    // std::cout << "t: " << t << " ";
                    for (auto const& person : people_in_meeting_at_t) {
                        people_who_know[person] = true;
                    }
                    /*
                    for (auto const& person : people_who_know) {
                        std::cout << person;
                    }
                    std::cout << "\n";
                    */
                }
                t = meetings[i][2];
                people_in_meeting_at_t.clear();
                secret = false;
            }
        }
        if (secret) {
            // std::cout << "t: " << t << " ";
            for (auto const& person : people_in_meeting_at_t) {
                people_who_know[person] = true;
            }
            /*
            for (auto const& person : people_who_know) {
                std::cout << person;
            }
            */
            std::cout << "\n";
        }

        std::vector<int> result{};
        for (auto const& person : people_who_know) {
            result.push_back(person);
        }
        return result;
    }
};

int main()
{
    Solution s{};
    std::vector<std::vector<int>> meetings = {{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}
    };
    s.findAllPeople(4, meetings, 3);
}
