class Solution {
public:
    bool checkOnesSegment(string s) {
        int segmentS = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                segmentS++;
            }
        }

        //return segmentS <= 1;
        if(segmentS <= 1) {
            return true;
        } else {
            return false;
        }
    }
};