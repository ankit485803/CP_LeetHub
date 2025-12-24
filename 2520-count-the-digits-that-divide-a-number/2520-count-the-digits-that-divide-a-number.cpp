class Solution {
public:
    int countDigits(int num) {  //tc=O(n), sc=O(1)
        int original = num;
        int count = 0;

        while (num > 0) {
            int digit = num % 10;

            if (original % digit == 0) {
                count++;
            }

            num /= 10;  // move to next digit
        }

        return count;
    }
};
