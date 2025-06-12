//1765: Map of Highest Peak
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        // Queue for BFS: holds all water cells as starting points
        queue<pair<int, int>> bfsQueue;

        // Initialize: water cells = height 0, land = -1 (unvisited)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    bfsQueue.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // BFS from all water cells
        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front(); bfsQueue.pop();

            for (const auto& [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // If inside grid and unvisited land
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && isWater[nx][ny] == -1) {
                    isWater[nx][ny] = isWater[x][y] + 1; // height = parent's height + 1
                    bfsQueue.push({nx, ny});
                }
            }
        }

        return isWater;
    }
};
