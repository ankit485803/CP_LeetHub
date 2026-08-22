class Solution {
public:
    //helperFun
    int calcaluteDigSum(int n) {  //tc=O(no of digits) = O(logN), sc=O(1)
        int sum = 0;
        
       while(n > 0) {
            int lastD = n % 10;
            sum += lastD;
            n /= 10;  //removingLast
        }
        
        return sum;
    }

    int calculateDigProd(int n) {
        int prod = 1;  //initilize with 1
        
        while(n > 0) {
            int lastD = n % 10;
            prod *= lastD;
            n /= 10;  
        }

        return prod;
    }


    bool checkDivisibility(int n) {
        //createTwo helperFunct
        int digSum = calcaluteDigSum(n), digProd = calculateDigProd(n);

        int totalSum = digSum + digProd;

        return (n % totalSum == 0); 
    }
};