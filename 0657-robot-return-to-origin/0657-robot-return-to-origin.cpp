class Solution {
public:
    bool judgeCircle(string moves) {  //TC=O(n), SC=O(1)
        //startWithOrigin
        int x=0, y=0;

        for(char mov : moves) {
            if(mov == 'U') {
                y++;
            } else if(mov == 'D') {
                y--; //move down decrease y coord

            } else if(mov == 'L') {
                x--;  
            } else if(mov == 'R') {
                x++;
            }
        }

        return (x == 0 && y == 0);
    }
};