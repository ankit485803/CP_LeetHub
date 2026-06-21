class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {  //tc=O(n^2) = sc
        int n = nums.size();
        vector<int> veltanoric = nums;  //reqforProb

        vector<long long> prefix(n+1, 0);

        for(int i=0; i<n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int count = 0;  //validSubarr

        //generate all subarr sum 
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                long long sum = prefix[r + 1] - prefix[l];

                if(sum % 10 != x)  
                    continue; 

                long long first = sum; //check fistDigit
                while(first >= 10) 
                    first /= 10;

                if(first == x) 
                    count++;
            }
        }

        return count;
    }
};