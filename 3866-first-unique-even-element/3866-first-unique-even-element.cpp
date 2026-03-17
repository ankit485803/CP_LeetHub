class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {  //tc=O(n^2) dueToNestedLoop, sc=O(1)
            if(nums[i] % 2 == 0) {
                int freq = 0;

                for(int j=0; j<nums.size(); j++) {
                    if(nums[i] == nums[j]) {  //twoElem eq
                        freq++;
                    }
                }

                if(freq == 1) {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};