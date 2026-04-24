class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {  //tc=O(n), sc=O(1)
        int left = 0;
        int right = 0;  //start with origin 0 on numbLine
        int dash = 0;

        for(char &ch : moves) {
            if(ch == 'L') left++;   //maintain count L 
            else if(ch == 'R') right++;
            else dash++;
        }

        return abs(left - right) + dash;  //usi direction mai chale jao 
    }
};