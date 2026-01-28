class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {  //tc=O(n), sc=O(1)
        int mx = *max_element(nums.begin(), nums.end());
        int sum = 0;

        for(int i=0; i<k; i++) {
            sum += mx;
            mx++;
        }

        return sum;
    }
};