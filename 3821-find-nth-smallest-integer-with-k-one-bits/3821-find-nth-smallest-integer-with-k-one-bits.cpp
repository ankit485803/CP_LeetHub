class Solution {
public:
    long long C[55][55];

    void buildCombinations() {
        for (int i = 0; i <= 50; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    long long nthSmallest(long long n, int k) {
        buildCombinations();

        long long ans = 0;
        int bitsLeft = k;

        // we go from highest possible bit down to 0
        for (int pos = 50; pos >= 0; pos--) {
            if (bitsLeft == 0) break;

            // count numbers if we DON'T set this bit
            long long count = C[pos][bitsLeft];

            if (count < n) {
                // we must set this bit
                ans |= (1LL << pos);
                n -= count;
                bitsLeft--;
            }
            // else: keep bit 0 and move on
        }

        return ans;
    }
};
