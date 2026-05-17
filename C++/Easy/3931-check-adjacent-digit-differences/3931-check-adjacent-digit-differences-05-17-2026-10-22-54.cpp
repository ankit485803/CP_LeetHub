class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {  //tc=O(n), sc=O(1)
        
        for(int i = 1; i < s.length(); i++) {
            if(abs(s[i] - s[i-1]) > 2) return false;
        }
        return true;
    } 
};