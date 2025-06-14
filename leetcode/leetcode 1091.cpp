// LeetCode 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Quick rejection for blocked start or end
        if (n == 0 || grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // All 8 possible directions: vertical, horizontal, and diagonal
        const vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        // BFS initialization
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({0, 0});
        grid[0][0] = 1; // mark as visited and start distance

        while (!bfsQueue.empty()) {
            auto [row, col] = bfsQueue.front(); bfsQueue.pop();
            int distance = grid[row][col];

            // Reached destination
            if (row == n - 1 && col == n - 1)
                return distance;

            // Explore all valid neighbors
            for (const auto& [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                // Skip if out of bounds or blocked
                if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 0)
                    continue;

                // Visit and enqueue
                grid[r][c] = distance + 1;
                bfsQueue.push({r, c});
            }
        }

        return -1; // No path found
    }
};
