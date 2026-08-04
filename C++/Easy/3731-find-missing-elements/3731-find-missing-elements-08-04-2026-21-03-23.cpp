class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {  //tc=O(logN + totalElem), sc=O(1)
        sort(nums.begin(), nums.end());

        int curr = nums[0];
        vector<int> ans;

        for(int i=0; i < nums.size(); ) {
            if(curr < nums[i]) {
                ans.push_back(curr);
            } else {
                i++;
            }
            curr++;
        }

        return ans;
    }
};