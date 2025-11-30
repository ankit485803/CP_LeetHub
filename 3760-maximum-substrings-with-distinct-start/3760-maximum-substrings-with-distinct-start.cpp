class Solution {
public:
    int maxDistinct(string s) {  //tc=O(n), sc=O(1)
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a'] = 1;   // mark character as present
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += freq[i];    // count distinct chars
        }

        return count;  // max substrings = distinct chars
    }
};
