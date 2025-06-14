#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();

        // Map each stop to the list of routes passing through it
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        // Build graph: nodes are routes, edges between routes sharing at least one stop
        vector<vector<int>> graph(n);
        for (auto& [stop, routeList] : stopToRoutes) {
            for (int i = 0; i < (int)routeList.size(); ++i) {
                for (int j = i + 1; j < (int)routeList.size(); ++j) {
                    int r1 = routeList[i], r2 = routeList[j];
                    graph[r1].push_back(r2);
                    graph[r2].push_back(r1);
                }
            }
        }

        // Identify routes containing source and target stops
        vector<int> sourceRoutes = stopToRoutes[source];
        vector<int> targetRoutes = stopToRoutes[target];
        unordered_set<int> targetSet(targetRoutes.begin(), targetRoutes.end());

        // BFS initialization from all source routes
        queue<int> q;
        vector<bool> visited(n, false);
        for (int r : sourceRoutes) {
            q.push(r);
            visited[r] = true;
        }

        int busesTaken = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int currRoute = q.front();
                q.pop();

                if (targetSet.count(currRoute)) {
                    return busesTaken;
                }

                for (int neigh : graph[currRoute]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            ++busesTaken;
        }

        return -1;  // No route found
    }
};

int main() {
    Solution sol;

    // Example routes: each subvector represents stops on a bus route
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7}
    };
    int source = 1;
    int target = 6;

    int result = sol.numBusesToDestination(routes, source, target);
    cout << "Minimum number of buses needed: " << result << endl;

    return 0;
}
