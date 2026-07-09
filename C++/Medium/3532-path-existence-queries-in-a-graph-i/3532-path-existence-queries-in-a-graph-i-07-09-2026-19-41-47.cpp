// Approach: Linear component labeling in one pass, then compare labels.
// Time: O(n + q)   Space: O(n)
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        // comp[0] = 0;                           // first node anchors component 0 (vector already zero-initialized)

        for (int i = 1; i < n; ++i) {            // O(n)
            int diff = abs(nums[i] - nums[i - 1]);
            if (diff <= maxDiff)
                comp[i] = comp[i - 1];           // connected -> inherit previous label
            else
                comp[i] = i;                     // gap too big -> start a new component
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int node1 = queries[i][0], node2 = queries[i][1];
            if (comp[node1] == comp[node2])
                ans[i] = true;                   // same label -> same component -> reachable
        }
        return ans;
    }
};
