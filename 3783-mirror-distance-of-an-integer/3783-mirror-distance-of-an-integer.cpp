class Solution {
public:
    int mirrorDistance(int n) {  //sc=O(1)
        int original = n;

        //step1: reverse the n, tc=O(digits)
        int revN = 0;
        while(n > 0) {
            revN = revN * 10 + (n % 10);
            n /= 10;
        }

        //step2: calculate abs diff
        int mirrDist = abs(original - revN);
        return mirrDist;
    }
};