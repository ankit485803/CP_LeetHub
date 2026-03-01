class Solution {
public:
    int minPartitions(string n) {  //tc=O(n), sc=O(1)
        //step1: find maxDigit in str
        char maxDigit = '0';

        for(char c : n) {
            if(c > maxDigit) {
                maxDigit = c;  //Update maxDigit when a larger digit is found
            }
        }

        return maxDigit - '0';  //convert char into int 
    }
};