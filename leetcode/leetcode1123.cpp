#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        // Queue stores pairs of node and its parent
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        // Maps node value to parent node value and value to node pointer
        vector<TreeNode*> valToNode(1001, nullptr);
        vector<int> parent(1001, -1);

        int leftMost = -1, rightMost = -1;

        // BFS traversal level by level
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto [node, parNode] = q.front();
                q.pop();

                int val = node->val;
                valToNode[val] = node;
                parent[val] = parNode ? parNode->val : -1;

                if (i == 0) leftMost = val;         // leftmost node at this level
                if (i == levelSize - 1) rightMost = val;  // rightmost node at this level

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
        }

        // If only one deepest leaf exists, return it
        if (leftMost == rightMost) {
            return valToNode[leftMost];
        }

        // Move up the parents until the two nodes meet (LCA)
        int s = leftMost, t = rightMost;
        while (s != t) {
            s = parent[s];
            t = parent[t];
        }

        return valToNode[s];
    }
};
