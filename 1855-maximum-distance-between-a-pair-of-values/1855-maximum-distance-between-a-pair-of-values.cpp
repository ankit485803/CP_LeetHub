class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        //takePointerApproach tc=O(n + m), sc=O(1)

        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j] ) {  //validPair condition
                ans = max(ans, j - i);
                j++;  //try to maximize dist
            } else {
                i++;  //needSmaller nums1[i]
            }
        }

        return ans;
    }
};