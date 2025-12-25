#include <cctype> // for isupper and tolower
class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            char ch1 = s[i];
            char ch2 = s[i + 1];

            // Check if the current characters are of different cases
            if (tolower(ch1) != tolower(ch2)) {
                count++;
            }
        }
        return count;
    }
};
