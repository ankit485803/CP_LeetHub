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
    static constexpr int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    long long dfsSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }

    long long dfsProduct(TreeNode* root) {  //tc=O(n) visitedEachNode, sc=O(h) height of tee
        if (!root) return 0;

        long long leftSum = dfsProduct(root->left);
        long long rightSum = dfsProduct(root->right);
        long long currSum = root->val + leftSum + rightSum;

        long long product = currSum * (totalSum - currSum);
        maxProd = max(maxProd, product);

        return currSum;
    }


    int maxProduct(TreeNode* root) { 
        totalSum = dfsSum(root);     // First pass
        dfsProduct(root);            // Second pass
        return maxProd % MOD;
    }
};
