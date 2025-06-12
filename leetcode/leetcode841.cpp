//leetcode841. Keys and Rooms
#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search to explore reachable rooms
    void explore(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;
        for (int key : rooms[room]) {
            if (!visited[key]) {
                explore(key, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        vector<bool> visited(totalRooms, false);

        // Start DFS from room 0
        explore(0, rooms, visited);

        // Check if all rooms were visited
        for (bool roomVisited : visited) {
            if (!roomVisited) return false;
        }

        return true;
    }
};
