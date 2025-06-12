#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        // Build adjacency list: bomb i -> all bombs j it can detonate
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            long long rSquared = r * r;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = x1 - bombs[j][0];
                long long dy = y1 - bombs[j][1];
                long long distSquared = dx * dx + dy * dy;

                if (distSquared <= rSquared) {
                    graph[i].push_back(j);
                }
            }
        }

        int maxDetonated = 0;
        for (int i = 0; i < n; i++) {
            int detonatedCount = bfs(i, graph);
            maxDetonated = max(maxDetonated, detonatedCount);
        }

        return maxDetonated;
    }

private:
    int bfs(int start, const vector<vector<int>>& graph) {
        int count = 0;
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return count;
    }
};
