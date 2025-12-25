#include <sstream>
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {  //tc=O(no of char), sc=O(n*k)
        int maxWord = 0;
        
        for (int i = 0; i < sentences.size(); i++) {
            string curr = sentences[i];
            stringstream ss(curr);
            string word;
            int wordCount = 0;
            
            // Count words in the current sentence
            while (ss >> word) {
                wordCount++;
            }

            maxWord = max(maxWord, wordCount);
        }
        
        return maxWord;
    }
};

