class Solution {
public:
    int absDifference(vector<int>& nums, int k) {  //tc=O(n logN), sc=O(1)
        int n = nums.size();
        //step1: sorting
        sort(nums.begin(), nums.end());  //O(logN)

        //step2: calculate min max 
        int minSum = 0;
        int maxSum = 0;

        for(int i=0; i<k; i++) {  //fromStarting till k-1
            minSum += nums[i];
        }
        for(int i=n-1; i>=n-k; i--) {  //rev ORDER
            maxSum += nums[i];
        }

        //step3: abs Diff
        return abs(maxSum - minSum);
        
    }
};