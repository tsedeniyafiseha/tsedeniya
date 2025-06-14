#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        queue<pair<int, int>> bfsQueue;
        int waterCells = 0;

        // Enqueue all land cells and count water cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    bfsQueue.push({i, j});
                } else {
                    waterCells++;
                }
            }
        }

        // If there is no water or no land, return -1
        if (waterCells == 0 || waterCells == rows * cols)
            return -1;

        int distance = -1;

        // BFS from all land cells outward to water
        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();
            distance++;

            for (int i = 0; i < levelSize; ++i) {
                auto [x, y] = bfsQueue.front(); bfsQueue.pop();

                for (const auto& [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;

                    // Skip if out of bounds or already visited
                    if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] != 0)
                        continue;

                    // Mark visited and enqueue
                    grid[newX][newY] = 2;
                    bfsQueue.push({newX, newY});
                }
            }
        }

        return distance;
    }
};
