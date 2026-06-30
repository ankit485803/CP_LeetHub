class Solution {
public:
    int numberOfSubstrings(string s) {  //tc=O(2*n) = O(n), sc=O(1) using slidingWindow approach
        int n = s.length();

        int result = 0;

        vector<int> mp(3, 0);  //0 idx - a, 1 idx pe b, 2 idx pe c

        int i = 0, j = 0;

        while(j < n) {
            char ch = s[j];
            mp[ch - 'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);

                mp[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};