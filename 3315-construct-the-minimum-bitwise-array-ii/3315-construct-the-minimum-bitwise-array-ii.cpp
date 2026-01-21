class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            int a = -1;
            for (int i = 0; i <= x; ++i) {
                if ((i | (i + 1)) == x) {
                    a = i;
                    break; // take the smallest
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
