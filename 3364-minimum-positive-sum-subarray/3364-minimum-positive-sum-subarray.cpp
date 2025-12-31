class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        // Try all subarrays with length in [l, r]
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r; len++) {
                if (i + len > n) break;

                int sum = prefix[i + len] - prefix[i];
                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
