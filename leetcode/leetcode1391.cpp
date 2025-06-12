//leetcode 1391 check if there is a valid path in a grid with streets
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // If starting cell is invalid
        if (n == 0 || m == 0) return false;
        
        // BFS queue: {row, col}
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        // Directions: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        // Valid connections for each street type (1-6) for [right, left, down, up]
        vector<vector<bool>> connections = {
            {}, // No street type 0
            {true, true, false, false},  // Type 1: left-right
            {false, false, true, true},  // Type 2: up-down
            {false, true, true, false},  // Type 3: left-down
            {true, false, true, false},  // Type 4: right-down
            {false, true, false, true},  // Type 5: left-up
            {true, false, false, true}   // Type 6: right-up
        };
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Reached destination
            if (x == n-1 && y == m-1) return true;
            
            // Try all four directions
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                // Check if next cell is valid and unvisited
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    // Check if current cell allows moving in direction d
                    if (connections[grid[x][y]][d]) {
                        // For the move to be valid, the next cell must allow the opposite direction
                        int opp_dir = (d % 2 == 0) ? d + 1 : d - 1; // Opposite: right<->left, down<->up
                        if (connections[grid[nx][ny]][opp_dir]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};