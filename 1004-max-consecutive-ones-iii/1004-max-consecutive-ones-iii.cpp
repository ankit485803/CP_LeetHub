class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxFlip = 0;
        int maxLeng = 0;
        int i = 0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[j] == 0) {
                maxFlip++;
            }
            while(maxFlip > k) {
                if(nums[i] == 0) {
                    maxFlip--;
                }
                i++;
            }
            maxLeng = max(maxLeng, j-i+1);
        }

        return maxLeng;
    }
};