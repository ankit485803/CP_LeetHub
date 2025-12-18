class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        // Loop through the string to check substrings of size 3
        for (int i = 0; i <= n - 3; i++) {
            string sub = s.substr(i, 3);  // Get the substring of length 3
            if (sub[0] != sub[1] && sub[1] != sub[2] && sub[0] != sub[2]) {
                count++;  // If all characters are distinct, increment the count
            }
        }
        
        return count;
    }
};
