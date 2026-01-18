class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        vector<int> freq(1001, 0);
        int maxCount = 0;
        int result = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                freq[nums[i + 1]]++;
                if (freq[nums[i + 1]] > maxCount) {
                    maxCount = freq[nums[i + 1]];
                    result = nums[i + 1];
                }
            }
        }
        return result;
    }
};
