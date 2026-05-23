class Solution {
public:
    bool check(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int countD = 0; //no of drop
        int n = nums.size();

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                countD++;
            }
        }

        return countD <= 1;
    }
};