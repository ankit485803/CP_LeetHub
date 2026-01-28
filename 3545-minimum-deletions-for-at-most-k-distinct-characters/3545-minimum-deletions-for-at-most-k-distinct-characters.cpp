class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;

        // Step 1: frequency count
        for (char c : s) {
            freq[c]++;
        }

        // If already within limit
        if (freq.size() <= k) return 0;

        // Step 2: collect frequencies
        vector<int> counts;
        for (auto &p : freq) {
            counts.push_back(p.second);
        }

        // Step 3: sort descending
        sort(counts.begin(), counts.end(), greater<int>());

        // Step 4 & 5: delete all except top k
        int deletions = 0;
        for (int i = k; i < counts.size(); i++) {
            deletions += counts[i];
        }

        return deletions;
    }
};
