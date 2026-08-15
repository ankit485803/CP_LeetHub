class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Base case: all elements are 0
        bool allZero = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) return 0;


        
        // Main logic: compute XOR of all elements
        int xorAll = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorAll ^= nums[i];
        }

        //condition
        if (xorAll != 0) {
            return nums.size();
        } else {
            return nums.size() - 1;
        }
    }
};

//TC=o(n), sc-O(1)