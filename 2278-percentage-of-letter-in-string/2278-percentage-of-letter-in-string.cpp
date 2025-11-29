class Solution {
public:
    int percentageLetter(string s, char letter) { //tc=O(n), sc=O(1)
        int n = s.size();

        int count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == letter) {
                count++;  // Increment count if the character matches the letter
            }
        }
        int percentLetter = (count * 100) / n;  //simply apply percentageFormaula

        return  percentLetter;
    }
};