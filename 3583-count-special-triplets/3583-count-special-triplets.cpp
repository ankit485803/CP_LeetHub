class Solution {
public:
    int specialTriplets(vector<int>& nums) {  //tc=O(n)
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;   //sc=O(n)

        // Fill right freqMap
        for (int x : nums) {
            right[x]++;
        }

        long long ans = 0;

        // j is the middle index
        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;  // remove current j from right side

            int target = mid * 2;
            if (left.count(target) && right.count(target)) {
                ans = (ans + left[target] * right[target]) % MOD;
            }

            left[mid]++;   //add current j to left side
        }

        return ans;
    }
};
