class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        //after maths calculation: xorBeauty = num[0] ^ num[1] ^ num[2] ..... num[n-1]

        int ans = 0;
        for(int num : nums) {  //tc=O(n), sc=O(1)
            ans = ans ^ num;
        }
        return ans;
    }
};