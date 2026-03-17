class Solution {
public:
    long long gcdSum(vector<int>& nums) { //tc=O(n logN), sc=O(n)

        int n = nums.size();
        vector<long long> prefixGcd(n);

        long long mx = 0;

        // build prefixGcd
        for(int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], mx);
        }

        // sort
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int l = 0, r = n - 1;

        while(l < r) {
            ans += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};