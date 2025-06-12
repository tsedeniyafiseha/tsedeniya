//leetcode 909 snakes and ladders 
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // Converts board coordinates (i,j) to board index (1-based)
        auto getSquare = [&](int index) -> pair<int, int> {
            int row = (index - 1) / n;
            int col = (index - 1) % n;
            if (row % 2 == 1)
                col = n - 1 - col;
            return {n - 1 - row, col};
        };

        // BFS initialization
        queue<pair<int, int>> q;  // {position, moves}
        vector<bool> visited(n * n + 1, false);
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front(); q.pop();
            if (curr == n * n) return steps;

            for (int dice = 1; dice <= 6 && curr + dice <= n * n; ++dice) {
                int next = curr + dice;
                auto [r, c] = getSquare(next);
                if (board[r][c] != -1) next = board[r][c];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};
