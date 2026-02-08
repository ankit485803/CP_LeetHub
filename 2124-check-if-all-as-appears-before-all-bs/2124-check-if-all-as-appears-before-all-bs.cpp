class Solution {
public:
    bool checkString(string s) {

        for(int i=0; i<s.size(); i++) {
            char ch1 = s[i];
            char ch2 = s[i+1];  //nextChar alikely b on rightSide

            if(ch1 == 'b' && ch2 == 'a') {
                return false;
            }
        }

        return true;
    }
};