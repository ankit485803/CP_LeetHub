class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {  //tc=O(n)=s
        unordered_set<int> seen;
        
        for (int x : nums) {
            if (seen.count(x)) {
                return x;
            }
            seen.insert(x);
        }
        
        return -1; // safety (never reached)
    }
};
