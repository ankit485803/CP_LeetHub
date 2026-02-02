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
    string smallestFromLeaf(TreeNode* root) {
        string path;
        string ans = "";   // empty means not set yet
        dfs(root, path, ans);
        return ans;
    }

    void dfs(TreeNode* node, string& path, string& ans) {
        if (!node) return;

        // add current character
        path.push_back('a' + node->val);

        // if leaf node
        if (!node->left && !node->right) {
            string leafToRoot = path;
            reverse(leafToRoot.begin(), leafToRoot.end());

            if (ans.empty() || leafToRoot < ans) {
                ans = leafToRoot;
            }
        }

        dfs(node->left, path, ans);
        dfs(node->right, path, ans);

        // backtrack
        path.pop_back();
    }
};
