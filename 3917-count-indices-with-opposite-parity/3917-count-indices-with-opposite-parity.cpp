class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {  //tc=O(n^2) using evenCount, oddCount
        int n = nums.size();
        vector<int> ans(n, 0); //sc=O(n)

        for(int i=0; i<n; i++) {
            int count = 0; 
            for(int j = i+1; j<n; j++) {
                if(nums[i] % 2 != nums[j] % 2) {
                    count++;
                }
            }
            ans[i] = count;
        }

        return ans;
    }
};