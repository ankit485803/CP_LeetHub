class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        
        if(n < 2) return "";  //edgeCase

        // Helper function to check if a substring is "nice"
        auto isNice = [](const string& substr) {
            unordered_set<char> lowercase, uppercase;
            for (char c : substr) {
                if (islower(c)) lowercase.insert(c);
                if (isupper(c)) uppercase.insert(c);
            }

         // Check if for every lowercase letter, the uppercase counterpart is present and vice versa
            for (char c : lowercase) {
                if (uppercase.find(toupper(c)) == uppercase.end()) return false;
            }
            for (char c : uppercase) {
                if (lowercase.find(tolower(c)) == lowercase.end()) return false;
            }
            return true;
        };

         // Recursively check all possible substrings
        string longest = "";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string substr = s.substr(i, j - i);
                if (isNice(substr) && substr.size() > longest.size()) {
                    longest = substr;
                }
            }
        }

        return longest;    
    }
};