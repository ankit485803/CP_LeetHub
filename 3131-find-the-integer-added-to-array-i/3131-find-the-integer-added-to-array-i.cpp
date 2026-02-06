class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {  //tc=O(logN), sc=O(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return nums2[0] - nums1[0];   //diff of any crosspondingIdx
    }
};