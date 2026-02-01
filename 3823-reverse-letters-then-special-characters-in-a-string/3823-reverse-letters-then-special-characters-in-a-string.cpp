class Solution {
public:
    string reverseByType(string s) {  //tc=O(n)=sc
        string letters, specials;
        
        // Step 1: collect letters and special characters
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                letters.push_back(c);
            } else {
                specials.push_back(c);
            }
        }
        
        // Step 2: reverse both
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());
        
        // Step 3: rebuild the string
        int i = 0, j = 0;
        for (char &c : s) {
            if (c >= 'a' && c <= 'z') {
                c = letters[i++];
            } else {
                c = specials[j++];
            }
        }
        
        return s;
    }
};
