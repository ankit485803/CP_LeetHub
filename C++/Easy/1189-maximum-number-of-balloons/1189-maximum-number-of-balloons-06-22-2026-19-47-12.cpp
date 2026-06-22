class Solution {
public:
    int maxNumberOfBalloons(string text) {  //tc=O(n), sc=O(1)
        //step1: iterate each char in str to count freq
        int b=0, a = 0, l=0, o = 0, n=0;

        for(char ch : text) {
            if(ch == 'b') b++;
            else if(ch == 'a') a++;
            else if(ch == 'l') l++;
            else if(ch == 'o') o++;
            else if(ch == 'n') n++;
        }

        //step2: instance BALLON condition 
        int ans = min({b, a, l / 2, o / 2, n});
        return ans;
    }
};