class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        
        //Step1: Calculate suffixMin arr
        vector<long long> suffixMin(n);
        suffixMin[n-1] = (long long)INT_MAX;  // Use max int value to represent "out of bound" value

        // Fill the suffixMin array (min from the right)
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min((long long)nums[i + 1], suffixMin[i + 1]);
        }

        //Step2: Calculate the maxScore
        long long prefixSum = 0;
        long long maxScore = (long long)INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            long long score = prefixSum - suffixMin[i];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
