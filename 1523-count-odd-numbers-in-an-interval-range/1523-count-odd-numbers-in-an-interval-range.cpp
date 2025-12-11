class Solution {
public:
    int countOdds(int low, int high) {  //tc = O(1) = sc
        // If both low and high are even.
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;
        
        // Otherwise, at least one is odd → add one more.
        return (high - low) / 2 + 1;
    }
};
