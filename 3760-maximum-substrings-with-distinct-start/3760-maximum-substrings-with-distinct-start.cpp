class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> used;

        for (char c : s) {
            used.insert(c);
        }

        return used.size();
    }
};
