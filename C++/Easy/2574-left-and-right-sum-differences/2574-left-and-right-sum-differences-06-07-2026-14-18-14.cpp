class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {  //tc=O(n^2), sc=O(1) bruteForce
        int n = nums.size();
        vector<int> ans(n);  //take arr with n sized

        for(int i=0; i<n; i++) {
            int leftSum = 0, rightSum = 0;

            //leftSide
            for(int j=0; j < i; j++) {
                leftSum += nums[j];
            }

            //rightSide
            for(int j = i+1; j<n; j++) {
                rightSum += nums[j];
            }

            ans[i] = abs(leftSum - rightSum);
        }

        return ans;

    }
};