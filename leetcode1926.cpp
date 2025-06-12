//leetcode 1926 nearest exit from entrance in maze
#include <vector>
#include <queue>
using namespace std;

// Struct to store BFS state: row, col, and current distance
struct State {
    int row, col, steps;
};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<State> q;

        // Start BFS from all valid neighbors of the entrance (not entrance itself)
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        int startRow = entrance[0];
        int startCol = entrance[1];
        maze[startRow][startCol] = '+';  // mark entrance as visited

        // Push all adjacent open cells to queue
        for (const auto& [dx, dy] : directions) {
            int newRow = startRow + dx;
            int newCol = startCol + dy;
            if (isInBounds(newRow, newCol, rows, cols) && maze[newRow][newCol] == '.') {
                q.push({newRow, newCol, 1});
                maze[newRow][newCol] = '+';  // mark as visited
            }
        }

        while (!q.empty()) {
            auto [r, c, dist] = q.front(); q.pop();

            // If it's an exit cell on the border (excluding entrance), return the distance
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                return dist;

            for (const auto& [dx, dy] : directions) {
                int nr = r + dx;
                int nc = c + dy;
                if (isInBounds(nr, nc, rows, cols) && maze[nr][nc] == '.') {
                    q.push({nr, nc, dist + 1});
                    maze[nr][nc] = '+';  // mark visited
                }
            }
        }

        return -1;  // No exit found
    }

private:
    // Helper to check if cell is inside maze bounds
    bool isInBounds(int r, int c, int maxRows, int maxCols) {
        return r >= 0 && r < maxRows && c >= 0 && c < maxCols;
    }
};
