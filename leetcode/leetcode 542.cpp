// LeetCode 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Stores the result distances
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

        // Movement directions: up, down, left, right
        const vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // BFS queue: stores (row, col)
        queue<pair<int, int>> q;

        // Start from all 0-cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Skip out-of-bound cells
                if (newX < 0 || newX >= rows || newY < 0 || newY >= cols)
                    continue;

                // If this neighbor can be improved
                if (distance[newX][newY] > distance[x][y] + 1) {
                    distance[newX][newY] = distance[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return distance;
    }
};
