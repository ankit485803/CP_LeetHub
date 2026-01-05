class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {  //tcO(n*n), sc=O(1)
        long long totalSum = 0;  
        long long minAbsVal = LONG_MAX;  
        int negativeCount = 0; 
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int num = matrix[i][j];
                totalSum += abs(num);
                minAbsVal = min(minAbsVal, (long long)abs(num));  // Cast abs(num) to long long
                if (num < 0) {
                    negativeCount++;
                }
            }
        }
        
        // If we have an odd count of negative numbers, one negative number must remain
        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsVal;
        }
        
        return totalSum;
    }
};
