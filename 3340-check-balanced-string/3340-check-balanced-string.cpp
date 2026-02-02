class Solution {
public:
    bool isBalanced(string num) {
        int evenIdx = 0;
        int oddIdx = 0;

        for(int i=0; i<num.size(); i++) {
            int curr = num[i] - '0';
            if(i % 2 == 0) {
                evenIdx += curr;
            } else {
                oddIdx += curr;
            }
        }

        // if(evenIdx == oddIdx) {
        //     return true;
        // }
        // return false; 

        return evenIdx == oddIdx;
    }
};