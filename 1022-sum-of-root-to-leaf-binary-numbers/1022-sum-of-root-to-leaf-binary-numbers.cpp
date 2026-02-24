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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int curr) { //tc=O(n), sc=O(heightTree)
        if (!node) return 0;
        
        // Shift left and add current node value
        curr = (curr << 1) | node->val;
        
        // If leaf node, return the binary number
        if (!node->left && !node->right) {
            return curr;
        }
        
        // Recurse left and right
        return dfs(node->left, curr) + 
               dfs(node->right, curr);
    }
};