class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i < n; i++) {
            // If any computer cannot be unlocked by computer 0
            if (complexity[i] <= complexity[0]) {
                return 0;
            }

            ans = (ans * i) % MOD;  // multiply choices
        }

        return (int)ans;
    }
};
