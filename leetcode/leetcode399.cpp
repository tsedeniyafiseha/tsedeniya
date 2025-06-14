#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Graph: node → list of {neighbor, weight}
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string& current, const string& target, unordered_set<string>& visited, double value) {
        if (graph.find(current) == graph.end()) return -1.0;
        if (current == target) return value;

        visited.insert(current);

        for (auto& neighbor : graph[current]) {
            if (visited.count(neighbor.first)) continue;
            double result = dfs(neighbor.first, target, visited, value * neighbor.second);
            if (result != -1.0) return result;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double val = values[i];
            graph[a].emplace_back(b, val);
            graph[b].emplace_back(a, 1.0 / val);
        }

        // Step 2: Process each query using DFS
        vector<double> results;
        for (auto& query : queries) {
            const string& src = query[0];
            const string& dest = query[1];
            unordered_set<string> visited;
            double answer = dfs(src, dest, visited, 1.0);
            results.push_back(answer);
        }

        return results;
    }
};
