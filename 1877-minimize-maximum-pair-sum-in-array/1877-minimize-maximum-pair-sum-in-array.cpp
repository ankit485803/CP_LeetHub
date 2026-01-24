class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;   //smaller
        int j = nums.size() - 1;  //larger
        int ans = 0;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};
