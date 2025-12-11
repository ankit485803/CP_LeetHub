class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        int i = 0; // as a index

        i = low;
        while(i <= high) {
            if(i % 2 == 1) {  //ODD conditon remainer 1
                count++;
            }
            i++;
        }

        return count;
    }
};