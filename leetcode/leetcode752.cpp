// LeetCode 752. Open the Lock
// https://leetcode.com/problems/open-the-lock/

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    // Generates all valid next combinations from current combination
    vector<string> getNextStates(const string& state) {
        vector<string> neighbors;
        for (int i = 0; i < 4; ++i) {
            string up = state, down = state;
            
            // Turn the wheel one step forward
            up[i] = (state[i] - '0' + 1) % 10 + '0';
            // Turn the wheel one step backward
            down[i] = (state[i] - '0' + 9) % 10 + '0';

            neighbors.push_back(up);
            neighbors.push_back(down);
        }
        return neighbors;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocked(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        string start = "0000";
        if (blocked.count(start)) return -1;

        q.push(start);
        visited.insert(start);
        int steps = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                string current = q.front(); q.pop();
                if (current == target) return steps;

                for (const string& next : getNextStates(current)) {
                    if (!blocked.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1; // Target is unreachable
    }
};
