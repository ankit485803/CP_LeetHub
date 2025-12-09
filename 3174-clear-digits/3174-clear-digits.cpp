#include <stack>
#include <cctype>  // for isdigit

class Solution {
public:
    string clearDigits(string s) {  //tc=O(n)=sc
        stack<char> stk;

        for (char c : s) {
            if (isdigit(c)) {
                // If char is a digit, pop the last non-digit char
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(c);
            }
        }


        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;  // prepend the char to result
            stk.pop();
        }

        return result;
    }
};
