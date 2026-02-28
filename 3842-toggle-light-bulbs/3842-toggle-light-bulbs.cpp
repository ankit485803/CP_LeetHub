class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> freq(101, 0);   // bulbs numbered 1 to 100
        
        // Count frequency
        for (int b : bulbs) {
            freq[b]++;
        }
        
        vector<int> ans;
        
        // Check which bulbs are ON (odd count)
        for (int i = 1; i <= 100; i++) {
            if (freq[i] % 2 == 1) {
                ans.push_back(i);
            }
        }
        
        return ans;   // already sorted because we go from 1 to 100
    }
};