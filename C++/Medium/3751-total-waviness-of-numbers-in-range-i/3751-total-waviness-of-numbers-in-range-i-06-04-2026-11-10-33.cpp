class Solution {
public:
    int totalWaviness(int num1, int num2) {  //TC=O(n*d), SC=O(d)
        int total = 0;

        for (int num = num1; num <= num2; ++num) {
            string strNum = to_string(num);
            int waviness = 0;
            
            // Skip numbers with fewer than 3 digits
            if (strNum.size() < 3) continue;
            
            // Loop through digits (excluding first and last)
            for (int i = 1; i < strNum.size() - 1; ++i) {
                char prev = strNum[i - 1];
                char curr = strNum[i];
                char next = strNum[i + 1];
                
                // Check for peak
                if (curr > prev && curr > next) {
                    waviness++;
                }
                // Check for valley
                if (curr < prev && curr < next) {
                    waviness++;
                }
            }
            
            total += waviness;
        }
        
        return total;
    }
};