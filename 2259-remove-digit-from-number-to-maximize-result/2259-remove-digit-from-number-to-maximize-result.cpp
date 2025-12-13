class Solution {
public:
    string removeDigit(string numb, char digit) { //tc=O(n), sc=O(1)
        int n = numb.size();

        //firstLoop: find firstDigit that is smaller than nextOne
        for(int i=0; i<n-1; i++) {
            if(numb[i] == digit && numb[i] < numb[i + 1]) {
                // If digit is smaller than the next digit, remove it
                return numb.substr(0, i) + numb.substr(i + 1);
            }
        }

        //secondLoop: if no such condition found, remove last occurrence of digit
        for(int i=n-1; i>=0; i--) {
            if(numb[i] == digit) {
                return numb.substr(0, i) + numb.substr(i + 1);
            }
        }

        return numb;  //if no removal, return originalNum
    }
};