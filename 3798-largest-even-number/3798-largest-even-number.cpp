class Solution {
public:
    string largestEven(string s) {  //tc=O(n), sc=O(1)
        int lastTwo = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '2') {
                lastTwo = i;
            }
        }
        
        if (lastTwo == -1) return "";
        
        return s.substr(0, lastTwo + 1);
    }
};
