class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        // Base case for 1 row
        long long dp = 12;  // 12 ways to paint a 1 x 3 grid
        
        for (int i = 2; i <= n; ++i) {
            dp = (dp * 6) % MOD;
        }
        
        return dp;
    }
};
