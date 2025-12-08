class Solution {
public:
    string removeStars(string s) {   //tc=O(n) = sc length of str
        string result = ""; 
        
        for (char c : s) {
            if (c == '*') {
                result.pop_back();  // Remove lastChar (equivalent to pop).
            } else {
                result.push_back(c);  // Add non-star char to result.
            }
        }
        
        return result;  
    }
};
