// leetcode 129 sum root to leaf numbers
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        current = current * 10 + node->val;

        // If it's a leaf node, return the number formed
        if (!node->left && !node->right)
            return current;

        // Recurse on both children
        int leftSum = dfs(node->left, current);
        int rightSum = dfs(node->right, current);

        return leftSum + rightSum;
    }
};

