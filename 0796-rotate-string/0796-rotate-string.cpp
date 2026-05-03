class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n) {
            return false;
        }

        //bruteForceally check all possible rotation
        for(int rotationCount = 1; rotationCount <= m; rotationCount++) {
            //using STL c++
            rotate(s.begin(), s.begin() + 2, s.end());

            if(s == goal) {
                return true;
            }
        }
        return false;
    }
};