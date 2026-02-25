#include <bitset>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Convert integer to binary string (using bitset for a 32-bit representation)
        string num = bitset<32>(n).to_string(); 

        // Trim leading zeros (unnecessary part for comparison)
        num = num.substr(num.find('1'));

  
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] == num[i + 1]) {
                return false;  
            }
        }

        return true; 
    }
};