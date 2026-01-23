class Solution {
public:
    struct Pair {
        long long sum;
        int i;
        bool operator>(const Pair& other) const {
            return sum > other.sum;
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> val(nums.begin(), nums.end());
        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i + 1 < n ? i + 1 : -1);
        }

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({val[i] + val[i + 1], i});
        }

        int violations = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (val[i] > val[i + 1]) violations++;
        }

        int ops = 0;

        while (violations > 0) {
            auto cur = pq.top();
            pq.pop();

            int i = cur.i;
            if (!alive[i]) continue;

            int j = next[i];
            if (j == -1 || !alive[j]) continue;
            if (val[i] + val[j] != cur.sum) continue;

            // remove old violations
            if (prev[i] != -1 && val[prev[i]] > val[i]) violations--;
            if (val[i] > val[j]) violations--;
            if (next[j] != -1 && val[j] > val[next[j]]) violations--;

            // merge
            val[i] += val[j];
            alive[j] = false;

            next[i] = next[j];
            if (next[j] != -1) prev[next[j]] = i;

            // add new violations
            if (prev[i] != -1 && val[prev[i]] > val[i]) violations++;
            if (next[i] != -1 && val[i] > val[next[i]]) violations++;

            // push updated adjacent sums
            if (prev[i] != -1)
                pq.push({val[prev[i]] + val[i], prev[i]});
            if (next[i] != -1)
                pq.push({val[i] + val[next[i]], i});

            ops++;
        }

        return ops;
    }
};
