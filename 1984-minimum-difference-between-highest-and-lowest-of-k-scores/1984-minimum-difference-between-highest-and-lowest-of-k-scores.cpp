class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) { //tc=O(nlogN), sc=O(1)
        if(k == 1) return 0;

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for(int i=0; i+k-1 < nums.size(); i++) {   //sliddingWindow approach
            ans = min(ans, nums[i+k-1] - nums[i]);
        }

        return ans;
    }
};