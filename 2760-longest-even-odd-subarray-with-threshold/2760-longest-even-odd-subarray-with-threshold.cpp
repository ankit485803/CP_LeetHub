class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) { //greedy tc=O(n), sc=O(1) 
        int maxLen = 0;
        int currLen = 0;
        int prevParity = -1; // 0 = even, 1 = odd

        for (int num : nums) {
            if (num > threshold) {
                // Cannot include this number
                currLen = 0;
                prevParity = -1;
                continue;
            }

            int parity = num % 2;

            if (currLen == 0) {
                // Start only if the number is even
                if (parity == 0) {
                    currLen = 1;
                    prevParity = parity;
                    maxLen = max(maxLen, currLen);
                }
            } else {
                // Check alternating parity
                if (parity != prevParity) {
                    currLen++;
                    prevParity = parity;
                    maxLen = max(maxLen, currLen);
                } else {
                    // Restart if current number is even
                    if (parity == 0) {
                        currLen = 1;
                        prevParity = parity;
                        maxLen = max(maxLen, currLen);
                    } else {
                        currLen = 0;
                        prevParity = -1;
                    }
                }
            }
        }

        return maxLen;
    }
};
