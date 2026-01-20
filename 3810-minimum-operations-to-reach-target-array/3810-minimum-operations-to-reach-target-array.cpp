class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {  //tc=O(n)=sc
        unordered_set<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                ans.insert(nums[i]);
            }
        }

        return ans.size();
    }
};
