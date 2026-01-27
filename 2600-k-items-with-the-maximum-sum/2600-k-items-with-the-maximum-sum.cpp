class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {  //tc=O(1)=sc
        int maxSum = 0;
        if(k <= numOnes) return k;

        // Take all 1s
        maxSum += numOnes;
        k -= numOnes;

        // Take 0s if possible
        if(k <= numZeros) {
            return maxSum;
        }

        // Remaining must be -1s
        k -= numZeros;
        return maxSum - k;
    }
};
