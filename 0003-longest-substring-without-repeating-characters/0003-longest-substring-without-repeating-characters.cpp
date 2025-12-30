class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(256, -1);  // stores last seen index of characters
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character was seen and is inside curr window
            if (lastIdx[s[right]] >= left) {
                left = lastIdx[s[right]] + 1;
            }

            lastIdx[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
