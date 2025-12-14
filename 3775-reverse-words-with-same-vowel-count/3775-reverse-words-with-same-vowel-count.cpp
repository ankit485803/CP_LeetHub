class Solution {
public:
    string reverseWords(string s) {  //tc=O(n)=sc
        // Helper function to count vowels in a word
        auto countVowels = [](const string& word) {
            int count = 0;
            for (char c : word) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    count++;
                }
            }
            return count;
        };
        
        // Step 1: Split the input string into words
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Determine the vowel count of the first word
        int firstWordVowelCount = countVowels(words[0]);

        // Step 3: Reverse words that have the same vowel count as the first word
        for (int i = 1; i < words.size(); ++i) {
            if (countVowels(words[i]) == firstWordVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        // Step 4: Join the words back into a single string
        string result;
        for (const string& w : words) {
            result += w + " ";
        }
        
        // Remove the trailing space
        result.pop_back();

        return result;
    }
};
 