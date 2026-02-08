class Solution {
public:
    int dominantIndices(vector<int>& nums) {  //tc=O(n^2) working because size 100 sc=O(1)
        int n = nums.size();
        int count = 0;  //which count dominant Idx

        for(int i=0; i<n-1; i++) {  //last rightmost not dominant
            int sum = 0;
            int element = n-i-1;

            for(int j=i+1; j<n; j++) {
                sum += nums[j];
            }

            double avg = (double)sum / element;

            if(nums[i] > avg) {
                count++;
            }
        }

        return count;
    }
};