class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 1;
        int count = 0;

        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }

            long diff = (long)nums[j] - nums[i];

            if (diff < k) {
                j++;
            } 
            else if (diff > k) {
                i++;
            } 
            else { // diff == k
                count++;

                int leftVal = nums[i];
                int rightVal = nums[j];

                // skip duplicates
                while (i < n && nums[i] == leftVal) i++;
                while (j < n && nums[j] == rightVal) j++;
            }
        }

        return count;
    }
};
