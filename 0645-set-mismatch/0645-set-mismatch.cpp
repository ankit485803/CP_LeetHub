class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  //tc=O(n), sc=o(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> err(2); // To store duplicate and missing number
        int missing = 1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                err[0] = nums[i]; // Duplicate number
            }
            
            // Check if the number is expected or missing
            if (nums[i] == missing) {
                missing++;
            }
        }
        
        // The missing number will be the last missing value
        err[1] = missing;

        return err;
    }
};
