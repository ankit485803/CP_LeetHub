class Solution {
private:
    bool isVowel(char ch) {  //tc=O(n), sc=O(1)
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        } else {
            return false;
        }
    }    

public:
    string trimTrailingVowels(string s) {
        //vowels that are at the end of str: Trailing
        //trim: cut into pieces
        int i = s.size() - 1;

        while(i >= 0 && isVowel(s[i])) {
            i--;
        }
        return s.substr(0, i+1);

    }
};