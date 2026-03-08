class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {  //tc=O(n)=sc
        int n = nums.size();
        string res = "";

        //approach: clever trick called “diagonalization”, inspired by Cantor’s diagonal argument.

        for (int i = 0; i < n; ++i) {
            res += (nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};