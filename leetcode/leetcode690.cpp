//leetcode 690 employement importance
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for Employee
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    // Graph: maps employee id to the Employee pointer
    unordered_map<int, Employee*> graph;

    // Recursive DFS to sum up importance
    int dfs(int id) {
        Employee* emp = graph[id];
        int total = emp->importance;
        for (int subId : emp->subordinates) {
            total += dfs(subId);
        }
        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        // Step 1: Build the graph
        for (Employee* emp : employees) {
            graph[emp->id] = emp;
        }

        // Step 2: Start DFS from given id
        return dfs(id);
    }
};
