class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // 1. Sort events by start time
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // 2. Build suffix maximum array of values
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        // 3. Try each event as the first event
        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]); // single event case

            // Binary search for first event with start > end[i]
            int lo = i + 1, hi = n - 1, idx = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > events[i][1]) {
                    idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            // Combine with best possible future event
            if (idx != -1) {
                ans = max(ans, events[i][2] + suffixMax[idx]);
            }
        }

        return ans;
    }
};
