class Solution {
public:
    int numSteps(string s) {  //tc=O(n) sc=O(1)
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (ignore first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd → +1 and divide
                steps += 2;
                carry = 1;
            } else {
                // even → divide
                steps += 1;
                // carry remains same
            }
        }

        // If carry remains at MSB
        return steps + carry;
    }
};