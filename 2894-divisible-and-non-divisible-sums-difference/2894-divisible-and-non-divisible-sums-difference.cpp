class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;  //not divisible
        int num2 = 0;  //divisible by m

        for(int i=1; i<=n; i++) {
            if(i % m == 0) {
                num2 += i;
            }
        }
        int totalSum = n * (n+1) / 2;
        num1 = totalSum - num2;

        return num1-num2;
    }

};