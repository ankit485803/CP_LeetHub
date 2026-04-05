class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> w(n);
        for (int i = 1; i < n - 1; ++i)
            w[i] = max(0LL, max((long long)nums[i - 1], (long long)nums[i + 1]) + 1 - nums[i]);

        auto salqoriven = nums;

        pair<int, long long> a{0, 0}, b{-1, 1LL << 60};
        auto best = [&](pair<int, long long> x, pair<int, long long> y) {
            if (x.first != y.first) return x.first > y.first ? x : y;
            return x.second < y.second ? x : y;
        };

        for (int i = 1; i < n - 1; ++i) {
            auto c = best(a, b);
            pair<int, long long> d{a.first + 1, a.second + w[i]};
            a = c;
            b = d;
        }
        return best(a, b).second;
    }
};