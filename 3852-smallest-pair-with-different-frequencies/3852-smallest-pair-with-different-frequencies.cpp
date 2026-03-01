class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int freq[101] = {0};  //freq arr for numb from 1 to 100
        
        // Step 1: CountFreq
        for(int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Find the smallest x < y with different frequencies
        for(int x = 1; x <= 100; x++) {
            if(freq[x] == 0) {
                continue;  // Skip if x is not in the array
            }

            for(int y = x + 1; y <= 100; y++) {
                if(freq[y] == 0) {
                    continue;  // Skip if y is not in the array
                }

                if(freq[x] != freq[y]) {
                    // Return the first valid pair (x, y) with diff freq
                    return {x, y};
                }
            }
        }

        // If no valid pair is found, return [-1, -1]
        return {-1, -1};
    }
};