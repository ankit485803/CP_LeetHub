class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());   //using c++ STL tc=O(logN), sc=O(1)

        return min;
    }
};