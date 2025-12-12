class Solution {
public:
    int secondHighest(string s) {  //tc=o(n logN), sc=O(n) due to digits
        vector<int> digits;
 
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                digits.push_back(s[i] - '0');  // Store the actual digit, not the index
            }
        }

        // If there are fewer than two digits
        if (digits.size() < 2) {
            return -1;
        }

        // Sort descending order to find the secondLarg
        sort(digits.begin(), digits.end(), greater<int>());
        
        // Find the second largest unique digit
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] != digits[0]) {
                return digits[i];
            }
        }
        
        return -1;  
    }
};