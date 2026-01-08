class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {  //LCS style DP
        int n = nums1.size(), m = nums2.size();
        const int NEG_INF = -1e9;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {  //tc=O(n * m)=sc
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                dp[i][j] = max({
                    prod,                       // start new subsequence
                    dp[i - 1][j - 1] + prod,    // extend previous
                    dp[i - 1][j],               // skip nums1 element
                    dp[i][j - 1]                // skip nums2 element
                });
            }
        }

        return dp[n][m];
    }
};
