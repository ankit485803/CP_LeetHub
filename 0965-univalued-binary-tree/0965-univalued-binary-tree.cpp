/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    bool dfs(TreeNode* node, int value) {
        if (node == NULL) return true;

        if (node->val != value) return false;

        return dfs(node->left, value) && dfs(node->right, value);
    }

    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};
