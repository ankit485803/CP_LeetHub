class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {  
        // tc = O(n), sc = O(n)

        unordered_map<int, int> freq1, freq2;

        // count frequencies
        for (int x : nums1) freq1[x]++;
        for (int x : nums2) freq2[x]++;

        int totalDiff = 0;

        // check feasibility + count differences
        unordered_set<int> keys;
        for (auto &p : freq1) keys.insert(p.first);
        for (auto &p : freq2) keys.insert(p.first);

        for (int x : keys) {
            int f1 = freq1[x];
            int f2 = freq2[x];

            // if total frequency is odd → impossible
            if ((f1 + f2) % 2 != 0) return -1;

            // count extra elements in nums1
            if (f1 > f2) {
                totalDiff += (f1 - f2);
            }
        }

        // each swap fixes 2 elements
        return totalDiff / 2;
    }
};