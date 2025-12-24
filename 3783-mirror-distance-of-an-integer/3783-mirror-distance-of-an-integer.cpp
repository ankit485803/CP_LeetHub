class Solution {
public:
    int mirrorDistance(int n) { //sc=O(1)
        //step1: Rev 
        int R = 0;
        int original = n;
        
        // ReverseNum - tc=O(n)
        while (n > 0) {
            R = R * 10 + (n % 10);  // Get the last digit and add it to R
            n /= 10;  // Remove the last digit from n
        }

        //step2: calculateDiff
        int diff = original - R;

        return abs(diff);
    }
};
