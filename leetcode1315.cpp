//leetcode 1315 sum of nodes with even valued grandparent
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (!node) return 0;

        int sum = 0;

        // Add current node's value if grandparent exists and is even
        if (grandparent && grandparent->val % 2 == 0) {
            sum += node->val;
        }

        // Recurse on left and right children
        sum += dfs(node->left, node, parent);
        sum += dfs(node->right, node, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};
