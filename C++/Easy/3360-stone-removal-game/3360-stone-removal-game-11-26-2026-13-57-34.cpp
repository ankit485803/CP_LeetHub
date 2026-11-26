class Solution {
public:
    bool canAliceWin(int n) {  //tc=O(1)=sc using SIMULATION apporach
        int take = 10;
        int steps = 0;

        while(n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;  //if odd idx Alice win
    }
};