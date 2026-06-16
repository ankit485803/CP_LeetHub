class Solution {
public:
    string processStr(string s) {  //tc=O(m) = sc
        string result = "";

        for(char &ch : s) {
            if(ch == '*') {
                if(result.length() > 0) result.pop_back();   //remove lastChar O(1)
                 
            } else if(ch == '#') {
                result += result;   //n -> 2*n duplicate kar dena  O(m)

            } else if(ch == '%') { 
                reverse(begin(result), end(result));  //O(m)

            } else {
                result += ch;
            }
        }

        return result;
    }
};