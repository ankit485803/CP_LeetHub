class Solution {
public:
    int minOperations(vector<int>& nums, int k) {  //tc=O(n), sc=O(k)
        int n = nums.size(); 

        vector<bool> seen(k, false);  // Boolean array to track collected elements
        int collected = 0;  
        int ops = 0;  

    
        for (int i=n-1; i>=0; i--) {
            ops++;
            
            int val = nums[i];
            
            // If the element is in the range [1, k] and hasn't been collected yet
            if (val <= k && !seen[val - 1]) {
                seen[val - 1] = true;  
                collected++;  
            }

            if (collected == k) {
                return ops;
            }
        }

        return ops;  
    }
};

