class Solution {
public:
    int balancedStringSplit(string s) {  //tc=O(n),sc=O(1)
        int ans = 0;

        int left = 0;
        int right = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'L') {
                left++;
            } else {
                right++;
            }

            if(left == right) {  //checkCondition: EQULITY
                ans++;
            }
        }

        return ans;
    }
};