class Solution {
public:
    int specialArray(vector<int>& nums) { //tc=O(n logN), sc=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int x = 1; x <= n; ++x) {
            // Count how many elements are >= x
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            // If count is exactly x, return x
            if (count == x) {
                return x;
            }
        }
        
        return -1;
    }
};
