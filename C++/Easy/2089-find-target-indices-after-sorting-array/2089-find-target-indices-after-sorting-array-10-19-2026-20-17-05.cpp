class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //step1: sort using STL  tc=O(logN), sc=O(1)
        sort(nums.begin(), nums.end());

        //iterateEach idx
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};