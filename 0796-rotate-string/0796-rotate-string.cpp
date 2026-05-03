class Solution {
public:
    bool rotateString(string s, string goal) {  //tc=O(n^2) nestedWork, sc=O(1)
        int m = s.length(); 
        int n = goal.length();

        if(m != n) {
            return false;
        }

        //bruteForceally check all possible rotation
        for(int rotationCount = 1; rotationCount <= m; rotationCount++) {
            //using STL c++ 
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal) {
                return true;
            }
        }
        return false;
    }
};