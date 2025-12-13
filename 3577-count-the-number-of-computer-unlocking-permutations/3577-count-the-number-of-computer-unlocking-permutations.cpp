class Solution {
public:
    int countPermutations(vector<int>& complexity) { //greedyAppoach
        const int MOD = 1e9 + 7;
        int n = complexity.size();

        vector<pair<int,int>> a;
        for (int i = 1; i < n; i++) {
            a.push_back({complexity[i], i});
        }

        // Sort by complexity
        sort(a.begin(), a.end());

        long long ans = 1;
        int unlocked = 1; // computer 0 already unlocked

        for (auto &[comp, idx] : a) {
            // count how many unlocked j < idx with smaller complexity
            int choices = 0;
            for (int j = 0; j < idx; j++) {
                if (complexity[j] < comp) choices++;
            }

            if (choices == 0) return 0;

            ans = (ans * choices) % MOD;
            unlocked++;
        }

        return ans;
    }
};
