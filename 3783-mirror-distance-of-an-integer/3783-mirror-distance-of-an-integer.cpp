class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);  //convert interger into string  tc=O(log10 N)
        //rev
        reverse(begin(s), end(s));
        
        int revIntAns = stoi(s);  //reconvert

        return abs(n - revIntAns);
    }
};