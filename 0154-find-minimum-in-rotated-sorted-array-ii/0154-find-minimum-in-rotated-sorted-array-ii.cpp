class Solution {
public:
    int findMin(vector<int>& nums) {  //tc=O(n) dueToDuplicate even used BS, sc=O(1)
        int n = nums.size();
        
        int l = 0, r = n-1;  //left right
        int resultIdx = 0;

        while(l <= r) {

            while(l < r && nums[l] == nums[l+1] ) l++;
            while(r > l && nums[r] == nums[r - 1] ) r--;

            int mid = l + (r - l)/2;
            
            if(nums[mid] < nums[resultIdx]) {
                resultIdx = mid;
            }

            if(nums[mid] > nums[r]) {  //rotated
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return nums[resultIdx];
    }
};