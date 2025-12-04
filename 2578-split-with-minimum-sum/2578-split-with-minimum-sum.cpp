class Solution {
public:
    int splitNum(int num) {  //tc=O(10 log10), sc=O(1)
        vector<int> digits;
        
        // Extract digits
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        // Sort digits ascending
        sort(digits.begin(), digits.end());
        
        long long num1 = 0, num2 = 0;
        
        // Distribute digits alternately
        for (int i = 0; i < digits.size(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + digits[i];
            } else {
                num2 = num2 * 10 + digits[i];
            }
        }
        
        return num1 + num2;
    }
};
