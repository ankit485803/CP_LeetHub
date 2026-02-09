class Solution {
public:
    bool areNumbersAscending(string s) {   //tc=O(n), sc=O(1)
        int prev = -1;
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(isdigit(s[i])) {
                int curr = 0;

                //extract all the numb from s
                while(i<n && isdigit(s[i])) {
                    curr = curr * 10 + (s[i] - '0');
                    i++;
                }

                //check stricklyInc
                if(curr <= prev) {
                    return false;
                }

                prev = curr;
            }
        }

        return true;
    }
};