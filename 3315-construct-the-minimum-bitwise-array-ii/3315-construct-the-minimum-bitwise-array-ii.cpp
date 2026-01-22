class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            if(num == 2) { // special case
                ans[i] = -1;
                continue;
            }

            bool isFound = false;

            for(int j = 0; j < 32; j++) { // iterate bits LSB → MSB
                if((num & (1 << j)) > 0) { // set bit → skip
                    continue;
                }
                // Found first 0 bit at position j
                int x = num ^ (1 << (j - 1)); // flip previous bit
                ans[i] = x;
                isFound = true;
                break;
            }

            if(!isFound) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};
