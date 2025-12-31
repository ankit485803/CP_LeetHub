class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;  // Start index of the window
        int j = 0;  

        double maxAvg = -DBL_MAX;  // Initialize maxAvg with a very small value
        double currSum = 0;  

        while (j < nums.size()) {
            currSum += nums[j];  

            // If the window size is less than k, expand the window
            if (j - i + 1 < k) {
                j++;
            } else {
                // When the window size becomes equal to k, calculate the average
                maxAvg = max(maxAvg, currSum / k);
                currSum -= nums[i];
                i++;  
                j++;  
            }
        }

        return maxAvg;
    }
};
