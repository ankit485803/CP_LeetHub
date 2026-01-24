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

    int ans = 0;
    int height(TreeNode* root) {  //TC=O(n)
        if(root == NULL) {
            return 0;
        }

        int leftHt = height(root->left);  //height using recurssion
        int rightHt = height(root->right);
        
        ans = max(ans, leftHt + rightHt); //currDiam of root node
        return max(leftHt, rightHt) + 1;
    }





    int diameterOfBinaryTree(TreeNode* root) {  //O(n * n) because hm again height calculate kar rahe hai

        height(root);
        return ans;
    }
};


/*
Time Complexity: O(n) → Every node visited once.
Space Complexity: O(h) → Height of recursion stack (in worst-case O(n) for skewed tree).
*/