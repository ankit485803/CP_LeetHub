class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0; // number of vowels
        int c = 0; // number of consonants

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {   // only letters
                if (ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u') {
                    v++;
                } else {
                    c++;
                }
            }
        }

        if (c == 0) return 0;
        return v / c;   // integer division = floor
    }
};
