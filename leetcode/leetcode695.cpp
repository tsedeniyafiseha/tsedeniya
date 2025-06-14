#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // BFS to calculate the area of each island
        auto bfs = [&](int startRow, int startCol) {
            int area = 0;
            queue<pair<int, int>> q;
            q.push({startRow, startCol});
            visited[startRow][startCol] = true;

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                area++;

                for (auto [dr, dc] : directions) {
                    int newRow = r + dr;
                    int newCol = c + dc;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }

            return area;
        };

        // Explore the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, bfs(i, j));
                }
            }
        }

        return maxArea;
    }
};
