class Solution {
public:
    int maxDepth(string s) {  //tc=O(n), sc=O(1) using constantSpace interative countingApproach
        int ans = 0;
        int openBrackets = 0;

        for(char& ch : s) {
            if(ch == '(') {
                openBrackets++;
            } else if(ch == ')') {
                openBrackets--;
            }

            ans = max(ans, openBrackets);
        }

        return ans;
    }
};