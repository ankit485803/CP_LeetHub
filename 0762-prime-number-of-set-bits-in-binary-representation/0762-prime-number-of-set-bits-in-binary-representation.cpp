class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;

        for(int i=2; i*i <=n; i++) {
            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {  //tc=O(n), sc=O(1)
        int count = 0;

        for(int num = left; num <= right; num++) {
            int bits = __builtin_popcount(num);  //total 1s bit
            if(isPrime(bits)) {
                count++;
            }
        }

        return count;
    }
};