#include <cctype> //for islower, isupper funct STL  c++

class Solution {
public:
    int numberOfSpecialChars(string word) {  //tc=O(n), sc=O(1)
        //step1: take two variable 
        bool lower[26] = {false};
        bool upper[26] = {false};

        //step2: assig lower, upper char
        for(char c : word) {
            if(islower(c)) {   //using STL
                lower[c - 'a'] = true;  
            } else {
                upper[c - 'A'] = true;
            }
        }

        //step3: count specialChar
        int count = 0;

        for(int i=0; i < 26; i++) {
            if(lower[i] && upper[i]) {   //bothCharPresent
                count++;
            }
        }

        return count;
    }
};