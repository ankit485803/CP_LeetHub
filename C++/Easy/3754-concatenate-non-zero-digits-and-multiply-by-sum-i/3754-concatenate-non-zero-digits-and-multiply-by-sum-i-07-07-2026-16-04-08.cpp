class Solution {
public:
    long long sumAndMultiply(int n) {   //TC=O(n, digits)
        long long x = 0;  
        int sum = 0;   


        if (n == 0) {
            return 0; 
        }

        vector<int> nonZeroDigits;


        while (n > 0) {
            int digit = n % 10;  // Get the last digit of n
            n /= 10;             // Remove the last digit from n

            if (digit != 0) {    
                nonZeroDigits.push_back(digit); 
                sum += digit;            
            }
        }

        // Build x by concatenating digits in the correct order
        for (int i = nonZeroDigits.size() - 1; i >= 0; --i) {
            x = x * 10 + nonZeroDigits[i];  
        }


        return x * sum;
    }
};