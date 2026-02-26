class Solution {
public:
    int countBinarySubstrings(string s) {
        // Count consecutive characters and form group sizes.
        // ans += min(groups[i], groups[i-1])

        int prev = 0;
        int curr = 1;  //curr groupLeng
        int count = 0;

        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        count += min(prev, curr);
        return count;  //tc=O(n), sc=O(1)
    }
};