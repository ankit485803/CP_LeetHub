class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Frequency map for all elements
        // Time: O(n log(maxVal)), Space: O(n)
        unordered_map<long long, int> freq;
        int ones = 0;

        for (int num : nums) {
            freq[num]++;
            if (num == 1) ones++;
        }

        // Any odd-length subsequence of 1s is valid
        int ans = (ones % 2 == 0) ? ones - 1 : ones;

        // Remove 1s since they are already handled
        freq.erase(1LL);

        for (const auto& entry : freq) {
            long long num = entry.first;
            int count = 0;
            long long curr = num;

            // Follow the squaring chain: num -> num^2 -> num^4 -> ...
            while (freq.count(curr)) {
                if (freq[curr] >= 2) {
                    count += 2;  // Can take a pair at this level
                } else {
                    count++;     // Only one occurrence, end the chain
                    break;
                }

                // Prevent overflow when squaring
                if (curr > LLONG_MAX / curr) break;
                curr = curr * curr;
            }

            // Result must be odd
            if (count % 2 == 0) count--;

            ans = max(ans, count);
        }

        return ans;
    }
};