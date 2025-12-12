#include <unordered_map>
#include <algorithm>


class Solution {
public:
    string customSortString(string order, string s) { //tc=O(n logN), sc=(m + n)
        // Step 1: Create map to store the priority of eachChar
        unordered_map<char, int> charPriority;
        for (int i = 0; i < order.size(); ++i) {
            charPriority[order[i]] = i;
        }
        
        // Step 2: Create a lambdaFunct to sort characters based on their order priority
        auto customComparator = [&charPriority](char a, char b) {
            // If both characters are in the order, compare their priorities
            if (charPriority.count(a) && charPriority.count(b)) {
                return charPriority[a] < charPriority[b];
            }
            // If only one of them is in the order, that one should come first
            if (charPriority.count(a)) return true;
            if (charPriority.count(b)) return false;
            // If neither is in the order, keep the original order
            return a < b;
        };
        
        // Step3: Sort
        sort(s.begin(), s.end(), customComparator);
        
        return s;
    }
};
