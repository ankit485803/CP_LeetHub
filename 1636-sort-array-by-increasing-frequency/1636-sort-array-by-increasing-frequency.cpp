class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Sort with custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) 
                return a > b; // decreasing order for same frequency
            return freq[a] < freq[b]; // increasing order of frequency
        });

        return nums;
    }
};
