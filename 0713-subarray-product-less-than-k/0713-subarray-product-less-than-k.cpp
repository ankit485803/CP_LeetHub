class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // If k is 0 or 1,  edgeCase

        int i = 0, ans = 0;
        long long prod = 1;

        for (int j = 0; j < nums.size(); j++) {
            prod *= nums[j];  

            // Shrink the window until the product is less than k.
            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            // Count the number of subarrays ending at j.
            ans += j - i + 1;
        }

        return ans;
    }
};
