class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //first convert to str
        string s = to_string(num);
        int count = 0;

        for(int i=0; i+k<s.size(); i++) {
            int val = stoi(s.substr(i, k));

            //0 is not divisor
            if(val != 0 && num % val == 0) {
                count++;
            }
        }

        return count; 
    }
};