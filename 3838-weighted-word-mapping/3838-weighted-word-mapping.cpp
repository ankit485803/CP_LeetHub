class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (const string& word : words) {
            int sum = 0;

            // Calculate total weight of word
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int mod = sum % 26;

            // Reverse alphabetical mapping
            char mappedChar = 'z' - mod;

            result += mappedChar;
        }

        return result;
    }
};