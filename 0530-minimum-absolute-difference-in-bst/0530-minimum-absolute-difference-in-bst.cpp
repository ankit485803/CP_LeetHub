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

    TreeNode* prev = NULL;

    int getMinimumDifference(TreeNode* root) {

        if(root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;
        if(root->left  !=  NULL) {
            int leftMin = getMinimumDifference(root->left);
            ans = min(ans, leftMin); 
        }

        //calculate currMin
        if(prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        //same thing for right wale ke liye
        if(root->right  !=  NULL) {
            int rightMin = getMinimumDifference(root->right);
            ans = min(ans, rightMin); 
        }

        return ans;
    }
};


// TC = O(n)= SC