#include <unordered_map>

class Solution {
public:
    int longestBalanced(string s) {  //TC=(n * n) due to nestedLoop, SC=O(1)map will store at most 26 key-value pairs.

        
        int n = s.size();
        int max_len = 0;
        
        // Step1: Iterate over all possible substr
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;  // To store Freq of char in curr window
            
            // Step2: Iterate over the subStr starting from i
            for (int j = i; j < n; ++j) {
                freq[s[j]]++;  // Increment

                // Step3: Check if the curr subStr is balanced
                if (isBalanced(freq)) {
                    max_len = max(max_len, j - i + 1);  // Update max_len if the curr subStr is balanced
                }
            }
        }

        return max_len;  
    }



    
private:
    // Helper function to check if the curr Freq map represents a balanced subStr
    bool isBalanced(const unordered_map<char, int>& freq) {   //TC=(n)
        int count = -1;
        
        // Check if all characters have the same Freq
        for (const auto& entry : freq) {
            if (count == -1) {
                count = entry.second;  // Initialize with the first character's Freq
            } else if (entry.second != count) {
                return false;  // If any character has a different Freq, it's not balanced
            }
        }
        
        return true;
    }
};
