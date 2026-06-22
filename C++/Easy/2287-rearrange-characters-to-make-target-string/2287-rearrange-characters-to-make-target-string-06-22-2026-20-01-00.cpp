class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> sFreq(26, 0);
        vector<int> targetFreq(26, 0);

        //freq
        for(char c : s) 
            sFreq[c - 'a']++;

        for(char c : target) 
            targetFreq[c - 'a']++;

        //mainLogic
        int ans = INT_MAX;

        for(int i=0; i<26; i++) {
            if(targetFreq[i] > 0) {
                ans = min(ans, sFreq[i] / targetFreq[i]); 
            }
        }

        return ans;
    }   
};