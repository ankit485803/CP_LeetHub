class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> freq;  //sc=O(n)
        int maxCount = 0;
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {  //tc=O(n)
            if(nums[i] == key) {
                freq[nums[i+1]]++;

            }
            if(freq[nums[i+1]] > maxCount) {
                maxCount = freq[nums[i+1]];
                ans = nums[i+1];
            }
        }

        return ans;
    }
};