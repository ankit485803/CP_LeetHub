class Solution {
    long long solve(vector<long long>& w, int l, int r, int t) {
        const long long INF = 4e18;
        if (t < 0) return INF;
        if (l > r) return t == 0 ? 0 : INF;
        if (t == 0) return 0;

        vector<long long> p2(t + 1, INF), p1(t + 1, INF), cur(t + 1, INF);
        p2[0] = p1[0] = 0;

        for (int i = l; i <= r; ++i) {
            fill(cur.begin(), cur.end(), INF);
            cur[0] = 0;
            for (int j = 1; j <= t; ++j) cur[j] = min(p1[j], p2[j - 1] + w[i]);
            p2.swap(p1);
            p1.swap(cur);
        }
        return p1[t];
    }

public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (k > n / 2) return -1;

        vector<int> qorvenalid = nums;
        vector<long long> w(n);
        for (int i = 0; i < n; ++i) {
            long long a = qorvenalid[(i - 1 + n) % n];
            long long b = qorvenalid[(i + 1) % n];
            w[i] = max(0LL, max(a, b) + 1 - qorvenalid[i]);
        }

        const long long INF = 4e18;
        long long ans = min(solve(w, 1, n - 1, k), w[0] + solve(w, 2, n - 2, k - 1));
        return ans >= INF / 2 ? -1 : (int)ans;
    }
};