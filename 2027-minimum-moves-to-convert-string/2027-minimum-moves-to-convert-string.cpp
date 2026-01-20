class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        int i=0;
        while(i < s.size()) {
            if(s[i] == 'X') {
                moves++;
                i +=3;  //given oneMove takes threePosition
            } else {
                i++;
            }
        }
        return moves;
    }
};