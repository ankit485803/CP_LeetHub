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
    long long kthLargestLevelSum(TreeNode* root, int k) { //tc=O(logN),sc=O(k)
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        // min-heap to keep k largest level sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (!q.empty()) {
            int sz = q.size();
            long long levelSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            pq.push(levelSum);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        if ((int)pq.size() < k) return -1;
        return pq.top();
    }
};
