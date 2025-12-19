class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0; 

        //twoPointer
        int i = 0;
        int j = 0;
        while(i < nums1.size() &&  j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                int dist = j-i;
                maxDist = max(dist, maxDist);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};