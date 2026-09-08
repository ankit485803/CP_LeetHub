class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        int i = 999;  //intilize
        while(i < n) {
            count++;
            i++;
        }

        return count;
    }
};