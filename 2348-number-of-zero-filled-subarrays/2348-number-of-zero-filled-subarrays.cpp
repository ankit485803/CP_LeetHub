class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {  //tc=O(n), sc=O(1)
        long long total = 0;
        long long count = 0;

        for (int num : nums) {
            if (num == 0) {
                count++;  // Increment count for consecutive zeros
                total += count;  // Add the count of subarrays formed by the current block of zeros
            } else {
                count = 0;  // Reset count when a non-zero element is encountered
            }
        }

        return total;
    }
};
