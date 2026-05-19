
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {  //TC=O(m+n), sc=O(1)
        int i = 0, j = 0;

        //twoPointerApproach
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];  // Found the smallest common value
            }
            else if (nums1[i] < nums2[j]) {
                i++;  // Move forward in nums1
            }
            else {
                j++;  // Move forward in nums2
            }
        }

        return -1;  // No common element found
    }
};
