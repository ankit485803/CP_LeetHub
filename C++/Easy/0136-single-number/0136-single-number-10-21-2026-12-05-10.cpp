class Solution {
public:
    int singleNumber(vector<int>& nums) { //tc=O(n), sc=O(1)
        int ans = 0;

        //prop of bitwise XOR operator: A^A = 0, A^0=1

        for(int num : nums) {
            ans = ans ^ num;
        }

        return ans; 
    }
};