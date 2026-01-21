class Solution {
public:
    bool isSubsequence(const string& s, const string& word) {  //tc=O(m*n), sc=O(1)
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";

        for (const string& word : dictionary) {
            if (isSubsequence(s, word)) {
                if (word.size() > result.size() ||
                   (word.size() == result.size() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};
