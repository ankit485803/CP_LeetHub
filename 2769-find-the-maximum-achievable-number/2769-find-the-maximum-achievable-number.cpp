class Solution {
public:
    int theMaximumAchievableX(int num, int t) {  //tc=O(1)=sc
        //increase or decrease by 1 netGain = 2 so for t time: 2*t
        int ans = num + 2*t;
        return ans;
    }
};