class Solution {
public:
    bool isGood(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int maxElem = 0;
        for (int x : nums) {
            maxElem = max(maxElem, x);
        }

        // base[n] has length n + 1
        if (nums.size() != maxElem + 1)
            return false;

        vector<int> freq(201, 0);
        for (int x : nums) {
            freq[x]++;
        }

        // Check 1 to n-1 appear exactly once
        for (int i = 1; i < maxElem; i++) {
            if (freq[i] != 1)
                return false;
        }

        // Check n appears exactly twice
        if (freq[maxElem] != 2)
            return false;

        return true;
    }
};
