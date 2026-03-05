class Solution {
public:
    int minOperations(string s) {  //TC=O(n),SC=O(1)
 
        int countZ = 0; //zeros
        int countO = 0;  //ones counting

        for (int i = 0; i < s.size(); i++) {

            // Case1: evenIndex (i = 0, 2, 4, ...)
            if (i % 2 == 0) {
                // For pattern "0101...", even positions should be '0'
                if (s[i] != '0') countZ++;

                // For pattern "1010...", even positions should be '1'
                if (s[i] != '1') countO++;
               } 



            // Case2: oddIndex (i = 1, 3, 5, ...)
            else {
                // For pattern "0101...", odd positions should be '1'
                if (s[i] != '1') countZ++;

                // For pattern "1010...", odd positions should be '0'
                if (s[i] != '0') countO++;
               }
        }


        return min(countZ, countO);
      }
};


