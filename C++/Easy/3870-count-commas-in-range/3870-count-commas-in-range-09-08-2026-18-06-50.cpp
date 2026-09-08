class Solution {
public:
    int countCommas(int n) { 
        //by observation tc=O(no of digits in range), sc=O(1)
        int count = 0;
        
        for(int i = 999; i < n; i++) {
            count++;
        }

        return count;
    }
};