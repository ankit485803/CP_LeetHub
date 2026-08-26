class Solution {
public:
    //T.C -> O(N);
    //S.C -> O(1);
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        
        while(right<n){
            if(nums[right]!=0){
                swap(nums[right], nums[left]);
                left++;
            }
            right++;
        }
    }
};