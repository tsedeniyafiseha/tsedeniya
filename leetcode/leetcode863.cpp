/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        // Recursive function to collect nodes at a certain distance
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return -1;

            // If current node is the target
            if (node == target) {
                collect(node, k, result);  // collect all k-distance nodes downward
                return k - 1;
            }

            int left = dfs(node->left);
            if (left >= 0) {
                if (left == 0) result.push_back(node->val);
                else collect(node->right, left - 1, result);
                return left - 1;
            }

            int right = dfs(node->right);
            if (right >= 0) {
                if (right == 0) result.push_back(node->val);
                else collect(node->left, right - 1, result);
                return right - 1;
            }

            return -1;
        };

        dfs(root);
        return result;
    }

private:
    // Collects nodes that are 'distance' away from current node
    void collect(TreeNode* node, int distance, vector<int>& result) {
        if (!node || distance < 0) return;
        if (distance == 0) {
            result.push_back(node->val);
            return;
        }
        collect(node->left, distance - 1, result);
        collect(node->right, distance - 1, result);
    }
};
