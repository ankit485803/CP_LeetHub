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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);

    }

private: 
    int dfs(TreeNode* root, int curr) {  //tc=O(n), sc=O(h) due to recussiveStack
        if(!root) return 0;

        curr = curr * 10 + root->val;
        //if leafNode
        if(!root->left && !root->right) {
            return curr;
        }

        return dfs(root->left, curr) + dfs(root->right, curr);
    }


};