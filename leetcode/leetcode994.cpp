#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Cell {
        int row, col, time;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<Cell> bfsQueue;
        int freshCount = 0;
        int maxTime = 0;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Step 1: Initialize the graph with rotten oranges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    bfsQueue.push({r, c, 0});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        // Step 2: BFS to simulate rotting process
        while (!bfsQueue.empty()) {
            auto [r, c, time] = bfsQueue.front(); bfsQueue.pop();
            maxTime = max(maxTime, time);

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Check bounds and if the neighbor is a fresh orange
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;  // Rot it
                    freshCount--;      // One less fresh orange
                    bfsQueue.push({nr, nc, time + 1});
                }
            }
        }

        // Step 3: If any fresh orange remains, return -1
        return freshCount == 0 ? maxTime : -1;
    }
};
