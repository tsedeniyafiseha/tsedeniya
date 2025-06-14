#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        
        // If clicked on a mine, mark it as 'X' and return immediately
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        // Otherwise, reveal the clicked cell recursively
        revealCell(board, x, y);
        return board;
    }

private:
    // Check if the given coordinates are inside the board boundaries
    bool isValid(const vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < (int)board.size() && y >= 0 && y < (int)board[0].size();
    }
    
    // Directions for the 8 neighbors (top-left, top, top-right, left, right, bottom-left, bottom, bottom-right)
    const vector<pair<int,int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };
    
    void revealCell(vector<vector<char>>& board, int x, int y) {
        if (!isValid(board, x, y) || board[x][y] != 'E') return;

        int mineCount = 0;

        // Count mines in adjacent cells
        for (auto& d : directions) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (isValid(board, nx, ny) && board[nx][ny] == 'M') {
                mineCount++;
            }
        }

        if (mineCount > 0) {
            // If adjacent mines exist, update current cell with the count
            board[x][y] = '0' + mineCount;
        } else {
            // If no adjacent mines, mark current as 'B' (blank)
            board[x][y] = 'B';

            // Recursively reveal all neighbors
            for (auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;
                revealCell(board, nx, ny);
            }
        }
    }
};
