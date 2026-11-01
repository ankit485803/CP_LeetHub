class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int minElem = INT_MAX;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            minElem = min(minElem, nums[i]);  //reassign minElem
        }

        return sum - n*minElem;  //mainLogic
    }
};