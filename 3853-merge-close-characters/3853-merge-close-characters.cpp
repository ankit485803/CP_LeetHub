#include <string>
using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (!result.empty() && result.back() == s[i] && i - result.size() <= k) {
                continue;
            }
            result += s[i];
        }

        return result;
    }
};