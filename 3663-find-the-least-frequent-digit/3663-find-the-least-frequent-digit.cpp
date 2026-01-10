class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);

        // Step1: count digitFreq
        while (n > 0) {
            int d = n % 10;
            freq[d]++;
            n /= 10;
        }

        // Step2: find least freqDigit
        int minFreq = INT_MAX;
        int ans = 0;

        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0) {  // only digits that appear
                if (freq[d] < minFreq) {
                    minFreq = freq[d];
                    ans = d;
                }
            }
        }

        return ans;
    }
};
