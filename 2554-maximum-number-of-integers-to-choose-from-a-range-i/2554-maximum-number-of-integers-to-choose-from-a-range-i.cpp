class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {  //tc=O(n logN), sc=O(1) using GREEDY approach

        unordered_set<int> ban(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;   // skip banned numbers

            if (sum + i > maxSum) break;  // stop if sum exceeds maxSum

            sum += i;
            count++;
        }
        
        return count;
    }
};
