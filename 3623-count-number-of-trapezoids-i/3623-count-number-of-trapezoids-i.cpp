class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;

        // Count points per y-level
        for (auto &p : points) {
            mp[p[1]]++;
        }

        long long result = 0;
        long long prev = 0;   // sum of past C(n,2)

        for (auto &e : mp) {
            long long cnt = e.second;
            if (cnt >= 2) {
                long long cur = cnt * (cnt - 1) / 2;   // C(n,2)

                result = (result + cur * prev) % MOD;

                prev = (prev + cur) % MOD;
            }
        }

        return result;
    }
};

