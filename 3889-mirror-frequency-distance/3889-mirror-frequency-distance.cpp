class Solution {
public:
    int mirrorFrequency(string s) {  //tc=O(n), sc=O(1)
        vector<int> freq(128, 0);
        
        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }
        
        int ans = 0;
        
        // Step 2: Iterate over all possible charsa
        for (char c = 'a'; c <= 'z'; c++) {
            char m = 'z' - (c - 'a');
            
            if (c > m) continue; // avoid double counting
            
            ans += abs(freq[c] - freq[m]);
        }
        
        for (char c = '0'; c <= '9'; c++) {
            char m = '9' - (c - '0');
            
            if (c > m) continue; // avoid double counting
            
            ans += abs(freq[c] - freq[m]);
        }
        
        return ans;
    }
};