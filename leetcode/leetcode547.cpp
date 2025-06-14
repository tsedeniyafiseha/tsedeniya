#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Depth-First Search to mark all cities in the same province
    void dfs(int city, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int city = 0; city < n; ++city) {
            if (!visited[city]) {
                dfs(city, isConnected, visited);  // or use bfs(city, isConnected, visited)
                provinces++;
            }
        }

        return provinces;
    }

    // Optional: Breadth-First Search alternative
    void bfs(int city, const vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(city);
        visited[city] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
                if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};
