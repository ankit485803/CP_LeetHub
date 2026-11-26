
class Solution {
public:
    bool canAliceWin(int n) {  //tc=O(1)=sc using maths
        int k = (21 - sqrt(441 - 8*n)) / 2;

        return k % 2 == 1;  //Alice win
    }
};