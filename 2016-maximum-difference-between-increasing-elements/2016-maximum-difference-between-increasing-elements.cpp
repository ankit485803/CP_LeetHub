class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //twoPointer
        int maxDiff = -1;  //initilize

        for(int i=0; i<nums.size(); i++) {   //O(N^2) due to nestedLoop
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] < nums[j]) {
                    int diff = nums[j] - nums[i];
                    maxDiff = max(diff, maxDiff);
                }
            }
        }

        return maxDiff;
    }
};