class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {  //tc=O(n), sc=O(1)
        string result = "";

        for(const string& word : words) {
            int sum = 0;

            //calculate total weight of words
            for(char ch : word) {
                sum += weights[ch - 'a'];
            }

            int mod = sum % 26;

            //reverse alphabetically mapping
            char mappedChar = 'z' - mod;

            result += mappedChar;
        }

        return result;
    }
};