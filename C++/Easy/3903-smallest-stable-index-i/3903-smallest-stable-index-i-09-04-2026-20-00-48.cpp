class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {  //tc=O(n^2), sc=O(1) using bruteForce
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxElem = INT_MIN;
            int minElem = INT_MAX;

            // max(nums[0..i])
            for (int j = 0; j <= i; j++) {
                maxElem = max(maxElem, nums[j]);
            }

            // min(nums[i..n-1])
            for (int j = i; j < n; j++) {
                minElem = min(minElem, nums[j]);
            }

            // instability score <= k
            if (maxElem - minElem <= k) {
                return i;
            }
        }

        return -1;
    }
};
