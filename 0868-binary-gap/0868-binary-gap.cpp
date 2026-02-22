class Solution {
public:
    int binaryGap(int n) {  //tc=O(logN), sc=O(1)
    
        int lastPos = -1;     // stores position of previous 1
        int maxDist = 0;      // stores maximum distance
        int pos = 0;          // current bit position
        
        while (n > 0) {
            if (n & 1) {  // if current bit is 1
                if (lastPos != -1) {
                    maxDist = max(maxDist, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1;  // shift right
            pos++;
        }
        
        return maxDist;
    }
};