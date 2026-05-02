class Solution {
public:
    
    bool isGood(int num) {  //O(logm Num)
        bool changed = false;

        while(num > 0) {
            int digit = num % 10;

            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) changed = true;

            num /= 10;  //removeLastD
        }
        return changed;
    }


    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {  //O(n)
            if(isGood(i)) {
                count++;
            }
        }
        return count;
    }
};