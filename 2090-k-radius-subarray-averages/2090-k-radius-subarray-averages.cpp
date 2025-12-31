class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avg(n, -1);

        // Special case
        if (k == 0) return nums;

        int windowSize = 2 * k + 1;
        if (windowSize > n) return avg;

        long long windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }

        // Center of first window is index k
        avg[k] = windowSum / windowSize;

        // Slide the window
        for (int i = windowSize; i < n; i++) {
            windowSum += nums[i];
            windowSum -= nums[i - windowSize];

            int center = i - k;
            avg[center] = windowSum / windowSize;
        }

        return avg;
    }
};
