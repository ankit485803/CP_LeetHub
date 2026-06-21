class Solution {
public:
    int maxDistance(string moves) {  //tc=O(n), sc=(1)
        
        //approach: x = R-L, y = U-D mod values, ans = x + y + k
        //k means no of -

        int U = 0, D = 0, L = 0, R = 0, k = 0;

        for(char c : moves) {
            if(c == 'U') U++;
            else if(c == 'D') D++;
            else if(c == 'L') L++;
            else if(c == 'R') R++;
            else k++;  //this is for -
            
        }

        int ans = abs(R - L) + abs(U - D) + k;
        return ans;
    }
};