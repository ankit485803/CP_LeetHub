class Solution {
public:
    typedef long long ll;

    vector<ll> getDistances(vector<int>& arr) {  //tc=O(n)=sc
        int n = arr.size();
        vector<ll> ans(n, 0);

        unordered_map<int, ll> idxSum;
        unordered_map<int, ll> idxCount;

        // Left → Right
        for (int i = 0; i < n; i++) {
            ll freq = idxCount[arr[i]];
            ll sum = idxSum[arr[i]];

            ans[i] += freq * i - sum;

            idxCount[arr[i]]++;
            idxSum[arr[i]] += i;
        }

        // Clear maps
        idxSum.clear();
        idxCount.clear();

        // Right → Left
        for (int i = n - 1; i >= 0; i--) {
            ll freq = idxCount[arr[i]];
            ll sum = idxSum[arr[i]];

            ans[i] += sum - freq * i;

            idxCount[arr[i]]++;
            idxSum[arr[i]] += i;
        }

        return ans;
    }
};