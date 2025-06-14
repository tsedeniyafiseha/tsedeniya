#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> inorderValues;
    int index = 0;

    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        inorderValues.push_back(node->val);
        inorderTraversal(node->right);
    }

    void restoreTree(TreeNode* node) {
        if (!node) return;
        restoreTree(node->left);
        node->val = inorderValues[index++];
        restoreTree(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Step 1: Collect node values via inorder traversal
        inorderTraversal(root);
        
        // Step 2: Sort the collected values to get the correct order
        sort(inorderValues.begin(), inorderValues.end());
        
        // Step 3: Reassign sorted values back to the tree by inorder traversal
        restoreTree(root);
    }
};
