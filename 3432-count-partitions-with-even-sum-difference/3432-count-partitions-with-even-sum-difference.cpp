class Solution {
public:
    int countPartitions(vector<int>& nums) { //tc=O(n), sc=O(1) using prefixSum
        int totalS = 0;  
        int leftS = 0;    
        int count = 0; 

    
        for (int num : nums) {
            totalS += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftS += nums[i]; 
            int rightS = totalS - leftS;  

            // Check if diff is even
            if ((leftS - rightS) % 2 == 0) {
                count++;  
            }
        }

        return count;  
    }
};
