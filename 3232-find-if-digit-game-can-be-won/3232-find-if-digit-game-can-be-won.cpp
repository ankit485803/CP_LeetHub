class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleD = 0;  //digit single
        int doubleD = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 10) {
                singleD += nums[i];
            } else {
                doubleD += nums[i];
            }
        }
        if(singleD == doubleD) {
            return false;   //aliceShikha wins
        }
        return true;  //bobBanti 
    }
};