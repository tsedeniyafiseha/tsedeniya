#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        // Directions for exploring neighbors: up, down, left, right
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Track visited cells to avoid re-processing
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        queue<pair<int,int>> q;

        // Push all 'O's on the border into the queue and mark them visited
        for (int r = 0; r < rows; r++) {
            for (int c : {0, cols-1}) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }
        for (int c = 0; c < cols; c++) {
            for (int r : {0, rows-1}) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }

        // BFS to mark all 'O's connected to border 'O's as safe
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols 
                    && board[nx][ny] == 'O' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // Flip all 'O's not visited (not connected to border) to 'X'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
