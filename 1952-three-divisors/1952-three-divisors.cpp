class Solution {
public:
    bool isThree(int n) {
        int x = sqrt(n);
        
        if (x * x != n) return false;
        
        // Check if x is prime
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        
        return x > 1;
    }
};
