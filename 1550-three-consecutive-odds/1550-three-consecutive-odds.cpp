class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0; // Count of consecutive odd numbers
        
        for (int num : arr) {
            if (num % 2 != 0) {  //odd
                count++;
                if (count == 3) {  // If we have found 3 consecutive odd numbers
                    return true;
                }
            } else {
                count = 0;  // Reset the count if the number is even
            }
        }
        
        return false;   
    }
};
