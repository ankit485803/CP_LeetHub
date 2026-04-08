class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7; // modulus to avoid overflow during multiplication

        // Process each query one by one
        for (auto &q : queries) {
            int li = q[0]; // left index of range
            int ri = q[1]; // right index of range
            int ki = q[2]; // step size
            int vi = q[3]; // multiplier value

            // Update every ki-th index in range [li, ri]
            for (int idx = li; idx <= ri; idx += ki) {
                // Use 1LL to promote to long long before multiplication
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }

        // After applying all queries, calculate XOR of entire array
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};



// TC=O(n * query), SC=O(1) 